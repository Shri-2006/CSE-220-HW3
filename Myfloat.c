#include "Myfloat.h"
#include <stdio.h>
#include<stdint.h>
//Shriyans Singh 114807762
float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
    */
   //Unsigned to do proper shifting.
   unsigned int sign_bit_int = sign_bit;
   sign_bit_int=sign_bit_int<<31;

   //unsigned to do proper shifting
   unsigned int exponent_int = exponent;
   //Preventing unnecessary bits from interfering. Only care about 8 bits.
   exponent_int=exponent&0b11111111;
   exponent_int=exponent_int<<23;

   //keep only first 23 bits
   fraction = fraction&0b11111111111111111111111;

   //combination of all three parts
   f= sign_bit_int | exponent_int| fraction;
   //Debugger tool to figure out error
   //printf("sign = %X, exponent = %X, fraction = %X\n", sign_bit_int,exponent_int,fraction);
   

   return *(float *)&f;
}
