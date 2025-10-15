# Crc8_J1850
CRC8 algorithm according to J1850
For more explanations please refer to: <br>
	[AUTOSAR Specification of CRC Routines](https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_CRCLibrary.pdf) <br>
	http://www.sunshine2k.de/coding/javascript/crc/crc_js.html <br>

## Python wrapper
This is generated using [SWIG](https://www.swig.org)  development tool.

To generate and test the Python wrapper:
1. Install SWIG development tool
2. Go to "swig_wrapper" sub-folder
3. Run: make all
4. Test the wrapper: python3 th_Crc8_J1850.py<br>
   This is also nice example how to use the wrapper in Python.

## Unit testing
To run the unit testing test harness:
1. Go to "unit_test" sub-folder
2. Run: make all
2. Run: th_Crc8_J1850 > results_th_Crc8_J1850.txt
3. To append the coverage report th_Crc8_J1850.c.gcov and Crc8_J1850.c.gcov to test results: 
   gcov th_Crc8_J1850.gcda Crc8_J1850.gcda >> results_th_Crc8_J1850.txt

To re-build test harness in Windows:
1. Install MinGW compiler
2. Add it to the Windows "PATH" environement variable
3. Restart computer
4. Run: mingw32-make all<br>
   Just to be clear: This shall be run instead of simple 'make all' from above instructions. 
