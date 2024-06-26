# File:   Makefile
# Author: M. P. Hayes, UCECE
# Date:   12 Sep 2010
# Descr:  Makefile for lab2-ex5

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../../drivers/avr -I../../../utils -I../../../drivers
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: maze.out


# Compile: create object files from C source files.
maze.o: maze.c ../../../drivers/avr/pio.h ../../../drivers/avr/system.h ../../../utils/pacer.h ../../../drivers/ledmat.h ../../../utils/tinygl.h ../../../drivers/display.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../../drivers/avr/pio.c ../../../drivers/avr/pio.h ../../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../../drivers/avr/system.c ../../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../../drivers/avr/timer.c ../../../drivers/avr/system.h ../../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../../utils/pacer.c ../../../drivers/avr/system.h ../../../drivers/avr/timer.h ../../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../../drivers/ledmat.c ../../../drivers/avr/pio.h ../../../drivers/avr/system.h ../../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../../utils/tinygl.c ../../../drivers/avr/system.h ../../../drivers/display.h ../../../utils/font.h ../../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../../utils/font.c ../../../drivers/avr/system.h ../../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../../drivers/display.c ../../../drivers/avr/system.h ../../../drivers/display.h ../../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

# Link: create ELF output file from object files.
maze.out: maze.o pio.o system.o timer.o pacer.o ledmat.o tinygl.o display.o font.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: maze.out
	$(OBJCOPY) -O ihex maze.out maze.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash maze.hex; dfu-programmer atmega32u2 start


