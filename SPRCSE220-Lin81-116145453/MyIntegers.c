// Name: Kevin Lin SBUID: 116145453

#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */
    // 1. validate source and target, they have to be '2' or 'S'
    // If src is 2 or S, then its false, if target is 2 or S, then its false, false or false is false
    if(!(source_repr == '2' || source_repr == 'S') || !(target_repr == '2' || target_repr == 'S')) {
        printf("error\n");
        return;
    }
    //Max value repr, cannot convert

    if(source_repr == '2') {
        if(target_repr != '2') {
            // Max negative value in twos complement.
            if(repr == 0x80000000) {
                printf("undefined\n");
                return;
            }
        // This is for '2' repr to 'S' repr
            //If negative
            if((repr >> 31) & 1) {
                // XOR with mask all 1's result in inverting all bits
                // Add 1 to the result
                repr = (repr ^ 0x7fffffff) + 1;
            }
        }
    } else {
        // Src is 'S', target is '2'
        if (target_repr != 'S') {
            // Convert to two's complement
            // Check sign bit, if negative then invert all except sign then + 1
            if((repr >> 31) & 1) {
                // This mask is msb 0, remaining bit 1, invert then add 1 to the result
                repr = (repr ^ 0x7fffffff) + 1;
            }
        }
    }
    // If positive '2' or 'S' then same repr, if same src to same target then same repr
    // The %08 ensures it has 8 character
    // lowercase x results in lowercase hex 
    printf("Hex: %08x\n", repr);
}
