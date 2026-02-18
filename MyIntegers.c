//Shriyans Singh 114807762
#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>//Professor Malik said that this library is ok to add

void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */
    
    //If not 2 or S in both repr, print "error\n"
    if((source_repr!='2' &&source_repr!='S')|| (target_repr!='2'&& target_repr!='S')){
        printf("error\n");
        //stop execution if bad input
        return;   
    }
    //if source is 2's complement
    if (source_repr=='2'){
        //if target is also 2's return repr since no change required
        if(target_repr == '2'){
            printf("%08x\n",repr);
            return;
        }
        //if target is 'S'
        else{
            int repr_int = (int) repr;
            //if unable to convert to signed, undefined due to bit limit
            if (repr==0x80000000){
                printf("undefined\n");
                return;
            }else{
                uint32_t res = 0;
                //if negative use absolute value to calculate
                if(repr_int<0){
                    res = -repr_int;
                    res=res|0x80000000;
                }
                else{
                    //if positive its repr;
                    res= repr;
                }
                printf("%08x\n",res);
                return;
            }
        }
    }
    //if source is signed
    else {
        //if target is same as source return repr
        if(target_repr == 'S'){
            printf("%08x\n",repr);
            return;
        }
        //if target is '2' convert to source to signed.
        else{
            //find sign bit
            uint32_t sign_bit = repr>>31;
            //store repr as temp and clean it.
            uint32_t temp = repr;
            temp= temp& 0x7FFFFFFF; 
            //if 0, print 0
            if(temp==0){
                printf("%08x\n",0);
                return;
            }
            //convert to signed value
            else{
                int signed_res=0;
                //if positive, no need to make signed bit negative
                if(sign_bit==0){
                    signed_res=(int)temp;
                    uint32_t res = (uint32_t)(signed_res);
                    printf("%08x\n",res);
                    return;
                }
                //Other cases would be negative, sign bit must be negative (1 for sign bit)
                else{
                    signed_res=-(int)(temp);
                    uint32_t res = (uint32_t)(signed_res);
                    printf("%08x\n",res);
                    return;
                }
            }
        }
    }

}



//Shriyans Singh (tests done visually)
/*

   repr_convert('2', 'S', 0x00000005);//return 00000005
   repr_convert('2', 'S', 0xffffffff);//return 80000001
   repr_convert('2', '2', 0xffffffff);//return ffffffff
   repr_convert('4','2',0xffffffff);//return error
   repr_convert('2','S', 0x00000000);//return 00000000
   repr_convert('S','2', 0x00000000);//return 00000000

*/
