# Makefile for SWIG Python module

# Use python3-config to get correct flags automatically
PYTHON_INCLUDE = $(shell python3-config --includes)
PYTHON_VERSION = $(shell python3 -c "import sys; print(f'{sys.version_info.major}.{sys.version_info.minor}')")

# Compiler and flags
CC = gcc
CFLAGS = -fPIC -O2 $(PYTHON_INCLUDE)
LDFLAGS = -shared

# Module name
TARGET = Crc8_J1850

# Default target
all: _$(TARGET).so th_$(TARGET).py

# Rule to link the final shared library for Python
_$(TARGET).so: $(TARGET)_wrap.o $(TARGET).o
	$(CC) $(LDFLAGS) $^ -o $@

# Rule to compile the SWIG-generated wrapper code
$(TARGET)_wrap.o: $(TARGET)_wrap.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile our original C code from the parent directory
$(TARGET).o: ../$(TARGET).c ../$(TARGET).h
	$(CC) $(CFLAGS) -c ../$(TARGET).c -o $(TARGET).o

# Rule to generate the wrapper from the interface file
$(TARGET)_wrap.c: $(TARGET).i
	swig -python $(TARGET).i

# Rule to generate the Python test script
# Rule to generate the Python test script from the template
th_$(TARGET).py: th_template.py
	@echo "Generating test script $@ from template..."
	@sed 's/%%MODULE_NAME%%/$(TARGET)/g' $< > $@

# Clean up generated files
clean:
	rm -f *.o *.so *_wrap.c
	rm -f $(TARGET).py 
	rm -f th_$(TARGET).py 
	rm -rf __pycache__