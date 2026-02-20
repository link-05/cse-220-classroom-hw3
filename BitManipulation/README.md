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

Name: Kevin Lin SBUID:116145453
Note: The structure of my test case is name I give the test case, the actual input, and the expected 

# MyBitManipulation.c
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
---
# ClearBitRange edge cases
    # Clear first half of all 1 bit
    ClearBitRange(0xffffffff, 0, 15) expects 0xffff0000
    
    # Clear second half of all 1 bit
    ClearBitRange(0xffffffff, 16, 31) expects 0x0000ffff

    # Error start > end
    ClearBitRange(0xffffffff, 31, 1) expects 0xffffffff
---
# RotateLeft edge cases
    # full 32 rotation
    RotateLeft(5, 32) expects 5;

    # Rotate half
    RotateLeft(0xcccccccc, 16) expects 0xcccccccc

    # Rotate None
    RotateLeft(0xffffffff, 0) expects 0xffffffff

    # Rotate 1
    RotateLeft(0x80000000, 1) expects 1

    # Rotate more than 32, should be same as 1
    RotateLeft(0x80000000, 33) expects 1

    # 2x Rotate more than 32, should be same as 1
    RotateLeft(0x80000000, 65) expects 1
---
# SwapOddEvenBits edge cases
    # 1010... convert to 0101...
    SwapOddEvenBits(0xaaaaaaaa) expects 0x55555555

    # 0101... convert to 1010...
	SwapOddEvenBits(0x55555555) expects 0xaaaaaaaa

    # half of Even odd both 1 => 0000...1100...
	SwapOddEvenBits(0x0000cccc) expects 0x0000cccc
---
# construct_float_sf test 
    # Positive zero
    construct_float_sf(0x00, 0x00, 0x000000) expects 0.0

    # Negative zero
    construct_float_sf(0x01, 0x00, 0x000000) expects 0.0 

    # Positive one decimal
    construct_float_sf(0x00, 0x7F, 0x000000) expects 1.0

    # Negative one decimal
    construct_float_sf(0x01, 0x7F, 0x000000) expects -1.0

    # Positive first position fraction (0.5)
    construct_float_sf(0x00, 0x7E, 0x000000) expects 0.5

    # Negative first position fraction (-0.5)
    construct_float_sf(0x01, 0x7E, 0x000000) expects -0.5

    # Positive random fraction only (0.1234)
    construct_float_sf(0x00, 0x7B, 0x7CB924) expects 0.1234

    # Negative random fraction only (-0.1234)
    construct_float_sf(0x01, 0x7B, 0x7CB924) expects -0.1234

    # Positive multi-decimal only (1234.0) exponent > 127
    construct_float_sf(0x00, 0x89, 0x1A4000) expects 1234.0

    # Negative multi-decimal only (-1234.0) exponent > 127
    construct_float_sf(0x01, 0x89, 0x1A4000) expects -1234.0
---
# repr_convert Edge Cases
	# Max negative value in 2's complement
    repr_convert('2', 'S', 0x80000001);
    expected output: ffffffff

    # Negative value conversion
    repr_convert('S', '2', 0x80000005);
    expected output: fffffffb

    # Positive Zero (2's to Sign)
    repr_convert('2', 'S', 0x00000000);
    expected output: 00000000

    # Positive Zero self conversion (2's to 2's)
    repr_convert('2', '2', 0x00000000);
    expected output: 00000000

    # Negative Zero (sign to 2's)
    outcome is positive 0 because that is what the hw3 pdf instructs.
    repr_convert('S', '2', 0x80000000);
    expected output: 00000000

    # Negative Zero self conversion (sign to sign)
    repr_convert('S', 'S', 0x80000000);
    expected output: 00000000

    # Max Positive (2's to sign)
    repr_convert('2', 'S', 0x7FFFFFFF);
    expected output: 7fffffff

    # Max Positive (sign to 2's)
    repr_convert('S', '2', 0x7FFFFFFF);
    expected output: 7fffffff

    # Positive 1 (2's to sign)
    repr_convert('2', 'S', 0x00000001);
    expected output: 00000001

    # Positive 1 (sign to 2's)
    repr_convert('S', '2', 0x00000001);
    expected output: 00000001

    # Expected all test case output List
    Hex: ffffffff
    Hex: fffffffb
    Hex: 00000000
    Hex: 00000000
    Hex: 00000000
    Hex: 80000000
    Hex: 7fffffff
    Hex: 7fffffff
    Hex: 00000001
    Hex: 00000001