all: clean nes

NOTES_DIR ?= zelda
NOTES_SRCS = $(wildcard $(NOTES_DIR)/*.c)
SAMPLING_RATE ?= 48000

nes: nes.c audio.c audio.h notes.h $(NOTES_SRCS)
	gcc -Wall -o nes nes.c audio.c $(NOTES_SRCS) -lpthread -lm -O2 -std=gnu99 -D SAMPLING_RATE=$(SAMPLING_RATE)

.PHONY:	clean all

clean:
	rm -f *.o nes
