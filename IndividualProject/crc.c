#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t crc32(unsigned char *input) // these are the arguments required to execute the program
{
	uint32_t crc=0xFFFFFFFF; // 32bit 1's, used for division and comparison
	int i;


	while (input[i] != 0) // 0 represents the end of the cycle
	
	{
		char byte = input[i];
		for(size_t j=0; j <= 7 ; j++) {
			crc = byte ^ crc;
			uint32_t b = crc & 1; // checking 0's of the first bits, so the result of this operation is either 0 or 1
				crc = crc >> 1;
			if(b) crc = crc ^ 0xEDB88320;  // division process
				byte = byte >>  1; // moving to the next round of division
		}
	i++;
	}
	return ~crc;
}



int main()
{
	
	unsigned char data[32];
	printf("Enter the data \n");
	
	scanf("%s", &data);
	printf("Your data is: \"%s\"\n", data);
	unsigned int result = crc32(data);
	printf("Your hash is: \"%x\"\n", result);


}
