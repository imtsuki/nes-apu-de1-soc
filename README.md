# NES APU Emulation on DE1-SoC

This is a personal proof-of-concept project aiming to emulate the NES APU (Audio Processing Unit) on a DE1-SoC FPGA board. The project currently supports the emulation of four channels: Square 1, Square 2, Triangle, and Noise.

## Compilation

To compile this project, simply run:

```bash
make
```

The sampling rate can be adjusted by passing the `SAMPLING_RATE` parameter to the Makefile. DE1-SoC supports three sampling rates: 8000, 32000, and 48000 Hz.

```bash
make SAMPLING_RATE=48000
```

## Music Note Sequence

C source files defining the music note sequence for each channel should be placed in a subfolder. These files should include the following 8 variable definitions as required in notes.h:

```c
extern const note_t SQUARE1_NOTES[];
extern const note_t SQUARE2_NOTES[];
extern const note_t TRIANGLE_NOTES[];
extern const note_t NOISE_NOTES[];

extern const size_t SQUARE1_NOTES_LENGTH;
extern const size_t SQUARE2_NOTES_LENGTH;
extern const size_t TRIANGLE_NOTES_LENGTH;
extern const size_t NOISE_NOTES_LENGTH;
```

Pass the `NOTES_DIR` parameter to the Makefile to specify the source files to be compiled.

```bash
make NOTES_DIR=zelda
```

## Helper Program

A helper program is provided in the `generate/` subfolder to facilitate the creation of source files for the music note sequences. This program accepts input in the **FamiStudio Text** format.

To obtain this input format:

- Open the `.NSF` file using [FamiStudio](https://github.com/BleuBleu/FamiStudio).
- Export the music in **FamiStudio Text** format.

The helper program generates four source files: `square1.c`, `square2.c`, `triangle.c`, and `noise.c`.

## Disclaimer

All music source files included in this project are properties of Nintendo and are provided for example purposes only.
