//Shriyans Singh 114807762
#include "Myfloat.h"
#include <stdio.h>
#include<stdint.h>
float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   //if sign bit is invalid, return 0.00
   if ((sign_bit!=0x00)&&(sign_bit!=0x01)){
      printf("Invalid Sign Bit: %c",sign_bit);
      return 0.00;
   }
   //Sign bit conversion and shifter.
   uint32_t sign_bit_int = (uint32_t)sign_bit;
   sign_bit_int=sign_bit_int&1;
   sign_bit_int=sign_bit_int<<31;

   //Exponenet shifter and conversion
   uint32_t exponent_int = (uint32_t)exponent;
   //Preventing unnecessary bits from interfering. Only care about 8 bits.
   exponent_int=exponent_int&0xFF;        //&0b11111111;
   exponent_int=exponent_int<<23;

   //Remove all unnecesssary bits in fraction
   fraction = fraction&0x7FFFFF;      //&0b11111111111111111111111;

   //combination of all three parts
   f= sign_bit_int | exponent_int| fraction;


   //Debugger printer to figure out error (figured out exponent was problem from here)
   //printf("sign = %x, exponent = %x, fraction = %X\n\n\n", sign_bit_int,exponent_int,fraction);
   

   return *(float *)&f;
}


   //positive Tests by Shriyans Singh
   /*
   f = construct_float_sf(0x00, 0x00, 0x0000000); //test if remains 0
   cr_assert_float_eq(f, 0.0, 0.00001);

   f = construct_float_sf(0x00, 0x7F, 0x000000);//1 means exponent is properly shifted.
   cr_assert_float_eq(f, 1, 0.00001);

   f = construct_float_sf(0x00, 0x80, 0x000000);//if 2, then 2 verifcations of positive exponent shift works
   cr_assert_float_eq(f, 2, 0.00001);

   f = construct_float_sf(0x00, 0x80, 0x200000);//if 2.5, then more verifcations of positive exponent shift works
   cr_assert_float_eq(f, 2.5, 0.00001);

   f = construct_float_sf(0x00, 0x7F, 0x400000); //1.5 means decimals work
   cr_assert_float_eq(f, 1.5, 0.00001);

   f = construct_float_sf(0x00, 0x91, 0x700000); //Checks large numbers (must be larger than 255439)
   cr_assert_float_eq(f, 491520, 0.00001);
   
   */




   //negative Tests by Shriyans Singh
   /*
   f = construct_float_sf(0x01, 0x00, 0x0000000); //tests if negative 0 works (only sign bit has a one)
   cr_assert_float_eq(f, -0, 0.00001);

   f = construct_float_sf(0x01, 0x7F, 0x000000);//-1 means exponent is being properl shifted.
   cr_assert_float_eq(f, -1, 0.00001);

   f = construct_float_sf(0x01, 0x80, 0x000000); //if -2 then 2 verifcation of negative exponent shift
   cr_assert_float_eq(f, -2, 0.00001);

     f = construct_float_sf(0x01, 0x80, 0x200000);//if -2.5, then 2 verifcations of positive exponent shift works
   cr_assert_float_eq(f, -2.5, 0.00001);

   f = construct_float_sf(0x01, 0x7F, 0x400000); //-1.5 negative decimals also work
   cr_assert_float_eq(f, -1.5, 0.00001);

   f = construct_float_sf(0x01, 0x91, 0x700000); //checks large negative numbers (less than -255439 )
   cr_assert_float_eq(f, -491520, 0.00001);
   */
    //I wasn't sure how to write the edge case for if sign bit is invalid in criterion so I left it out.

