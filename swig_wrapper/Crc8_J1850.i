/* Crc8_J1850.i */
%module Crc8_J1850

// --- INPUTS ---
// Typemap 1: Handles single uint8 arguments
%typemap(in) uint8 {
  if (!PyLong_Check($input)) {
    PyErr_SetString(PyExc_TypeError, "Expected an integer.");
    return NULL;
  }
  unsigned long val = PyLong_AsUnsignedLong($input);
  if (val > 0xFF) {
    PyErr_SetString(PyExc_ValueError, "Value out of range for uint8 (0-255).");
    return NULL;
  }
  $1 = (uint8)val;
}

// Typemap 2: Handles the (data, len) pair
%typemap(in) (const uint8* data, unsigned int len) {
  if (!PyBytes_Check($input)) {
    PyErr_SetString(PyExc_TypeError, "Expected a bytes object.");
    return NULL;
  }
  $1 = (uint8*) PyBytes_AsString($input);
  $2 = PyBytes_Size($input);
}

// --- OUTPUTS ---
%typemap(out) uint8 {
  // Take the C result ($1) and convert it into a Python integer
  $result = PyLong_FromLong($1);
}

%{
#include "../Crc8_J1850.h" 
%}

/* Declarations of functions/variables to wrap. */
uint8 Crc8(const uint8* data, unsigned int len, uint8 startvalue); 
