//#Shriyans Singh 114807762
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
   //tests by Shriyans Singh
   /*
   cr_assert_eq(ToggleBit(0,0),1);
   cr_assert_eq(ToggleBit(1,0),0);
   cr_assert_eq(ToggleBit(0,2),4);
   cr_assert_eq(ToggleBit(-1,3),-9);
   cr_assert_eq(ToggleBit(2147483647,31),-1);
   cr_assert_eq(ToggleBit(20,3),28);
   cr_assert_eq(ToggleBit(20,5),52)
   */
}


Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);
   //Tests by Shriyans Singh
   /*
   cr_assert_eq(GetMSB(2147483647),30);
   cr_assert_eq(GetMSB(-1),31);
   cr_assert_eq(GetMSB(23),4);
   cr_assert_eq(GetMSB(43),5);
   cr_assert_eq(GetMSB(73),6);
   */

    
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);

   //Tests by Shriyans Singh
   /*
   cr_assert_eq(ClearBitRange(2,10,1),2); //checks start>end constraint
   cr_assert_eq(ClearBitRange(2,-10,1),2); //checks -start constraint, return num
   cr_assert_eq(ClearBitRange(2,10,41),2); //checks end>31 constraint, return num
   cr_assert_eq(ClearBitRange(9,1,4),1); //clears all bit but first 
   cr_assert_eq(ClearBitRange(63,1,5),1); //clears all bit but first
   cr_assert_eq(ClearBitRange(100000,0,0),0); //checks if only one bit changes
   cr_assert_eq(ClearBitRange(63,0,0),62);// checks if only one bit changes
   cr_assert_eq(ClearBitRange(23,0,10),0); //checks if all bits cleared

   */
}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);

    //Tests by Shriyans Singh
   /*
   cr_assert_eq(RotateLeft(23,-4),23);//deals with negative d check
   cr_assert_eq(RotateLeft(1,31),-2147483648); //puts first bit into MSB, making it negative. 
   cr_assert_eq(RotateLeft(0,100),0);//checks if any bits are actually changed instead of simply being moved.
   cr_assert_eq(RotateLeft(-1,31),-1);//another check to see if bits are affected. 
   cr_assert_eq(RotateLeft(23,32),23); //should result in same thing since moved by 0 bits

   */
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
}


