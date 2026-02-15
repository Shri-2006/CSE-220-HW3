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
   uint32_t sign_bit_int = sign_bit;
   sign_bit_int=sign_bit_int<<31;

   //unsigned to do proper shifting
   uint32_t exponent_int = exponent;
   exponent_int=exponent_int<<23;

   //combination of all three parts
   f= sign_bit_int | exponent_int| fraction;

   
   

   return *(float *)&f;
}
