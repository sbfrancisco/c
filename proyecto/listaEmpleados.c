#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NMax 150
typedef struct{
    int dia;
    int mes;
    int anio;
}TFecha;
typedef struct{
    int dni;
    char nombre[20];
    char apellido[20];
    TFecha nacimiento;
    int edad; 
    char ciudad[20]; 
    char ciudadAntes[20]; 
    char DP[30];
    char CE[20];
    char telefono[15];
    bool VF;
    TFecha fallecimiento;
    char beneficio[20];
    char CP[10];
    char provincia[50];
    int fuerza;
    char destino[50];
    char funcion[100];
    char grado[20];
    char secuelas[200];
}TPers;
typedef TPers TArreglo;
typedef struct{
    TArreglo p[NMax];
    int cant;
}TData;
typedef struct nodolse{
    struct nodolse *next;
    TPers info;
}TFallecido;
typedef struct nodo{
    struct nodo *next;
    struct nodo *back;
    TPers info;
}TFuerza;
TFuerza *fuerzaPri, *fuerzaUlt;
TFallecido *fallecidos;
TFecha fechaActual;
TData personas;
TPers persona;
char ap[20];
int opcion, dni, pos, mes;
FILE* f;
TPers datos;
bool bisiesto(int a);
int dias(TFecha a);
int edad(TFecha a, TFecha b);
int posicion(TData a, int i, int dni);
void insertar(TData *a, TPers b);
void suprimir(TData *a, int pos);
bool repetido(TData a, int dni);
bool llena(TData a);
bool vacia(TData a);
void modificar(TData *a,int pos);
void mostrar(TData a);
void mostrarReg(TPers reg);
void obtenerFecha(TFecha *a);
void mantenerOrden(TData *a);
void mostrarCumpleaños(TData b, int mes);
void ordenarDia(TData *a);
void inicializarLSE(TFallecido **list);
void insertarCabecera(TFallecido **list, TPers reg);
void listaFallecidos(TFallecido **list, TData a);
void mostrarLSE(TFallecido *list);
int buscarPos(TData a, int i, TPers reg);
void inicializarLDE(TFuerza **pri, TFuerza **ult);
void insertarLDE(TFuerza **pri, TFuerza **ult, TData a);
void mostrarLDE(TFuerza *pri, TFuerza *ult);
void mostrarApellido(TData a, char ap[20]);
void limpiarLSE(TFallecido **q);
void limpiarLDE(TFuerza **pri, TFuerza **ult);
void obtenerDatos(FILE* f, TData *a);
void almacenarDatos(FILE* f, TData a);
void main(){
  personas.cant=0;
  fallecidos=NULL;

  inicializarLDE(&fuerzaPri, &fuerzaUlt);
  inicializarLSE(&fallecidos);
  printf("Ingrese los datos de la fecha actual\n");
  obtenerFecha(&fechaActual);
  obtenerDatos(f,&personas);
   do{
   printf("\n\n\t\t\tMENU PRINCIPAL\n");
   printf("\t\t\t--------------\n");
   printf("1. Alta de persona\n");
   printf("2. Baja de persona\n");
   printf("3. Modificar datos de persona \n");
   printf("4. Listar todas las personas registradas \n");
   printf("5. Listar todas las personas segun su apellido\n");
   printf("6. Listar personas fallecidas\n");
   printf("7. Listar personas segun fuerza a la que pertenecio\n");
   printf("8. Listar personas que cumplen años en un mes\n");
   printf("9. Salir\n");
   printf("\nIngrese la opcion: ");
   scanf("%d", &opcion);
    if(opcion==1){ 
       if(!llena(personas)){
        do{
		printf("Ingrese el DNI de la persona a ingresar:\n"); scanf("%d",&persona.dni);
		}while(repetido(personas,persona.dni));
        printf("Ingrese el nombre de la persona a ingresar:\n"); scanf("%s",persona.nombre);
		printf("Ingrese el apellido de la persona a ingresar:\n"); scanf("%s",persona.apellido);
		do{
		  printf("Ingrese los datos de nacimiento de la persona a ingresar:\n");
		  obtenerFecha(&persona.nacimiento);
		}while((edad(persona.nacimiento,fechaActual)<0));
       persona.edad= edad(persona.nacimiento,fechaActual);
       printf("Ingrese la ciudad donde reside la persona a ingresar:\n"); scanf("%s",persona.ciudad);
       printf("Ingrese la ciudad donde residia antes de malvinas de la persona a ingresar:\n"); scanf("%s",persona.ciudad);
       printf("Ingrese el codigo postal de la ciudad de la persona a ingresar:\n"); scanf("%s",persona.CP);
       printf("Ingrese la direccion postal de la ciudad de la persona a ingresar:\n"); scanf("%s",persona.CP);
       printf("Ingrese el correo de la persona a ingresar:\n"); scanf("%s",persona.CE);
       printf("Ingrese el telefono de la persona a ingresar:\n"); scanf("%s",persona.telefono);
	   do{
       printf("Ingrese si actualmente la persona esta viva:\n"); scanf("%d",&persona.VF); // 1 si, 0 no
	   }while(persona.VF!=0 && persona.VF!=1);
		if(!persona.VF){	
            do{
            printf("Ingrese los datos de fallecimiento de la persona a ingresar:\n");
			obtenerFecha(&persona.fallecimiento);
		}while((edad(persona.nacimiento,persona.fallecimiento)<0));
        }
        printf("Ingrese el numero de beneficio nacional de la persona a ingresar:\n"); scanf("%s",persona.beneficio);
        printf("Ingrese la provincia donde nacio la de la persona a ingresar:\n"); scanf("%s",persona.provincia);
        do{
          printf("Ingrese la fuerza a la que pertenecio la persona a ingresar:\n");  printf("1. Marina\n2. Gendarmeria\n3. Ejercito\n4. Aeronautica\n"); printf("Ingrese la opcion deseada: "); scanf("%d",&persona.fuerza);
        }while(!(persona.fuerza>0 && persona.fuerza<5));
        printf("Ingrese el destino en malvinas de la persona a ingresar: \n"); scanf("%s",persona.destino);
        printf("Describa la funcion en malvinas de la persona a ingresar: \n"); scanf("%s",persona.funcion);
        printf("Ingrese el grado en malvinas de la persona a ingresar: \n");scanf("%s",persona.grado); 
        printf("Describa las secuelas posteriores a malvinas de la persona a ingresar: \n"); scanf("%s",persona.secuelas);
         insertar(&personas,persona);
        } else {
          printf("La lista esta llena\n");
        }
    } else {
        if(opcion==2){
			if(vacia(personas)){
				printf("La lista de personas esta vacia\n");
			} else {
			    printf("Ingrese el documento de la persona a eliminar: "); scanf("%d", &dni);
                pos = posicion(personas,0,dni);
                if(pos<0){
                    printf("La posicion ingresada es invalida\n");
                } else {
				suprimir(&personas,pos);
				printf("El empleado fue suprimido\n");
			}
			}
        } else {
            if(opcion==3){
			  printf("Ingrese el documento de la persona a modificar: "); scanf("%d", &dni);
              pos = posicion(personas,0,dni);
                if(pos<0){
                 printf("La posicion ingresada es invalida\n");
                } else {
                  modificar(&personas,pos);
                }
            } else {
                if(opcion==4){
                    if(personas.cant>0){
				  printf("Los empleados registrados son: \n");
				  mostrar(personas);
				} else {
					printf("La lista esta vacia\n");
				}
                } else {
                    if(opcion==5){
                        scanf("%s",ap);
                        mostrarApellido(personas,ap);
                    } else {
                        if(opcion==6){
                           listaFallecidos(&fallecidos,personas);
                           mostrarLSE(fallecidos);
                           limpiarLSE(&fallecidos);
                        } else {
                            if(opcion==7){
                               if(!vacia(personas)){
                                insertarLDE(&fuerzaPri,&fuerzaUlt,personas);
                                mostrarLDE(fuerzaPri,fuerzaUlt);
                                limpiarLDE(&fuerzaPri,&fuerzaUlt);
                               } else {
                                 printf("No hay soldados registrados\n");
                                }
                            } else {
                                if(opcion==8){
                                  printf("Ingrese el mes que quiera generar la lista:\n"); scanf("%d",&mes);
                                  mostrarCumpleaños(personas,mes);
                                }
                            }
                        }
                    }
                }    
            }
        }
    }
}while(opcion>0 && opcion<9);
almacenarDatos(f,personas);
}
void obtenerDatos(FILE* f, TData *a){
 int i;
 TPers reg;
    f = fopen("personas.dat","rb");
    i=0;
    if(f!=NULL){
    while(!feof(f)){
        fread(&reg,sizeof(TPers),1,f);
        if(!feof(f)){
            a->p[i]=reg;
            i++;
        }
      }
    }
    fclose(f);
   a->cant=i;
}
void almacenarDatos(FILE *f,TData a){
 int i;
    f = fopen("personas.dat","w+b");
    for(i=0;i<a.cant;i++){
        fwrite(&a.p[i],sizeof(TPers),1,f);
    }
    fclose(f);
}
 bool bisiesto(int a){
   return (a%4==0 && a%100!=0)||(a%100==0 && a%400==0);
 }
 int dias(TFecha a){
    if(a.mes==1 || a.mes==3 || a.mes==5 || a.mes==7 || a.mes==8 || a.mes==10 || a.mes==12){
        return 31;
    }else{
      if(a.mes==4 || a.mes==6 || a.mes==9 || a.mes==11){
        return 30;
     } else {
         if(a.mes==2 && bisiesto(a.anio)){
             return 29;
         } else {
             return 28;
         }
      }
   }
}
void obtenerFecha(TFecha *a){
  int valido;
  printf("Ingrese el año:\n"); scanf("%d",&a->anio); 
  do{
  printf("Ingrese el mes:\n"); scanf("%d",&a->mes);
 }while(!(a->mes>=1 && fechaActual.mes<=12));
  do{  
  printf("Ingrese el dia:\n"); scanf("%d",&a->dia);
  valido= dias((*a)); 
  }while(a->dia>valido);
}
 int edad(TFecha a, TFecha b){
  int e;
  e = b.anio - a.anio;
   if(a.mes>b.mes){
    e = e-1;
    } else {
     if(a.mes==b.mes){
       if(a.dia>b.dia){
         e = e-1;
        }
      }
    }
 return e;
 }
int posicion(TData a, int i, int dni){
    if(i>=a.cant){
        return -1;
    } else {
        if(a.p[i].dni==dni){
            return i;
        } else {
            return posicion(a,i+1,dni);
        }
    }
 
 }
 bool compararElementos(TPers a, TPers b){
    return ((strcmp(a.apellido,b.apellido)>0) || ((strcmp(a.apellido,b.apellido)==0) && (strcmp(a.nombre,b.nombre)>0)) || (strcmp(a.apellido,b.apellido)==0) && (strcmp(a.nombre,b.nombre)>=0) && (a.dni > b.dni));
 }
 void insertar(TData *a, TPers b){
  int i,pos;
  pos = buscarPos(*a,0,b);
  for(i=a->cant;i>=pos;i--){
    a->p[i+1]= a->p[i];
  }
   a->p[pos]=b;
   (*a).cant++;
}
int buscarPos(TData a, int i, TPers reg){
  if(i>=a.cant){
    return i;
  } else {
    if(!compararElementos(a.p[i],reg)){
        return buscarPos(a,i+1,reg);
    } else {
        return i;
    }
  }
}
void mantenerOrden(TData *a){
 int i,j;
 TPers aux;
    if((*a).cant>1){
        for(i=a->cant-1;i>0;i--){
            for(j=0;j<i;j++){
                if((compararElementos(a->p[j],a->p[j+1]))){
                    aux = (*a).p[j];
                    (*a).p[j]=(*a).p[j+1];
                    (*a).p[j+1]=aux;
                }
            }    
        }
    }
}
void suprimir(TData *a, int pos){
   int i;
   TPers aux;
     for(i=pos;i<(*a).cant;i++){
         (*a).p[i] = (*a).p[i+1];
     }
     a->cant=a->cant-1;
   }
bool repetido(TData a, int dni){
	int i;
	bool cond;
	cond=false;
	for(i=0;i<a.cant;i++){
		if(a.p[i].dni==dni){
			cond=true;
		}
	}
	return cond;
}
bool llena(TData a){
    return a.cant==NMax;
}
bool vacia(TData a){
    return a.cant==0;
}
void modificar(TData *a,int pos){
    int opcion;
    do{
         printf("1. Nombre\n2. Apellido\n3. Fecha de Nacimiento\n4. Ciudad de residencia \n5. Direccion Postal\n6. Correo electronico\n7. Numero telefonico\n8. Fallecimiento\n9. Fecha de fallecimiento\n10. Numero benefico\n11. Direccion postal\n12. Nueva provincia\n13. Provincia antes de la guerra\n14. Fuerza\n15. Destino\n16. Funcion\n17. Grado\n18. Secuelas\n"); 
    printf("Seleccione la opcion que desea modificar:\n"); scanf("%d",&opcion);
    if(opcion==1){
        printf("Ingrese el nuevo nombre: "); scanf("%s", a->p[pos].nombre);
    } else {
        if(opcion==2){
             printf("Ingrese el nuevo apellido: "); scanf("%s", a->p[pos].apellido);
        } else {
            if(opcion==3){
                printf("Ingrese la fecha de nacimiento modificada:\n");
                obtenerFecha(&a->p[pos].nacimiento);
                a->p[pos].edad=edad(a->p[pos].nacimiento, fechaActual);
            } else {
                if(opcion==4){
                    printf("Ingrese la nueva ciudad de residencia: "); scanf("%s", a->p[pos].ciudad);
                } else {
                    if(opcion==5){
                        printf("Ingrese el nuevo codigo postal a registrar: "); scanf("%s", a->p[pos].CP);
                    } else {
                        if(opcion==6){
                             printf("Ingrese el nuevo correo electronico a registrar: "); scanf("%s", a->p[pos].CE);
                        } else {
                            if(opcion==7){
                                printf("Ingrese el nuevo numero telefonico a registrar: "); scanf("%s", a->p[pos].telefono);
                            } else {
                                if(opcion==8){
                                    printf("Ingrese si actualmente la persona esta viva: "); scanf("%d",&a->p[pos].VF);
                                    if(!a->p[pos].VF){
                                        printf("Ingrese los datos de fallecimiento modificados a registrar:\n");
                                        obtenerFecha(&a->p[pos].fallecimiento);
                                    }
                                    } else {
                                    if(opcion==9){
                                        printf("Ingrese los datos de fallecimiento a registrar:\n");
                                        obtenerFecha(&a->p[pos].fallecimiento);
                                    } else {
                                        if(opcion==10){
                                            printf("Ingrese el nuevo numero beneficio a registrar "); scanf("%s",a->p[pos].beneficio);
                                        } else {
                                            if(opcion==11){
                                                printf("Ingrese la nueva direccion postal a registrar "); scanf("%s",a->p[pos].DP);
                                            } else {
                                                if(opcion==12){
                                                    printf("Ingrese la nueva provincia actual a registrar: "); scanf("%s",a->p[pos].ciudad);
                                            } else {
                                                if(opcion==13){
                                                    printf("Ingrese la provincia antes de la guerra a registrar: "); scanf("%s",a->p[pos].ciudadAntes);
                                                } else {
                                                    if(opcion==14){
                                                        do{
                                                        printf("Ingrese la fuerza a la que pertenecia en la guerra: \n");  printf("1. Marina\n2. Gendarmeria\n3. Ejercito\n4. Aeronautica\n"); printf("Ingrese la opcion deseada: ");scanf("%d",&a->p[pos].fuerza);
                                                        }while(!(a->p[pos].fuerza>0 && a->p[pos].fuerza<5 ));
                                                    } else {
                                                        if(opcion==15){
                                                            printf("Ingrese el nuevo destino en malvinas para registrar: "); scanf("%s",a->p[pos].destino);
                                                        } else {
                                                            if(opcion==16){
                                                                printf("Ingrese la funcion en malvinas para registrar: "); scanf("%s",a->p[pos].funcion);
                                                            } else {
                                                                if(opcion==17){
                                                                     printf("Ingrese el grado en malvinas para registrar: "); printf("1. Marina\n2. Gendarmeria\n3. Ejército\n4. Aeronáutica"); scanf("%s",a->p[pos].grado);
                                                                } else {
                                                                    if(opcion==18){
                                                                        printf("Ingrese las secuelas de malvinas para registrar: "); scanf("%s",a->p[pos].secuelas);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                          }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
        
            }
        }
    }
  }while(!(opcion>0 && opcion<19));
  printf("Registro modificado:\n");
  mostrarReg(a->p[pos]);
  if(opcion==1 || opcion==2){
    mantenerOrden(a);
  }
}
void mostrar(TData a){
    int i;
    for(i=0;i<a.cant;i++){
        mostrarReg(a.p[i]);
    }
}
void mostrarReg(TPers reg){
	printf("Datos del empleado:\n");
    printf("Nombre y apellido: %s %s\n",reg.nombre,reg.apellido);
    printf("DNI:%d\n",reg.dni);
    printf("Fecha de nacimiento:%d/%d/%d\n",reg.nacimiento.anio,reg.nacimiento.mes,reg.nacimiento.dia);
    printf("Edad:%d\n",reg.edad);
    printf("Ciudad:%s\n",reg.ciudad);
    printf("Codigo postal:%s\n",reg.CP);
    printf("Telefono: %s\n",reg.telefono);
    printf("Correo:%s\n",reg.CE);
    if(!reg.VF){
      printf("Fecha de fallecimiento:%d/%d/%d\n",reg.fallecimiento.anio,reg.fallecimiento.mes,reg.fallecimiento.dia);    
    }
   }  
void inicializarLSE(TFallecido **list){
  TFallecido *r;
    (*list)=NULL;
    r = (TFallecido *) malloc(sizeof(TFallecido));
    r->next=(*list);
    (*list)=r;
}
void insertarCabecera(TFallecido **list,TPers reg){
  TFallecido *r;
    r = (TFallecido *) malloc(sizeof(TFallecido));
    r->info=reg;
    r->next=(*list)->next;
    (*list)->next=r;
}
void listaFallecidos(TFallecido **list,TData a){
  TFallecido *r;
  int i;
    r = (TFallecido *) malloc(sizeof(TFallecido));
    for(i=0;i<a.cant;i++){
        if(!a.p[i].VF){
            insertarCabecera(&(*list),a.p[i]);
        }
    }
}
void mostrarLSE(TFallecido *list){
    TFallecido *aux;
    aux = list->next;
    printf("\n");
    while(aux!=NULL){
    printf("Nombre y apellido:%s %s\n",aux->info.nombre, aux->info.apellido);
    printf("Documento: %d",aux->info.dni);
    printf("Fecha de fallecimiento: %d/%d/%d\n",aux->info.fallecimiento.dia,aux->info.fallecimiento.mes,aux->info.fallecimiento.anio);
    printf("Ciudad de residencia: %s",aux->info.ciudad);
    aux = aux->next;
    }
}
void mostrarApellido(TData a, char ap[20]){
  int i;
  i = 0;
  while(i<=a.cant && ((strcmp(a.p[i].apellido,ap))!=0)){
    i++;
  }
  if(i<=a.cant){
    while(i<=a.cant && (strcmp(a.p[i].apellido,ap)==0)){
        mostrarReg(a.p[i]);
        i++;
    } 
    } else {
    printf("El apellido no fue encontrado en el registro\n");
  }
}
void mostrarCumpleaños(TData b, int mes){
 int i;
 TData a;
 a.cant=0;
 for(i=0;i<b.cant;i++){
  if(b.p[i].nacimiento.mes==mes){
    a.p[i]=b.p[i];
    a.cant++;
  }
 }
 if(a.cant>1){
    ordenarDia(&a);
 }
 for(i=0;i<a.cant;i++){
    printf("Nombre y apellido: %s %s\n",a.p[i].nombre,a.p[i].apellido);
    printf("Fecha de nacimiento: %d/%d/%d\n",a.p[i].nacimiento.dia,a.p[i].nacimiento.mes,a.p[i].nacimiento.anio);
    printf("Edad: %d\n",a.p[i].edad);
    printf("Direccion postal: %s \n",a.p[i].DP);
    printf("Correo electronico: %s\n",a.p[i].CE);
    if(a.p[i].VF){
        printf("La persona que cumple años vive\n");
    } else {
        printf("La persona que cumplia años fallecio\n");
    }
 }
}
void ordenarDia(TData *a){
 int i,j;
 TPers aux;
    if(a->cant>1){
        for(i=a->cant-1;i>0;i--){
          for(j=0;j<i;j++){
                if(a->p[j].nacimiento.dia>a->p[j+1].nacimiento.dia){
                    aux = a->p[j];
                    a->p[j]=a->p[j+1];
                    a->p[j+1]=aux;
                }
           }    
        }
    }
}
void inicializarLDE(TFuerza **pri, TFuerza **ult){
    TFuerza *r;
    (*pri)=NULL;
    (*ult)=NULL;
    r = (TFuerza *) malloc(sizeof(TFuerza));
    r->next=(*pri);
    r->back=(*pri);
    (*pri) = r;
    r = (TFuerza *) malloc(sizeof(TFuerza));
    r->next=(*ult);
    r->back=(*pri);
    (*ult) = r;
    (*pri)->next=(*ult);
}
void insertarLDE(TFuerza **pri, TFuerza **ult, TData a){
  TFuerza *r, *aux;
  int i; bool pos;
  int fuerza;
  aux = (*pri);
  do{
  printf("\n1. Marina\n2. Gendarmeria\n3. Ejercito\n4. Aeronautica\n");
  printf("Ingrese de que fuerza quiere que sea la lista a generar: ");scanf("%d",&fuerza);
  }while(!(fuerza>0 && fuerza<5));
   for(i=0;i<a.cant;i++){
       if(a.p[i].fuerza==fuerza){
               aux = (*pri);
                pos = false;
               while(aux->next!=(*ult) && !pos){
                if(!(compararElementos(a.p[i],aux->info))){
                    pos = true;
                }
                aux = aux->next;
               }
               r = (TFuerza *) malloc(sizeof(TFuerza));
               if(aux->next==(*ult)){
               r->info = a.p[i];
               r->next = aux->next;
               r->back=aux;
               aux->next->back=r;
               aux->next=r;
               } else {
               r->next = aux;
               r->back=aux->back;
               aux->back->next=r;
               aux->back=r;
               }
       }
   }
}
void limpiarLSE(TFallecido **q){
    TFallecido *aux,*r;
    aux = (*q)->next;
    while(aux!=NULL){
        r=aux;
        aux=aux->next;
        free(r);
    }
    (*q)->next=NULL;
}
void limpiarLDE(TFuerza **pri, TFuerza **ult){
    TFuerza *aux,*r;
    aux = (*pri)->next;
    while(aux->next!=NULL){
        r=aux;
        aux=aux->next;
        free(r);
    }
    (*pri)->next=(*ult);
    (*ult)->back=(*pri);
}
void mostrarLDE(TFuerza *pri, TFuerza *ult){
  TFuerza *aux;
     aux = pri->next;
     if(aux->next==NULL){
        printf("No se han encontrado soldados de esta fuerza\n");
     } else {
        printf("Los soldados pertenecientes a esta fuerza son: \n");
     }
     while(aux->next!=NULL){
     printf("%s %s\n",aux->info.apellido, aux->info.nombre);
    aux = aux->next;
     }
}