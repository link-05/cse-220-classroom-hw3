// Name: Kevin Lin SBUID: 116145453
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

// Return the length of the string, not including the null character
//  if pointer is null, return -1
int strgLen(const char *s) {
    // Edge case: null pointer.
    if(s == NULL) {
        return -1;
    }
    int len = 0;
    // While the character is not a null, increment the index/length.
    while(s[len] != '\0') {
        len++;
    }
    return len;
}

// Copy the content from source to destination, where size is size of destination.
void strgCopy(const char *source, char *destination, size_t size) {
    // Edge case: invalid inputs - null pointer or 0 size.
    if(source == NULL || destination == NULL || size == 0) return;
    // destination[i] = *(source + i) <-> destination[i] = source[i]
    size_t i;
    for(i = 0; i < (size - 1); i++) {
        // set the destination pointer location value to the source pointer location value
        destination[i] = source[i];
    }
    // Access the final index that is saved by size - 1, change to '\0'
    destination[i] = '\0';
}


// This function changes the case fo each letter in the string, only if the letter is not next to a digit.
//  The concept of lowercase char = uppercase char + 32 and uppercase char = lowercase char - 32
//  is used to flip the case of a letter.
void strgChangeCase(char *s) {
    // Check if it is a empty or null first (edge case - empty string or nonexistent pointer)
    if(*s == '\0' || s == NULL) {
        return;
    } else {
    // check the first character.
        // Edge case: if the right neighbor of the first number is '\0' it will just be 0 so not in range.
        // If the right neighbor is not a digit then
        if(!(*(s + 1) >= '0' && *(s + 1) <= '9')) {
            // if lowercase then - 32
            if(*s >= 'a' && *s <= 'z') {
                *s = *s - 32;
            } else if(*s >= 'A' && *s <= 'Z') {
                *s = *s + 32;
            }
        }
        // Move pointer to the next char.
        s++;
    }
    // For the rest of character in the string until '\0', flip case if not next to a digit
    while(*s != '\0') {
        // Check the right and left neighbor of current char, ensure they are not digits.
        if(!(*(s + 1) >= '0' && *(s + 1) <= '9') &&
            !(*(s - 1) >= '0' && *(s - 1) <= '9')) {
            // the difference of 'a' - 'A' is 32, 32 can just be added or subtracted to flip the case 
            // if lowercase then - 32
            if(*s >= 'a' && *s <= 'z') {
                *s = *s - 32;
            // if uppercase then + 32
            } else if(*s >= 'A' && *s <= 'Z') {
                *s = *s + 32;
            }
            // Any char non-alphabet then don't do anything
        }
        // Move pointer to the next char.
        s++;
    }
}

// This function compares two string and 
//   if the two string are different, return index where difference occurs
//   If the two string are the same, return -1
//   If a string is invalid input, return -2
int strgDiff(const char *s1, const char *s2) {
    // Check for null pointer 
    if(s1 == NULL || s2 == NULL) return -2;
    // Setup return index
    int index = 0;
    // While we can still compare
    while(s1[index] != '\0' && s2[index] != '\0') {
        // if different return the index where they are different
        if(s1[index] != s2[index]) {
            return index;
        }
        // Move to the next index
        index++;
    }
    // Can't compare anymore, if both are at the end of string return -1 => they are the same
    //    else return index => index where the non terminating string continues
    if(s1[index] == '\0' && s2[index] == '\0') {
        return -1;
    } else {
        return index;
    }
}

// This function interleaves two string into destination
//   where size is the size of destination.
//   logic uses int for interweaving process and
//   if one string ends, just control alternate to follow loop logic
//      size includes the '\0' so size of 4 means string of length 3.
void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    int s1Index = 0; //s1 current copy index
    int s2Index = 0; //s2 current copy index 
    int alternate = 1; // Controls interleave process by alternating true <-> false
    // Declared as size_t to avoid warning
    size_t i; // allows access to i even after the loop ends, used for setting the final terminating char 
    if(size == 0) return;
    // Size - 1 saves the last space for null terminating character
    for(i = 0; i < (size - 1); i++) {
        // edge case: length of s1 + length of s2 < size.
        // If no char to copy before size is reached, then break
        if(s1[s1Index] == '\0' && s2[s2Index] == '\0') {
            break;
        }
        // Alternate means use s1, not alternate means use s2.
        // if s1 is empty and alternate is true then flip alternate
        // if s2 is empty and alternate is false then flip alternate
        if(alternate && s1[s1Index] == '\0') {
            alternate = 0;
        }
        if(!alternate && s2[s2Index] == '\0') {
            alternate = 1;
        }

        // if alternate, if s1 is not empty then set destination at i to s1 at s1Index
        if(alternate) {
            if(s1[s1Index] != '\0') {
                d[i] = s1[s1Index];
                // move to next s1 index
                s1Index++;
            } 
        } else {
            // if s2 not empty, then set destination at i to s2 at s2Index
            if(s2[s2Index] != '\0') {
                d[i] = s2[s2Index];
                // Move to next s2 index
                s2Index++;
            } 
        }
        // Switch from adding s1 char to s2 char and vice versa.
        // if alternate is 1/true then 1 - 1 = false
        // if alternate is 0/false then 1 - 0 = true
        // achieving alternate effect.
        alternate = 1 - alternate;
    }
    // Add string null terminate character.
    d[i] = '\0';
}

// This function reverse a string by only moving the alphabets and not the 
void strgReverseLetters(char *s) {
    // String length function made earlier.
    int length = strgLen(s);
    // Edge case string is empty or pointer is null
    if(length == 0 || length == -1) return;
    // Using two pointer start at rightmost and leftmost
    char *endPtr = &s[length - 1]; //rightmost pointer
    // leftmost pointer is *s
    while(endPtr > s) {
        //While end ptr is not at a letter char, move left with --, unless it reached start pointer
        while(endPtr != s && 
            !((*endPtr >= 'A' && *endPtr <= 'Z') || (*endPtr >= 'a' && *endPtr <= 'z'))) {
            endPtr--;
        }
        //While start ptr is not at a letter char, move right with ++, unless it reached end pointer
        while(s != endPtr &&
             !((*s >= 'A' && *s <= 'Z') ||(*s >= 'a' && *s <= 'z'))) {
            s++;
        }
        if(s == endPtr) {
            return;
        } else {
            //Swap the two character at start and end 
            char temp = *s;
            *s = *endPtr;
            *endPtr = temp;
        }
        // Move s to next char right by 1, endPtr to next char left by 1.
        s++;
        endPtr--;
    }
}
