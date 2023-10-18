#include <stdio.h>
float t1, t2, t3;
float tMenor, tIntermedio, tMayor;
void main(){
    printf("Ingrese el tiempo del primer nadador: \n");
    scanf("%f",&t1);
    printf("Ingrese el tiempo del segundo nadador: \n");
    scanf("%f",&t2);
    printf("Ingrese el tiempo del tercer nadador: \n");
    scanf("%f",&t3);
        if(t1>t2 && t2>t3){
            tMenor = t3;
            tIntermedio = t2;
            tMayor = t1;
        } else if (t1>t3 && t3>t2){
                tMenor = t2;
                tIntermedio = t3;
                tMayor = t1;
         }      else if(t2>t3 && t3>t1){
                    tMenor = t1;
                    tIntermedio = t3;
                    tMayor = t2;
                    } else if(t2>t1 && t1>t3){
                        tMenor = t3;
                        tIntermedio = t1;
                        tMayor = t2;
                        } else if(t3>t1 && t1>t2){
                            tMenor = t2;
                            tIntermedio = t1;
                            tMayor = t3;
                             } else if(t3>t2 && t2>t1){
                                    tMenor=t1;
                                    tIntermedio=t2;
                                    tMayor=t3;
                        }
                            printf("El menor tiempo fue de:%2.f \n", tMenor);
                            printf("El tiempo intermedio fue de:%2.f \n", tIntermedio);
                            printf("El mayor tiempo fue de: %2.f \n", tMayor);
}
        