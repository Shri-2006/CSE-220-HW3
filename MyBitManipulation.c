// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>
#include <stdint.h>
//Shriyans Singh 114807762
/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   //prevent improper pos
   if (pos <0||pos>31){
      return num;
   }
   //Flip = XOR. (using slide 3 of lecture 6 to figure out the math here.)
   int bit_for_toggle= (1<<pos);
   num= num^bit_for_toggle;
   return num;
}

   //ToggleBit tests by Shriyans Singh
  /*
   cr_assert_eq(ToggleBit(2,-1),2);
   cr_assert_eq(ToggleBit(2,43),2);
   cr_assert_eq(ToggleBit(0,0),1);
   cr_assert_eq(ToggleBit(1,0),0);
   cr_assert_eq(ToggleBit(0,2),4);
   cr_assert_eq(ToggleBit(-1,3),-9);
   cr_assert_eq(ToggleBit(2147483647,31),-1);
   cr_assert_eq(ToggleBit(20,3),28);
   cr_assert_eq(ToggleBit(20,5),52)
   */




/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   for(int pos=31; pos>=0;pos--){
      //must be unsigned to prevent -0 error
      unsigned int bit_check=1;
      bit_check=(bit_check<<pos);

      //check if bit is 1
      if((num&bit_check)!=0){
         return pos;
      }
   }
   //if no 1, return -1
   return -1;
}


  //GetMSB Tests by Shriyans Singh
   /*
   cr_assert_eq(GetMSB(2147483647),30);
   cr_assert_eq(GetMSB(-1),31);
   cr_assert_eq(GetMSB(23),4);
   cr_assert_eq(GetMSB(43),5);
   cr_assert_eq(GetMSB(73),6);
   */


/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   //set constraints
   if(start < 0 || end >31 || start>end){
      return num;
   }

   //while start<=end run clearer
   for (int i=start; i<=end; i++){
      //unsigned to prevent -0 error here
      unsigned int one=1;
      //all bits but bit to be cleared set to 1
      unsigned int bit_clearer=~(one<<i);

     //clear bits using & operator
      num=num&bit_clearer;

   }
   return num;
}

   //ClearBitRange Tests by Shriyans Singh
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

/*
* Rotate num to the left by d bits
*/
//based on piazza
uint32_t RotateLeft(uint32_t num, int d) {
   //if negative d retutn num
   if (d<0){
      return num;
   }
   //Reduce d to under 32.
   while(d>31){
      d=d-32;
   }
   //create shifted left by d position. 
   uint32_t num_left=num<<d;
   //Stored positions lost in num_right.
   uint32_t num_right=num>>(32-d);

   //combine left & right
   num = num_left|num_right;

   return num;
}

    //RotateLeft Tests by Shriyans Singh
   /*
   cr_assert_eq(RotateLeft(23,-4),23);//deals with negative d check
   cr_assert_eq(RotateLeft(1,31),-2147483648); //puts first bit into MSB, making it negative. 
   cr_assert_eq(RotateLeft(0,100),0);//checks if any bits are actually changed instead of simply being moved.
   cr_assert_eq(RotateLeft(-1,31),-1);//another check to see if bits are affected. 
   cr_assert_eq(RotateLeft(23,32),23); //should result in same thing since moved by 0 bits

   */


/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   //Unsigned to allow for bit operations
   uint32_t temp= num;

   //edven bits swap
   uint32_t even_num=temp& 0xAAAAAAAA;
   even_num=even_num>>1;

   //odd bit
   uint32_t  odd_num=temp &0x55555555;
   odd_num=odd_num<<1;

   //combine into num
   num=even_num|odd_num;

   return num;
}
