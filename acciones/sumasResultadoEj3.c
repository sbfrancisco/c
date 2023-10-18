#include <stdio.h>
int a,b,c;
float pr;
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
b = 8;
a = -6;
c = 10;
SumRes(b,a,&c,&pr);
printf("%d %d %d %.2f",b, a, c, pr);
}
