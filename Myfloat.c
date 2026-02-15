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
   uint32_t sign_bit_int = sign_bit<<31;
   uint32_t exponent_int = exponent<<23;
   f= sign_bit_int | exponent_int| fraction;

   
   

   return *(float *)&f;
}
