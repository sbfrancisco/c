#include <stdio.h>
#include <string.h>
float costoConEnvio, costoSinEnvio;
char mensaje[89];
#define CostoEnvio 0.01
void main(){
    printf("Ingrese el costo de la computadora con envio incluido: \n");
    scanf("%f",&costoConEnvio);
    printf("Ingrese el costo de la computadora sin el costo de envio incluido: \n");
    scanf("%f",&costoSinEnvio);
      costoSinEnvio = (costoSinEnvio * CostoEnvio) + costoSinEnvio;
      if(costoSinEnvio>costoConEnvio){
        strcpy(mensaje, "El precio conveniente para comprar la computadora es el de la pagina con costo con envio");
      }else if(costoConEnvio>costoSinEnvio){
        strcpy(mensaje, "El precio conveniente para comprar la computadora es el de la pagina sin envio");
            }else{
                strcpy(mensaje,"El precio de las dos paginas es equivalente");
            }
            
     printf("%s", mensaje);
            }

