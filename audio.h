#ifndef AUDIO_H_
#define AUDIO_H_

#include <stddef.h>
#include <stdint.h>

#ifndef SAMPLING_RATE
#define SAMPLING_RATE 48000
#endif

#define MAX_VOLUME 0x7fffffff

typedef struct audio {
    volatile uint32_t control;
    volatile uint32_t fifospace;
    volatile int32_t left;
    volatile int32_t right;
} audio_t;

typedef struct fifospace {
    int write_available_left;
    int write_available_right;
    int read_available_left;
    int read_available_right;
} fifospace_t;

static inline fifospace_t read_fifospace(audio_t *audio) {
    fifospace_t space;
    uint32_t fifospace = audio->fifospace;

    space.write_available_left = (fifospace >> 24) & 0xFF;
    space.write_available_right = (fifospace >> 16) & 0xFF;
    space.read_available_left = (fifospace >> 8) & 0xFF;
    space.read_available_right = fifospace & 0xFF;

    return space;
}

typedef struct note {
    char name[4];
    int time;
    int duration;
    int duty;
    int volume;
} note_t;

typedef struct channel {
    int volume;
    int frequency;
    int duty;
    int current_note_time;
    int current_note_duration;
} channel_t;

audio_t *open_audio();
void close_audio();

#endif /*AUDIO_H_*/
