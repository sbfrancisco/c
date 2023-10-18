#include <string.h>
#include <stdio.h>
char sint1[10], sint2[10], sint3[10], sint4[10], sint5[10];
int indicio1, indicio2, indicio3, indicio4, indicio5;
char mensaje[47];
void main(){
    printf("Ingrese el primer sintoma que registra el paciente: \n");
    scanf("%s", sint1);
    printf("Ingrese el segundo sintoma que registra en el paciente: \n");
    scanf("%s",sint2);
    printf("Ingrese el tercer sintoma que registra en el paciente: \n");
    scanf("%s",sint3);
    printf("Ingrese el cuarto sintoma que registra en el paciente: \n");
    scanf("%s",sint4);
    printf("Ingrese el quinto sintoma que registra en el paciente: \n");
    scanf("%s",sint5);

     if(strcmp (sint1, "tos") == 0){
            indicio1= 1;
     }

        if(strcmp (sint2, "estornudo") == 0){
            indicio2= 1;
        }
             if(strcmp (sint3, "fiebre") == 0){
                 indicio3= 1;
               }
                    if(strcmp (sint4, "moco") == 0){
                         indicio4= 1;
                        }
                            if(strcmp (sint5, "congestion") == 0){
                                indicio5= 1;
                               } else if(strcmp(sint5, "vomito") == 0){
                                        indicio5=2;
                                    } else  if(strcmp(sint5, "flema") == 0){
                                                    indicio5=3;
                                            }
    if(indicio1==1 && indicio5==3){
        strcpy(mensaje, "Se le diagnostico coronavirus");
         } else if(indicio3==1 && indicio2	!= 1 && indicio5==3){
             strcpy(mensaje, "Se le diagnostico coronavirus");
               } else if(indicio3==1 && indicio4==1 && indicio2==1 && indicio5==2){
                    strcpy(mensaje, "Se le diagnostico gripe");
                            } else if(indicio4 != 1 && indicio5==1){
                                    strcpy(mensaje, "Se le diagnostico resfrio");
                                        }else{
                                            strcpy(mensaje, "Segun los indicios ingresados, no esta enfermo");
                                        }
    printf("%s", mensaje);
}

