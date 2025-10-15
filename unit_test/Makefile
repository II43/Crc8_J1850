# Set the C compiler
CC = gcc

# Module name
TARGET = Crc8_J1850
SRC_FILE = ../$(TARGET).c

# --- Platform-specific configuration ---
ifeq ($(OS),Windows_NT)
	# Windows settings
	RM = del /Q
	EXE_EXT = .exe
	SRC_FILE := $(subst /,\,$(SRC_FILE))
else
	# Linux/Unix settings
	RM = rm -f
	EXE_EXT =
endif

# --- Compiler and Linker Flags ---
CFLAGS = \
    -I.. \
    -Wfatal-errors

OFLAGS = -DCRC8_USE_TABLE

CCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -lgcov --coverage

# --- Building ---
OBJS = \
	th_$(TARGET).o \
    Crc8_J1850.o

all: th_$(TARGET)

th_$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LCOVFLAGS) -o $@ $^

th_$(TARGET).o: th_$(TARGET).c
	$(CC) $(CFLAGS) $(CCOVFLAGS) -c $< -o $@

Crc8_J1850.o: $(SRC_FILE)
	$(CC) $(CFLAGS) $(CCOVFLAGS) $(OFLAGS) -c $< -o $@

# --- Cleanup Rule ---
clean:
	$(RM) *.o *.gcno *.gcov *.gcda
	$(RM) th_$(TARGET)$(EXE_EXT)
	$(RM) results_*.txt