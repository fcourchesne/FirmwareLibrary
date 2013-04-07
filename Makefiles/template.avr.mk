# This Makefile is based on hid-custom-rq example from V-USB
# Copyright: (c) 2008 by OBJECTIVE DEVELOPMENT Software GmbH (hid-custom-rq sample)
# Copyright: (c) 2012 by Krzysztof Goj (later changes)
# License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)

DEVICE  = atmega328
#F_CPU   = 8000000	# in Hz
PROGRAMMER = usbasp
PROJECT = ProjectName

# see below for fuse values for particular devices
FUSE_L  = 0x9f
FUSE_H  = 0xc9
BAUD_RATE =
# BAUD_RATE = -B500

AVRDUDE = avrdude -c $(PROGRAMMER) -p $(DEVICE) $(BAUD_RATE) # edit this line for your programmer
CFLAGS  = -Iusbdrv -I. -DDEBUG_LEVEL=0
OBJECTS = main.o
#COMPILE = avr-gcc -Wall -Os -DF_CPU=$(F_CPU) $(CFLAGS) -mmcu=$(DEVICE)
COMPILE = avr-gcc -Wall -Os $(CFLAGS) -mmcu=$(DEVICE)

# symbolic targets:
help:
	@echo "This Makefile has no default rule. Use one of the following:"
	@echo "make hex ....... to build ${PROJECT}.hex"
	@echo "make program ... to flash fuses and firmware"
	@echo "make fuse ...... to flash the fuses"
	@echo "make flash ..... to flash the firmware (use this on metaboard)"
	@echo "make clean ..... to delete objects and hex file"

hex: ${PROJECT}.hex

program: flash fuse

# rule for programming fuse bits
fuse:
	@[ "$(FUSE_H)" != "" -a "$(FUSE_L)" != "" ] || \
		{ echo "*** Edit Makefile and choose values for FUSE_L and FUSE_H!"; exit 1; }
	$(AVRDUDE) -U hfuse:w:$(FUSE_H):m -U lfuse:w:$(FUSE_L):m

# rule for uploading firmware:
flash: ${PROJECT}.hex
	$(AVRDUDE) -U flash:w:${PROJECT}.hex:i

# rule for deleting dependent files (those which can be built by Make):
clean:
	rm -f ${PROJECT}.hex main.lst main.obj main.cof main.list main.map ${PROJECT}.eep.hex ${PROJECT}.elf *.o usbdrv/*.o main.s usbdrv/oddebug.s usbdrv/usbdrv.s

# Generic rule for compiling C files:
.c.o:
	$(COMPILE) -c $< -o $@

# Generic rule for assembling Assembler source files:
.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

# Generic rule for compiling C to assembler, used for debugging only.
.c.s:
	$(COMPILE) -S $< -o $@

# file targets:

${PROJECT}.elf: $(OBJECTS)
	$(COMPILE) -o ${PROJECT}.elf $(OBJECTS)

${PROJECT}.hex: ${PROJECT}.elf
	rm -f ${PROJECT}.hex ${PROJECT}.eep.hex
	avr-objcopy -j .text -j .data -O ihex ${PROJECT}.elf ${PROJECT}.hex
	avr-size ${PROJECT}.hex

# debugging targets:

disasm:	${PROJECT}.elf
	avr-objdump -d ${PROJECT}.elf

cpp:
	$(COMPILE) -E main.c
