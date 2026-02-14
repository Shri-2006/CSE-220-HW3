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

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   /* TODO: implement */
   return num;
}

/*
* Rotate num to the left by d bits
*/
int RotateLeft(int num, int d) {
   /* TODO: implement */
   return num;
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* TODO: implement */
   return num;
}
