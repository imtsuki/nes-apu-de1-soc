#ifndef NOTES_H_
#define NOTES_H_

#include "audio.h"

typedef struct note {
    char name[4];
    int time;
    int duration;
    int duty;
    int volume;
} note_t;

extern const note_t SQUARE1_NOTES[];
extern const note_t SQUARE2_NOTES[];
extern const note_t TRIANGLE_NOTES[];
extern const note_t NOISE_NOTES[];

extern const size_t SQUARE1_NOTES_LENGTH;
extern const size_t SQUARE2_NOTES_LENGTH;
extern const size_t TRIANGLE_NOTES_LENGTH;
extern const size_t NOISE_NOTES_LENGTH;

#endif /*NOTES_H_*/
