#include <stdio.h>
#define BinMax 30
typedef int TElem;
typedef TElem TBingo;
typedef struct{
    TBingo juego[BinMax];
    int cant;
}TData;
TData bingo;
void Jugar(TData *b){
char term;
int i;
term = 'n';
i = 0;
while((i<BinMax)&&(term=='n')){
    printf("Ingrese la bola que salio: \n");
    scanf("%d", &(*b).juego[i]);
    printf("Ingrese el caracter s, en caso de haber un ganador, ingrese n, si no hay un ganador: \n");
    scanf(" %c", &term);
    i++;
}
(*b).cant = i;
}
void mostrar(TData b){
    int i;
    for(i=0;i<b.cant;i++){
        printf("La bola que salio en la posicion %d, es %d \n", i+1, b.juego[i]);
    }
}
void main(){
    Jugar(&bingo);
    mostrar(bingo);
}