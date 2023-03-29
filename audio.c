#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#include "address_map.h"
#include "audio.h"

int memfd = -1;
void *LW_BRIDGE = NULL;

audio_t *open_audio() {
    if (memfd == -1) {
        memfd = open("/dev/mem", (O_RDWR | O_SYNC));
        if (memfd == -1) {
            fprintf(stderr, "ERROR: could not open \"/dev/mem\"...\n");
            return NULL;
        }
    }

    if (!LW_BRIDGE) {
        LW_BRIDGE = mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE),
                         MAP_SHARED, memfd, LW_BRIDGE_BASE);
        if (LW_BRIDGE == MAP_FAILED) {
            LW_BRIDGE = NULL;
            fprintf(stderr,
                    "ERROR: could not map \"/dev/mem\" to user space...\n");
            close(memfd);
            return NULL;
        }
    }

    audio_t *audio = (audio_t *)(LW_BRIDGE + AUDIO_BASE);
    return audio;
}

void close_audio() {
    if (LW_BRIDGE) {
        if (munmap(LW_BRIDGE, LW_BRIDGE_SPAN) != 0) {
            fprintf(stderr, "ERROR: munmap() failed...\n");
        }
        LW_BRIDGE = NULL;
    }

    if (memfd != -1) {
        close(memfd);
    }
}
