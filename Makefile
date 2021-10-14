# File:   Makefile
# Author: J. ZHU
# Date:   12 OCT 2021
# Descr:  Makefile for test file

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


.PHONY: test
test: test.out
	$(OBJCOPY) -O ihex test.out test.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash test.hex; dfu-programmer atmega32u2 start

test.out: test.o pio.o system.o timer.o display.o ledmat.o font.o pacer.o tinygl.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@

.PHONY: maze
maze: maze.out
	$(OBJCOPY) -O ihex maze.out maze.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash make.hex; dfu-programmer atmega32u2 start

maze.out: maze.o pio.o system.o timer.o pacer.o ledmat.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Compile: create object files from C source files.
game.o: game.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

test.o: test.c ../../drivers/avr/system.h ../../drivers/display.h ../../fonts/font5x7_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

playermove.o: playermove.c ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

maze.o: maze.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../utils/pacer.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@


# Link: create ELF output file from object files.
game.out: game.o pio.o system.o timer.o display.o ledmat.o font.o pacer.o tinygl.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@



# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start
