#include "Myfloat.h"
#include <stdio.h>
#include<stdint.h>
//Shriyans Singh 114807762
float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   //Sign bit conversion and shifter.
   uint32_t sign_bit_int = sign_bit;
   sign_bit_int=sign_bit_int<<31;

   //Exponenet shifter and conversion
   uint32_t exponent_int = exponent;
   //Preventing unnecessary bits from interfering. Only care about 8 bits.
   exponent_int=exponent&0xFF;        //&0b11111111;
   exponent_int=exponent_int<<23;

   //Remove all unnecesssary bits in fraction
   fraction = fraction&0x7FFFFF;      //&0b11111111111111111111111;

   //combination of all three parts
   f= sign_bit_int | exponent_int| fraction;


   //Debugger printer to figure out error (figured out exponent was problem from here)
   //printf("sign = %X, exponent = %X, fraction = %X\n", sign_bit_int,exponent_int,fraction);
   

   return *(float *)&f;
}
