// Name: Kevin Lin SBUID: 116145453

#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;
   /* The float is 32 bit */
   // Using masking shift the position like how the DOB during recitation was like
   // Sign_bit is 00000000 (+) or 000000001 (-)
   // Move the first sign bit to position 31 of the float.'
   // Casting to unsigned int, removes overflow errors
   f |= ((unsigned int)(sign_bit & 1) << 31);  

   //Move the exponent to position 23, its 8 bit will cover 23 to 30.
   // Exponent may overflow with test case 0x89 or 137,
   //     mask the 8 bits and ensure that it doesn't overflow by casting.
   //    need to apply the cast right away otherwise saving it will overflow again.
   f |= ((unsigned int)exponent & 0xff) << 23;

   // No need to move the fraction. Combine it with |
   f |= fraction;
   return *(float *)&f;
}

// Function copied from lecture 6 slide 10
// For debugging purpose
// Function to print an integer in binary (up to 32 bits)
// void printBinarys(unsigned int n) {
//    for (int i = 31; i >= 0; i--) {
//       unsigned int mask = 1 << i;
//       printf("%d", (n & mask) ? 1 : 0);
//       if (i % 4 == 0) printf(" "); // space every 4 bits
//    }
//    printf("\n");
// }
