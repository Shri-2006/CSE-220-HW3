//Shriyans Singh 114807762
#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

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
        int res = (int) repr;
        //if target is also 2's return repr
        if(target_repr == '2'){
            printf("%8x\n",repr);
            return;
        }
        //if target is 'S'
        else{
            int repr_int = (int) repr;
            //if unable to convert to signed, undefined
            if (repr==0x80000000){
                printf("undefined\n");
                return;
            }else{
                uint32_t res = 0;
                //if negative use absolute value for it.
                if(repr_int<0){
                    res = -repr_int;
                    res=res|0x80000000;
                }
                else{
                    //if positive its repr;
                    res= repr;
                }
                printf("%8x\n",res);
                return;
            }
        }
    }
    //source is signed
    else {
        //if target is same as source return repr
        if(target_repr == 'S'){
            printf("%8x\n ",repr);
            return;
        }
        //if target is '2' convert
        else{
            //find sign bit
            uint32_t sign_bit = repr>>31;
            //store repr as temp and clean it.
            uint32_t temp = repr;
            temp= temp& 0x7FFFFFFF; 
            //if 0, print 0
            if(temp==0){
                printf("%8x\n",0);
                return;
            }
            //convert to signed value
            else{
                int signed_res=0;
                if(sign_bit==0){
                    signed_res=(int)temp;
                    uint32_t res = (uint32_t)(signed_res);
                    printf("%8x\n",res);
                }
                else{
                    signed_res=-(int)(temp);
                    uint32_t res = (uint32_t)(signed_res);
                    printf("%8x\n",res);
                }
            }
        }
    }


    



}
