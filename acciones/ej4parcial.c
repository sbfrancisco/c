#include <stdio.h>
int sumat, areaR, base, altura, fact, n;
int factorial (int n){
    int k, f;
    k=1;
    f=1;
    while(k<=n){
        f*=k;
        k++;
    }
    return f;
}
void sumatoria(int n, int *sum){
    int i;
    (*sum) = 0;
    for(i=0;i<=n;i++){
        (*sum)=(*sum)+i;
    }
}
void obtenerDatos(int *b, int *h){
    do{
        printf("Ingrese la base del rectangulo: \n");
        scanf("%d", &(*b));
        printf("Ingrese la altura del rectangulo: \n");
        scanf("%d", &(*h));
    }while((*b)== 0 || (*h) == 0);
}
void areaRect(int b, int h, int *area){
    (*area) = ((b*h)/2);
}

void main(){
    printf("Ingrese el numero a analizar: \n");
    scanf("%d", &n); 
    fact = factorial(n);
    sumatoria(n,&sumat);
    obtenerDatos(&base, &altura);
    areaRect(base,altura,&areaR);
    printf("El factorial de %d tiene como resultado: %d \n", n, fact);
    printf("La sumatoria de %d tiene como resultado: %d \n", n, sumat);
    printf("El area del rectangulo tiene como resultado: %d \n", areaR);

}