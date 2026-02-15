#Shriyans Singh 114807762
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

I ran the tests while writing the code in programiz.com/c-programming/online-compiler/
Part 1:
Q1: In ToggleBit(num, pos) I put the edge case of less than 0, or greater than 31 since we are assuming 32 bits for integer

Q2: made bit_check an unsigned integer because i got worried about -0 error (I tested in a vm, and local. VM had error, local didn't).

Q3. Wrote the constraints requested of start<0, end>31, start>end return num. Additionally made one an unsigned integer to prevent -0 error that happened on vm.

Q4. Constraint to prevent -d. Constraint to reduce d to under 32.

Q5.used uint32_t because piazza mentioned for an earlier problem, and its quicker to type than unsigned int.                                                                                                                                                                                                                                              //OLD:Constraint to prevent -d. wasn't mentioned in assignment so I assume it doesn't exist, but I made it just in case. Constraint to prevent d from being greater than 31 (number could be put, but it would be less than 32). Created a checker to see if most significant bit is one. Did a unsigned int temp= num because of the -0 error thing.

Togglebit test cases I wrote:
   cr_assert_eq(ToggleBit(2,-1),2); - check negative constraint, return num
   cr_assert_eq(ToggleBit(2,43),2); - check over 31 constraint, return num
   cr_assert_eq(ToggleBit(0,0),1); - Flip the first bit which is a 0, results in 1.
   cr_assert_eq(ToggleBit(1,0),0); -Flip the first bit which is a 1, results in 0.
   cr_assert_eq(ToggleBit(0,2),4);  - Flip the second bit which is 0, results in 100, which is a 4.
   cr_assert_eq(ToggleBit(-1,3),-9); - Flip the 3 bit, and it is already -1, so MSB is still 1, and the third bit is flipped, resulting in 9.
   cr_assert_eq(ToggleBit(2147483647,31),-1); - Flip the MSB, turning into negative. Results in -1.
   cr_assert_eq(ToggleBit(20,3),28); - Flip third bit from 0 to 1, resulting in 20+8=28
   cr_assert_eq(ToggleBit(20,5),52) - Flip the 5th bit, adding 32 to 20 resulting in 52. 

  //GetMSB Tests by Shriyans Singh
   /*
   cr_assert_eq(GetMSB(2147483647),30); - all bits except MSB bit is 1, so MSB bit with 1 is 30.
   cr_assert_eq(GetMSB(-1),31);-Since negative, MSB bit (31) is 1
   cr_assert_eq(GetMSB(23),4); - 23=00010111, MSB with 1 is 4
   cr_assert_eq(GetMSB(43),5); - 43 = 00101011, MSB with 1 is 5
   cr_assert_eq(GetMSB(73),6); - 73 = 01001001, MSB with 1 is 6
   */


      //TClearBitRangeests by Shriyans Singh
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

       //Rotate Left Tests by Shriyans Singh
   /*
   cr_assert_eq(RotateLeft(23,-4),23);//deals with negative d check
   cr_assert_eq(RotateLeft(1,31),-2147483648); //puts first bit into MSB, making it negative. 
   cr_assert_eq(RotateLeft(0,100),0);//checks if any bits are actually changed instead of simply being moved.
   cr_assert_eq(RotateLeft(-1,31),-1);//another check to see if bits are affected. 
   cr_assert_eq(RotateLeft(23,32),23); //should result in same thing since moved by 0 bits

   */


 //SwapOddEvenBits Test by Shriyans Singh
   /*
   cr_assert_eq(SwapOddEvenBits(0),0); //should remain 0 since all is 0 bit
   cr_assert_eq(SwapOddEvenBits(1),2); //should become 2 since 0001 would change 0010.
   cr_assert_eq(SwapOddEvenBits(2),1); //should become 1 since 0010 becomes 0001. Basically checking the reverse 
   cr_assert_eq(SwapOddEvenBits(7),11); // 0111 becomes 1011 since first two bits swap with each other, and the MSB with a 1 swaps with MSB.
   cr_assert_eq(SwapOddEvenBits(-1),-1); //remains the same since all bits are 1. Checks if negatives work.
   
   */


   Part 2:Myfloat.case
   