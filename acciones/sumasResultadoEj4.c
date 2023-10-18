#include <stdio.h>
int x,z;
float b;
void SumRes (int a, int b, int *c, float *multi){
    a= a+1;
    b= b-5;
    *multi=a*b;
    if(*multi>=0){
        *c = *c + *multi;
    } else {
        *c = *c - *multi;
    }
    }
void main(){
x = 0;
z = 10;
b = 100.0;
SumRes(1,z,&x,&b);
printf("%d %d %.2f",z, x, b);
}
