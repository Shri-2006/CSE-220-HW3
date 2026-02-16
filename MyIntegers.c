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
            printf("0x%x\n",repr);
            return;
        }
        //if target is 'S'
        else{
            int repr_int = (int) repr;
            if (repr_int==0x80000000){
                printf("Undefined\n");
                return;
            }else{
                
                if(repr_int<0){
                    uint32_t res = -repr_int;
                    res=res|0x80000000;
                }
                else{
                    uint32_t res= repr;
                }
                printf("0x%x\n",res);
                return;
            }
            
            
        }

    }
    //source is signed
    else {
        //if target is same as source return repr
        if(target_repr == 'S'){
            printf("0x%x\n ",repr);
        }
        //if target is '2' convert
        else{

        }
    }


    



}
