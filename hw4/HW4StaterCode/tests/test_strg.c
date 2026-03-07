// Name: Kevin Lin SBUID: 116145453

#include <criterion/criterion.h>
#include "../strgPtr.h"

Test(strgLen, basic) {
    cr_expect_eq(strgLen("Stony Brook"), 11);
    //test down
    // cr_expect_eq(strgLen("CSE 220"), 7);
    // cr_expect_eq(strgLen("C"), 1);
    // cr_expect_eq(strgLen("1"), 1);
    // test up
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}

Test(strgCopy, truncation) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_expect_str_eq(d, "Comp");
}

//test
Test(strgCopy, sizeOne) {
    char d[1];
    strgCopy("", d, 1);
    cr_expect_str_eq(d, "");
}


Test(strgChangeCase, adjacency) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s, "sTONY bROOK");
}

// test
// Test(strgChangeCase, nextToDigit) {
//     char s[] = "CSE220";
//     strgChangeCase(s);
//     cr_expect_str_eq(s, "csE220");
// }

Test(strgInterleave, priority) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}
