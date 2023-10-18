#include <stdio.h>
#include <string.h>
  struct TCarta{
    char palo1;
    int carta1;
    char palo2;
    int carta2;
    char palo3;
    int carta3;
};
    int SumatoriaPuntos(struct TCarta b){
        int puntos;
        if((b.palo1==b.palo2 && b.palo2!=b.palo3) && (b.carta1<=7 && b.carta2<=7)){
            puntos = 20 + b.carta1 + b.carta2;
        } else {
            if(((b.palo1==b.palo3) && (b.palo3!=b.palo2)) && (b.carta1<=7 && b.carta3<=7)){
                puntos = 20 + b.carta1 + b.carta3;
            } else {
              if(((b.palo2==b.palo3) && (b.palo3!=b.palo1)) && (b.carta2<=7 && b.carta3<=7)){  
                puntos = 20 + b.carta2 + b.carta3;
              } else {
                if(((b.palo1==b.palo2) && (b.palo2!=b.palo3)) && (b.carta1<=7 && b.carta2>7)){
            puntos = 20 + b.carta1;
                } else {
                    if(((b.palo1==b.palo2) && (b.palo2!=b.palo3)) && (b.carta1>7 && b.carta2<=7)){
                     puntos = 20 + b.carta2;
                    } else {
                        if(((b.palo2==b.palo3) && (b.palo3!=b.palo1)) && (b.carta2>7 && b.carta3<=7)){
                            puntos = 20 + b.carta3;
                            } else {
                        if(((b.palo2==b.palo3) && (b.palo3!=b.palo1)) && (b.carta2<=7 && b.carta3>7)){
                            puntos = 20 + b.carta2;
                        } else {
                            if(((b.palo1==b.palo3) && (b.palo3!=b.palo2)) && (b.carta1>7 && b.carta3<=7)){
                            puntos = 20 + b.carta3;
                            } else {
                        if(((b.palo1==b.palo3) && (b.palo3!=b.palo2)) && (b.carta1<=7 && b.carta3>7)){
                            puntos = 20 + b.carta1;
                        }
                    }        
                }
              }
            }
         }
        }
      }
     }
     return puntos;
    }
    struct TCarta a;
    int puntaje;
    int main(void){
        printf("Ingrese el palo de su primer carta: \n");
        scanf(" %c", &a.palo1);
        printf("Ingrese el palo de su segunda carta: \n");
        scanf(" %c", &a.palo2);
        printf("Ingrese el palo de su tercer carta: \n");
        scanf(" %c", &a.palo3);
        do{
            printf("Ingrese el valor de su primer carta: \n");
        scanf("%d", &a.carta1);
        }while(a.carta1<=0 || a.carta1>12);
        do{
            printf("Ingrese el valor de su segunda carta: \n");
        scanf("%d", &a.carta2);
        }while(a.carta2<=0 || a.carta2>12);
        do{
            printf("Ingrese el valor de su tercer carta: \n");
        scanf("%d", &a.carta3);
        }while(a.carta3<=0 || a.carta3>12);

    puntaje=SumatoriaPuntos(a);
    printf("Usted tiene la cantidad de %d puntos", puntaje);
    }