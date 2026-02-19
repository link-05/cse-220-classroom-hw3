#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
	cr_assert_eq(ToggleBit(9, 0), 8);
	cr_assert_eq(ToggleBit(9, 3), 1);

	//Test Cases, explanation and type is in README.MD
	 
	// cr_assert_eq(ToggleBit(0xffffffff, 32), -1);
	// cr_assert_eq(ToggleBit(0xffffffff, 31), 0x7fffffff);
	// cr_assert_eq(ToggleBit(-5, 0), -6);
	// cr_assert_eq(ToggleBit(-1, 31), 0x7fffffff);
}

Test(GetMSB, examples) {
	cr_assert_eq(GetMSB(18), 4);
	cr_assert_eq(GetMSB(0), -1);

	//Test Cases, explanation and type is in README.MD
	 
	// cr_assert_eq(GetMSB(1), 0);
	// cr_assert_eq(GetMSB(0xffffffff), 31);
	// cr_assert_eq(GetMSB(0xcccccccc), 31);
	// cr_assert_eq(GetMSB(0x7fffffff), 30);

}

Test(ClearBitRange, examples) {
	cr_assert_eq(ClearBitRange(73, 1, 3), 65);
	//Test Cases, explanation and type is in README.MD
	 
	// cr_assert_eq(ClearBitRange(0xffffffff, 0, 15), 0xffff0000);
	// cr_assert_eq(ClearBitRange(0xffffffff, 16, 31), 0x0000ffff);
	// cr_assert_eq(ClearBitRange(0xffffffff, 31, 1), 0xffffffff);

}

Test(RotateLeft, examples) {
	cr_assert_eq(RotateLeft(5, 1), 10);
	cr_assert_eq(RotateLeft(5, 2), 20);
	//Test Cases, explanation and type is in README.MD
	 
	// cr_assert_eq(RotateLeft(5, 32), 5);
	// cr_assert_eq(RotateLeft(0xcccccccc, 16), 0xcccccccc);
	// cr_assert_eq(RotateLeft(0xffffffff, 0), 0xffffffff);
	// cr_assert_eq(RotateLeft(0x80000000, 1), 1);
	// cr_assert_eq(RotateLeft(0x80000000, 33), 1);
	// cr_assert_eq(RotateLeft(0x80000000, 65), 1);

}

Test(SwapOddEvenBits, examples) {
	cr_assert_eq(SwapOddEvenBits(23), 43);
	//Test Cases, explanation and type is in README.MD

	// cr_assert_eq(SwapOddEvenBits(0xaaaaaaaa), 0x55555555);
	// cr_assert_eq(SwapOddEvenBits(0x55555555), 0xaaaaaaaa);
	// cr_assert_eq(SwapOddEvenBits(0x0000cccc), 0x0000cccc);

}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
	float f = construct_float_sf(0x00, 0x7F, 0x200000);
	cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_examples) {
	float f = construct_float_sf(0x01, 0x7F, 0x200000);
	cr_assert_float_eq(f, -1.25, 0.00001);
}

// Test cases

Test(ConstructFloat, pos_zero) {
	float f = construct_float_sf(0x00, 0x00, 0x000000);
	cr_assert_float_eq(f, 0.0, 0.00001);
}

Test(ConstructFloat, neg_zero) {
	float f = construct_float_sf(0x01, 0x00, 0x000000);
	cr_assert_float_eq(f, 0.0, 0.00001);
}

Test(ConstructFloat, pos_one) {
	float f = construct_float_sf(0x00, 0x7F, 0x000000);
    cr_assert_float_eq(f, 1.0, 0.00001);
}

Test(ConstructFloat, neg_one) {
	float f = construct_float_sf(0x01, 0x7F, 0x000000);
    cr_assert_float_eq(f, -1.0, 0.00001);
}

Test(ConstructFloat, pos_first_position_fraction_bin) {
	float f = construct_float_sf(0x00, 0x7E, 0x000000);
    cr_assert_float_eq(f, 0.5, 0.00001);
}

Test(ConstructFloat, neg_first_position_fraction_bin) {
	float f = construct_float_sf(0x01, 0x7E, 0x000000);
    cr_assert_float_eq(f, -0.5, 0.00001);
}

Test(ConstructFloat, pos_random_fraction_only) {
	float f = construct_float_sf(0x00, 0x7B, 0x7CB924);
	cr_assert_float_eq(f, 0.1234, 0.00001);
}

Test(ConstructFloat, neg_random_fraction_only) {
	float f = construct_float_sf(0x01, 0x7B, 0x7CB924);
	cr_assert_float_eq(f, -0.1234, 0.00001);
}

Test(ConstructFloat, pos_multi_decimal_only) {
	float f = construct_float_sf(0x00, 0x89, 0x1A4000);
	cr_assert_float_eq(f, 1234.0, 0.00001);
}

Test(ConstructFloat, neg_multi_decimal_only) {
	float f = construct_float_sf(0x01, 0x89, 0x1A4000);
	cr_assert_float_eq(f, -1234.0, 0.00001);
}



/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
	repr_convert('2', '2', 0x59f2ca50);
	repr_convert('S', '2', 0x80000000);
	//Given test cases
	// repr_convert('S', '2', 0x80000001);
	// repr_convert('F', '2', 0x80000000);
	// repr_convert('2', 'S', 0x80000000);


}


