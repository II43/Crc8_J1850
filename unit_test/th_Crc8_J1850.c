/* Test harness to test Crc8_J1850 checksum calculation */

#include <stdio.h>
#include <assert.h>

#include "Crc8_J1850.h"

int main(void)
{
	printf("Start of testing\n");
	printf("----------------\n\n");
	
	/*
	   Test for Crc8 function
	   Based on https://www.autosar.org/fileadmin/user_upload/standards/classic/4-3/AUTOSAR_SWS_CRCLibrary.pdf
	*/
	printf("Crc8\n");
	printf("----------------\n\n");
	uint8 i = 1, crc;
	
    const uint8 testdata_1[] = {0x00,0x00,0x00,0x00};
	const uint8 testdata_2[] = {0xF2,0x01,0x83};
	const uint8 testdata_3[] = {0x0F,0xAA,0x00,0x55};
	const uint8 testdata_4[] = {0x00,0xFF,0x55,0x11};
	const uint8 testdata_5[] = {0x33,0x22,0x55,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};
	const uint8 testdata_6[] = {0x92,0x6B,0x55};
	const uint8 testdata_7[] = {0xFF,0xFF,0xFF,0xFF};
	
	/* Test 1 */
	crc = Crc8(testdata_1, 4, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0x59);
	
	/* Test 2 */
	crc = Crc8(testdata_2, 3, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0x37);
	
	/* Test 3 */
	crc = Crc8(testdata_3, 4, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0x79);
	
	/* Test 4 */
	crc = Crc8(testdata_4, 4, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0xB8);
	
	/* Test 5 */
	crc = Crc8(testdata_5, 9, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0xCB);
	
	/* Test 6 */
	crc = Crc8(testdata_6, 3, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0x8C);
	
	/* Test 7 */
	crc = Crc8(testdata_7, 4, 0xFF);
	crc ^= 0xFF;
	printf("CRC check %d\n",i++);
	printf("CRC = %d (0x%02X)\n\n", crc, crc);
	
	assert (crc == 0x74);
	
	printf("Done\n");
	return 0;
}