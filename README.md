# Crc8_J1850
CRC8 algorithm according to J1850
For more explanations please refer to:
	https://www.autosar.org/fileadmin/user_upload/standards/classic/4-3/AUTOSAR_SWS_CRCLibrary.pdf
	http://www.sunshine2k.de/coding/javascript/crc/crc_js.html 

To run the unit testing test harness:
1. Go to "unit_testing" folder
2. Run: th_Crc8_J1850 > results_th_Crc8_J1850.txt
3. To append the coverage report th_Crc8_J1850.c.gcov and Crc8_J1850.c.gcov to test results: 
   gcov th_Crc8_J1850.gcda Crc8_J1850.gcda >> results_th_Crc8_J1850.txt

To re-build test harness in Windows:
1. Install MinGW compiler
2. Add it to the Windows "PATH" environement variable
3. Restart computer
4. Run: mingw32-make th_Crc8_J1850 
