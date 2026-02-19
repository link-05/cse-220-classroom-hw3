HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
└── README.txt  


1- write your name and SBU ID in each of the file.

MyBitManipulation.c
---
# ToggleBit edge cases
   # Out of bound
   ToggleBit(0xffffffff, 32) expects -1 as error

   # Max hex, toggle sign bit
   ToggleBit(0xffffffff, 31) expects 0x7fffffff

   # Toggle negative values
   ToggleBit(-5, 0) expects -6 since its twos complement
        11111011 is -5 in 2's complement while 11111010 is -6 in 2's complement

   # Toggle sign bit
   ToggleBit(-1, 31) expects 0x7fffffff
---
# GetMSB edge cases
    # MSB at LSB
    GetMSB(1) expects 0
    
    # Max 32 bit integer
    GetMSB(0xffffffff) expects 31

    # Alternating 1 and 0
    GetMSB(0xcccccccc) expects 31

    # All except leftmost bit is 1
    GetMSB(0x7fffffff), 30