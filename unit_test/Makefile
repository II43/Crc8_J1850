
CC=gcc.exe
CFLAGS = \
	-I.. \
	-Wfatal-errors

OFLAGS = -DCRC8_USE_TABLE
	
OBJS = \
	CRC_J1850.o \
		
CCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -lgcov --coverage

clean:
	del /Q  *.o *.gcno *.exe

th_Crc8_J1850: th_Crc8_J1850.o Crc8_J1850.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) -o th_Crc8_J1850 th_Crc8_J1850.o Crc8_J1850.o
	
th_Crc8_J1850.o: th_Crc8_J1850.c
	$(CC) $(CFLAGS) $(CCOVFLAGS) -c th_Crc8_J1850.c
	
Crc8_J1850.o: ..\Crc8_J1850.c 
	$(CC) $(CFLAGS) $(CCOVFLAGS) $(OFLAGS) -c ..\Crc8_J1850.c 