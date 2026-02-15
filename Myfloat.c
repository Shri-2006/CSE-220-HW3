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
   exponent=exponent&0b11111111
   exponent_int=exponent_int<<23;

   //keep only first 23 bits
   fraction = fraction&0b11111111111111111111111;

   //combination of all three parts
   f= sign_bit_int | exponent_int| fraction;

   printf("sign = %X, exponent = %X, fraction = %X, f = %f", sign_bit_int,exponent_int,fraction,f);
   

   return *(float *)&f;
}
