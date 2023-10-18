/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int i;
void main(){
    for(i=1;i<=100;i++){
        if(i%2==0 && i%4==0 && i%6==0){
            printf("El numero %d es divisible por 2, 4, 6 \n", i);
         }
    }
}
    
    
