#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <linux/input.h>

#include "audio.h"
#include "notes.h"

// Calculate the frequency of a given note
double note_frequency(int semitones_from_a4) {
    return 880.0 * pow(2, (double)semitones_from_a4 / 12.0);
}

// Convert note names to their semitone offset from A4
int note_offset_from_a4(const char *note_name) {
    int semitones_from_a4;

    switch (note_name[0]) {
    case 'C':
        semitones_from_a4 = -9;
        break;
    case 'D':
        semitones_from_a4 = -7;
        break;
    case 'E':
        semitones_from_a4 = -5;
        break;
    case 'F':
        semitones_from_a4 = -4;
        break;
    case 'G':
        semitones_from_a4 = -2;
        break;
    case 'A':
        semitones_from_a4 = 0;
        break;
    case 'B':
        semitones_from_a4 = 2;
        break;
    default:
        return -1;
    }

    int octave_idx = 1;
    if (note_name[1] == '#' || note_name[1] == 'b') {
        if (note_name[1] == '#') {
            semitones_from_a4 += 1;
        } else {
            semitones_from_a4 -= 1;
        }
        octave_idx = 2;
    }

    int octave = note_name[octave_idx] - '0';
    semitones_from_a4 += 12 * (octave - 4);

    return semitones_from_a4;
}

channel_t CHANNEL_SQUARE1, CHANNEL_SQUARE2, CHANNEL_TRIANGLE, CHANNEL_NOISE;

channel_t *CHANNELS[] = {&CHANNEL_SQUARE1, &CHANNEL_SQUARE2, &CHANNEL_TRIANGLE,
                         &CHANNEL_NOISE};

const char *CHANNEL_NAMES[] = {"Square 1", "Square 2", "Triangle", "Noise"};

const double duties[] = {0.125, 0.25, 0.5, 0.75};
const int duty_fourier_cycles[] = {8, 4, 2, 4};

#define COEFFICIENT_TABLE_LENGTH 1024

/* Pre-calculated coefficients for the Fourier series of the square wave */
double square_coefficients[4][COEFFICIENT_TABLE_LENGTH];
/* Pre-calculated coefficients for the Fourier series of the triangle wave */
double triangle_coefficients[COEFFICIENT_TABLE_LENGTH];

void calculate_square_coefficients() {
    for (int duty_idx = 0; duty_idx < 4; duty_idx++) {
        double duty = duties[duty_idx];
        for (int n = 1; n < COEFFICIENT_TABLE_LENGTH; n++) {
            square_coefficients[duty_idx][n] =
                2 * sin(n * M_PI * duty) / (n * M_PI);
        }
    }
}

void calculate_triangle_coefficients() {
    for (int n = 1; n < COEFFICIENT_TABLE_LENGTH; n++) {
        triangle_coefficients[n] =
            (1.0 - pow(-1, n)) / (pow(n, 2.0) * pow(M_PI, 2.0));
    }
}

void play(audio_t *audio) {
    int indices[] = {0, 0, 0, 0};
    int nth_sample = 0;

    const note_t *all_notes[] = {SQUARE1_NOTES, SQUARE2_NOTES, TRIANGLE_NOTES,
                                 NOISE_NOTES};

    const int notes_lengths[] = {SQUARE1_NOTES_LENGTH, SQUARE2_NOTES_LENGTH,
                                 TRIANGLE_NOTES_LENGTH, NOISE_NOTES_LENGTH};

    calculate_square_coefficients();
    calculate_triangle_coefficients();

    while (1) {
        while (read_fifospace(audio).write_available_left < 1)
            ;

        int ended = 1;

        // For each channel, if the current note has ended, set the frequency to
        // 0
        for (int i = 0; i < sizeof(CHANNELS) / sizeof(channel_t *); i++) {
            if (nth_sample == SAMPLING_RATE * 4 *
                                  (CHANNELS[i]->current_note_time +
                                   CHANNELS[i]->current_note_duration) /
                                  256) {
                CHANNELS[i]->frequency = 0;
            }

            ended &= indices[i] >= notes_lengths[i];
        }

        if (ended) {
            break;
        }

        // For each channel, process the next note if it's time
        for (int i = 0; i < sizeof(CHANNELS) / sizeof(channel_t *); i++) {
            channel_t *channel = CHANNELS[i];

            const note_t *notes = all_notes[i];

            if (indices[i] < notes_lengths[i] &&
                nth_sample ==
                    SAMPLING_RATE * 4 * notes[indices[i]].time / 256) {
                // process this note
                if (notes[indices[i]].volume != -1) {
                    channel->volume = notes[indices[i]].volume;
                }

                if (notes[indices[i]].duty != -1) {
                    channel->duty = notes[indices[i]].duty;
                }

                if (strlen(notes[indices[i]].name) > 0) {
                    int semitones_from_a4 =
                        note_offset_from_a4(notes[indices[i]].name);
                    int frequency = note_frequency(semitones_from_a4);
                    printf("channel: %s, note: %s, duty: %d\n",
                           CHANNEL_NAMES[i], notes[indices[i]].name,
                           notes[indices[i]].duty);
                    channel->frequency = frequency;
                    channel->current_note_time = notes[indices[i]].time;
                    channel->current_note_duration = notes[indices[i]].duration;
                }

                indices[i] += 1;
            }
        }

        double final_signal = 0;

        // Square 1 and Square 2 Channels
        for (int i = 0; i < 2; i++) {
            channel_t *channel = CHANNELS[i];

            if (channel->frequency == 0)
                continue;

            int volume = MAX_VOLUME / 64 * channel->volume;

            double signal = 0;

            double sin_time =
                sin(2 * M_PI * channel->frequency * nth_sample / SAMPLING_RATE);
            double cos_time =
                cos(2 * M_PI * channel->frequency * nth_sample / SAMPLING_RATE);
            double temp;
            double sin_n = sin_time, cos_n = cos_time;
            for (int n = 1; channel->frequency * n < SAMPLING_RATE / 2; n++,
                     temp = sin_n * cos_time + cos_n * sin_time,
                     cos_n = cos_n * cos_time - sin_n * sin_time,
                     sin_n = temp) {
                if (n % duty_fourier_cycles[channel->duty] == 0) {
                    continue;
                }

                double coefficient_n = square_coefficients[channel->duty][n];

                // signal += cos(2 * M_PI * channel->frequency * n * nth_sample
                // / SAMPLING_RATE) * coefficient_n;
                signal += cos_n * coefficient_n;
            }

            signal *= volume;

            final_signal += signal;
        }

        // Triangle Channel
        do {

            if (CHANNEL_TRIANGLE.frequency == 0)
                break;

            // Triangle channel's volume is fixed
            int volume = MAX_VOLUME / 64 * 16;

            double signal = 0;

            // Triangle channel's pitch is lower
            int frequency = CHANNEL_TRIANGLE.frequency / 2;

            // generate triangle wave
            double sin_time =
                sin(2 * M_PI * frequency * nth_sample / SAMPLING_RATE);
            double cos_time =
                cos(2 * M_PI * frequency * nth_sample / SAMPLING_RATE);
            double temp;
            double sin_n = sin_time, cos_n = cos_time;

            for (int n = 1; frequency * n < SAMPLING_RATE / 2; n++,
                     temp = sin_n * cos_time + cos_n * sin_time,
                     cos_n = cos_n * cos_time - sin_n * sin_time,
                     sin_n = temp) {
                if (n % 2 == 0) {
                    continue;
                }
                double coefficient_n = triangle_coefficients[n];

                // signal += cos(2 * M_PI * frequency * n * nth_sample /
                // SAMPLING_RATE) * coefficient_n;
                signal += cos_n * coefficient_n;
            }

            signal *= volume;

            final_signal += signal;

        } while (0);

        // Noise Channel
        do {
            if (CHANNEL_NOISE.frequency == 0)
                break;

            int volume = MAX_VOLUME / 64 * 16;

            // generate noise wave
            final_signal += rand() % volume;

        } while (0);

        audio->left = final_signal;
        audio->right = final_signal;

        nth_sample += 1;
    }
}

int main() {
    audio_t *audio = open_audio();

    if (!audio) {
        fprintf(stderr, "ERROR: could not open audio device...\n");
        return 1;
    }

    play(audio);

    close_audio();

    return 0;
}
