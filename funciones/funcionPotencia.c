int potencia (int c, int d){
    int i, res, base;
    i = 1;
    res = 1;
    while(c>=i){
        base = d;
        res = res * base;
        i++;
    }
    return res;
}
#include <stdio.h>
int a, y;
int resul;
int main(){
    printf("Ingrese el numero que quiere elevar a la y: \n");
    scanf("%d", &a);
    printf("Ingrese la potencia que quiere elevar a la y: \n");
    scanf("%d", &y);
    resul = potencia(a, y);
    printf("El numero %d elevado a la %d es: %d", a, y, resul);
}
