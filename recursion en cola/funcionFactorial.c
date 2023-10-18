// factorial con recursion de cola
#include <stdio.h>
int factorial(int n, int z){
    if(n==1){
        return z;
    } else {
        return factorial(n-1,n*z);
    }
}
int res;
void main(){
    res = factorial(4,1);
    printf("%d", res);
}