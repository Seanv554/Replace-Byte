/*
 ============================================================================
 Name        		: Sean Vail
 Class       		: CS47
 Section Number 	: 03
 SJSU ID		 	: 007879469
 Assignment         : 2 
 HW problem Number	: 2
 Description 		: Returns an unsigned value in which byte i of argument x
 	 	 	 	 	  has been replaced by byte b
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
Uses shifts to substract a specific byte from x and then add in b to replace it.
Parameters: 
    x = 4 byte Unsigned Integer
    i = Index of byte to replace (i <= 3)
    b = What to replace byte with
Returns:
    Unsigned int with replaced byte
*/
unsigned replace_byte(unsigned x, int i, unsigned char b) {
    if(i > 3){
        printf("Error: Out of bounds [i]\n");
        return x;
    }
    int shift = (24-(8*i)); /**determines the necessary number of times to 
                            shift in order to isolate the old byte*/
    unsigned x1 = (x << shift)>>(shift+(i*8))<<(i*8);   /**isolates the byte 
                                                        to get rid of*/
    unsigned x2 = b << (i*8);   /**shifts the new byte in the appropriate 
                                position to replace the old byte*/
    x = (x - x1) + x2;  /**empties the old byte and replaces it with the new*/
    return x;
}


int main(int argc, char *argv[]) {
	unsigned int n = strtoul(argv[1], NULL, 16);  
	n=replace_byte(n, atoi(argv[2]), strtoul(argv[3], NULL, 16));
	printf("output:0x%08x\n", n);
	return 0;
}


