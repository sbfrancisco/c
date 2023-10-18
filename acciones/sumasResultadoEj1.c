#include <stdio.h>
int x,y,z;
float p;
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
x = 16;
y = 5;
z = 20;
p = 42.0;
SumRes(x,y,&z,&p);
printf("%d %d %d %.2f", x, y, z, p);
}
