// Name: Kevin Lin SBUID: 116145453

// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>

/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   //Handle edge cases, Out of Bound
   if(pos < 0 || pos > 31) {
      printf("Error: Position out of bound");
      return -1;
   }
   // Toggle bits can be done by setting up a mask with 1 located at pos and doing XOR
   // If the value at pos for num's binary rep is a 1, then XOR or ^ makes it to 0
   // Else if value at pos is a 0, then XOR makes it to 1
   return num ^ (1 << pos); // num ^ mask
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   // Given edge case: num == 0 return -1
   if(num == 0) return -1;
   /* for each bit from right to left
       shift the number right by i position and look at bit 1 or rightmost
          since the condition for the if statement can be 0 for false and anything else for true,
         if the value is a 1 then mark that pos as the current msb */
   int msbPos = -1;
   for(int i = 0; i < 32; i++) {
      if((num >> i & 1)) {
         msbPos = i;
      }
   }
   return msbPos;
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   if(start > end) return num;
   /* This function makes a mask from start to end 
        The function can start with a
        clear from 0 to start
        clear from 32 to end
        32 - end - 1 left shift then right shift by the same amount
         the extra 1 is due to balancing 
        start right shift then left shift by the same amount
         00111000
   */
   // binary of all 1's up to 32 bit
   unsigned int mask = 0xffffffff;
   // Goal of this mask is to clear all bit not in range from start to end
   // mask left shift by 32 - end with a -1 for inclusive of end. shift back so position does not change.
   mask = (mask << (32 - end - 1)) >> (32 - end - 1);
   // mask right shift by start and then shift back so position doesn't change. 
   mask = ((mask >> start) << start);
   // apply mask by flipping all 1 and 0's with ~ and mask onto num with &. 
   // Only those not in range can be true.
   return num & ~mask;

   //First attempt for clearing bit one by one.
   // for(int i = start; i <= end; i++) {
   //    //According to lecture slide, number & 1 should be everywhere except for the clear bit pos, which should be 0 
   //    num = num & ~(1 << i); 
   // }
   // printBinary(num);
   // return num;
}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
   /* In order to rotate left, I did both left and right shifts
      Move the bits left so d number of 0 will appear on rightmost side.
      Get the bits that are offsetted by the left rotation by right shift 32 - d,
      Note to self: This is possible because the number does not get changed during this process
      Then combine the two using | to set the bits*/
   return (num << d) | (num >> (32 - d));
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* Given the bitmask 
      0xAAAAAAAA -> mask for even bits
      0x55555555 -> mask for odd bits */
   /* For this function, I would right shift the even bit and left shift the odd bits then combine them
      ex. 10011001, 
      mask odd 00010001 -> left shift ->    00100010, 
      mask even 10001000 -> right shift ->  01000100, 
                                    combine 01100110 
   */
   // return (even bit's of number) right shifted by 1 + (odd bits of number) left shift by 1
   return ((num & 0xAAAAAAAA) >> 1) + ((num & 0x55555555) << 1);
}

// Function copied from lecture 6 slide 10
// For debugging purpose
// Function to print an integer in binary (up to 32 bits)
void printBinary(unsigned int n) {
   for (int i = 31; i >= 0; i--) {
      unsigned int mask = 1 << i;
      printf("%d", (n & mask) ? 1 : 0);
      if (i % 4 == 0) printf(" "); // space every 4 bits
   }
   printf("\n");
}