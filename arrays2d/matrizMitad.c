#include <stdio.h>
#define MFila 20
#define MCol 20
typedef struct {
    int dato[MFila][MCol];
    int cantFila;
    int cantCol;
}TMatriz;
TMatriz matriz;
int sum;
void cargarMatriz(TMatriz *a){
    int i,j;
    printf("Ingresar la cantidad de filas de la matriz \n");
    scanf("%d", &(*a).cantFila);
    printf("Ingresar la cantidad de columnas de la matriz \n");
    scanf("%d", &(*a).cantCol);
        for(i=0;i<(*a).cantFila;i++){
            for(j=0;j<(*a).cantCol;j++){
                printf("Ingrese el numero que va a almacenar en la fila %d, columna %d: \n", i , j);
                scanf("%d", &(*a).dato[i][j]);
            }
        }
}
 void sumaMatriz(TMatriz a, int *suma){
  int i,j;
  (*suma)=0;
  for(i=0;i<a.cantFila/2;i++){
    for(j=0;j<(a.cantCol/2)+1;j++){
        (*suma)=(*suma)+(a.dato[i][j]);
    }
}
}
void main(){
    cargarMatriz(&matriz);
    sumaMatriz(matriz,&sum);
    printf("La suma de los elementos de la matriz es: %d \n", sum);
}