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
void cargarMatriz(TMatriz *a);
 void corazon(TMatriz a, int *suma);
void cascara(TMatriz a, int suma);
void main(){
    cargarMatriz(&matriz);
    corazon(matriz,&sum);
    cascara(matriz,sum);
}
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
 void corazon(TMatriz a, int *suma){
  int i,j;
  (*suma)=0;
  for(i=1;i<a.cantFila-1;i++){
    for(j=1;j<a.cantCol-1;j++){
    (*suma)=(*suma)+(a.dato[i][j]);
  }
 }
}
void cascara(TMatriz a, int suma){
  int i,j;
  int total;
 total = 0;
   for(i=0;i<a.cantFila;i++){
     for(j=0;j<a.cantCol;j++){
        total = total + a.dato[i][j];
    }
}
 total = total - suma;
 if(total==suma){
    printf("La sumatoria de las celdas límites es igual que la sumatoria las celdas del interior");
 }
}