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
    }
    //if source is 2's complement
    if (source_repr=='2'){
        //if target is also 2's return repr
        if(target_repr == '2'){
            printf("%x\n",repr);
            
        }
    }



}
