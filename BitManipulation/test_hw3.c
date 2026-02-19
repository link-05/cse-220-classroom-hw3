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
   cr_assert_eq(ToggleBit(0xffffffff, 32), -1);
   cr_assert_eq(ToggleBit(0xffffffff, 31), 0x7fffffff);
   cr_assert_eq(ToggleBit(-5, 0), -6);
   cr_assert_eq(ToggleBit(-1, 31), 0x7fffffff);
}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);

   //Test Cases, explanation and type is in README.MD
   cr_assert_eq(GetMSB(1), 0);
   cr_assert_eq(GetMSB(0xffffffff), 31);
   cr_assert_eq(GetMSB(0xcccccccc), 31);
   cr_assert_eq(GetMSB(0x7fffffff), 30);

}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);
}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
}

Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);
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


