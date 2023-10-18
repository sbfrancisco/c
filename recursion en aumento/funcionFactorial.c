// factorial con recursion en aumento
#include <stdio.h>
int factorial(int n){
    if(n==1){
        return 1;
    } else {
        return n*factorial(n-1);
    }
}
int res;
void main(){
    res = factorial(4);
    printf("%d", res);
}