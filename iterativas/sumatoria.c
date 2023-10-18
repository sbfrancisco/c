#include <stdio.h>
int n, sumatoria, i;
void main(){
    scanf("%d", &n);
        i = 1;
        sumatoria = 1;
     while(i<=n){
        i=i+1;
        sumatoria=sumatoria+i;
    };
printf("La sumatoria de el numero %d es de %d", n, sumatoria);
}