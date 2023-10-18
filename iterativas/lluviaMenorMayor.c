#include <stdio.h>
int lluviaMayor, lluviaMenor, lluviaInter;
int lluvia, i;
int main(){
    i=0;
    lluviaMayor = 0;
    lluviaMenor = 0;
 do{
     printf("Ingrese cuanto llovio en el mes %d: \n", (i+1));
     scanf("%d", &lluvia);
      if(i==0){
          lluviaMayor = lluvia;
          lluviaMenor = lluvia;
             }  else if(lluvia>lluviaMayor){
            lluviaMayor = lluvia;
        } else if(lluvia<lluviaMenor){
            lluviaMenor = lluvia;
        }
                i++;
     
     }while(!(12<=i));
     printf("La menor precipitacion fue de %d, y la mayor precipitacion fue de %d", lluviaMenor,  lluviaMayor);
 }   
