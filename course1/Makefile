#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

TARGET = c1m2

# General compiler and linker flags for both platforms
CFLAGS = -Wall -Werror -g -O0 -std=c99
DEPFLAGS := -M
LDFLAGS := -Wl,-Map=$(TARGET).map

CPPFLAGs := -D$(PLATFORM)


# Compiler Flags and Defines
	ifeq ($(PLATFORM),MSP432)
		# Architectures Specific Flags
		LINKER_FILE := ../msp432p401r.lds
		CPU := cortex-m4
		ARCH := thumb
		MARCH := armv7e-m 
		SPECS := nosys.specs
		FPU := -mfloat-abi=hard -mfpu=fpv4-sp-d16

		CC := /usr/bin/arm-none-eabi-gcc
		LD := /usr/bin/arm-none-eabi-ld
		SIZE := /usr/bin/arm-none-eabi-size
		OBJDUMP:= /usr/bin/arm-none-eabi-objdump
		LDFLAGS := $(LDFLAGS) -T $(LINKER_FILE)
		CFLAGS := $(CFLAGS) -mcpu=$(CPU) -march=$(MARCH) -m$(ARCH)  --specs=$(SPECS) $(FPU)
		SOURCES:= $(SOURCES) interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c
		INCLUDES := $(INCLUDES) -I../include/msp432/ -I../include/CMSIS/

	else
		CC := /usr/bin/gcc
		LD := /usr/bin/ld
		SIZE := /usr/bin/size
		OBJDUMP := /usr/bin/objdump
	endif

OBJS = $(SOURCES:.c=.o)

#%.i : %.c
#	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

#%.o : %.i
#	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

main.i : main.c main.d
	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

main.o : main.i main.d
	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

memory.i : memory.c memory.d
	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

memory.o : memory.i memory.d
	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

startup_msp432p401r_gcc.i : startup_msp432p401r_gcc.c startup_msp432p401r_gcc.d
	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

startup_msp432p401r_gcc.o : startup_msp432p401r_gcc.i startup_msp432p401r_gcc.d
	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

interrupts_msp432p401r_gcc.i : interrupts_msp432p401r_gcc.c interrupts_msp432p401r_gcc.d
	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

interrupts_msp432p401r_gcc.o : interrupts_msp432p401r_gcc.i interrupts_msp432p401r_gcc.d
	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

system_msp432p401r.i : system_msp432p401r.c system_msp432p401r.d
	$(CC) -E $(INCLUDES) $(CPPFLAGs) $< -o $@

system_msp432p401r.o : system_msp432p401r.i system_msp432p401r.d
	$(CC) -c $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< -o $@

%.asm : %.o
	$(OBJDUMP) -S $< > $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -S $< > $@

%.d : %.c
	$(CC) $(DEPFLAGS) $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $< > $@

$(TARGET).out : $(OBJS)
	$(CC)  $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(OBJS)
	$(SIZE) $(TARGET).out 

.PHONY: compile-all
compile-all: $(OBJS)
	
.PHONY: build
build: $(TARGET).out
	
.PHONY: clean
clean:
	rm -rf *.i *.o *.asm *.map *.out *.d
