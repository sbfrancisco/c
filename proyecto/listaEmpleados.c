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
    char nombre[50];
    char apellido[50];
    TFecha fechaNacimiento;
    int edad;
    char ciudad[50];
    char cp[50];
    char telefono[50];
    char correo[50];
    int vive;
    TFecha fechaFallecimiento;
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
}TCiudad;
TCiudad *localidadPri, *localidadUlt;
TFallecido *fallecidos;
TFecha fechaActual;
TData personas;
TPers persona;
int opcion,valido, dni, pos, opmenu;
bool l,v,d;
TPers datos;
bool bisiesto(int a);
int dias(TFecha a);
int edad(TFecha a, TFecha b);
int posicion(TData a, int b);
void insertar(TData *a, TPers b);
void suprimir(TData *a, int pos);
bool repetido(TData a, int dni);
bool llena(TData a);
bool vacia(TData a);
void modificar(TData *a,int pos);
void mostrar(TData a);
void obtenerFecha(TFecha *a);
void inicializarLSE(TFallecido **list);
void insertarCabecera(TFallecido **list, TPers reg);
void listaFallecidos(TFallecido **list, TData a);
void mostrarLSE(TFallecido *list);
void inicializarLDE(TCiudad **pri, TCiudad **ult);
void insertarLDE(TCiudad **pri, TCiudad **ult, TData a);
void mostrarLDE(TCiudad *pri, TCiudad *ult, int opcion);
void limpiarLSE(TFallecido **q);
void limpiarLDE(TCiudad **pri, TCiudad **ult);
void main(){
  personas.cant=0;
  fallecidos=NULL;
  localidadPri=NULL;
  localidadUlt=NULL;
  inicializarLDE(&localidadPri, &localidadUlt);
  inicializarLSE(&fallecidos);
  printf("Ingrese los datos de la fecha actual\n");
  obtenerFecha(&fechaActual);
 do{
   printf("\n\n\t\t\tMENU PRINCIPAL\n");
   printf("\t\t\t--------------\n");
   printf("1. Alta de persona\n");
   printf("2. Baja de persona\n");
   printf("3. Mostrar los empleados registrados\n");
   printf("4. Modificar empleado\n");
   printf("5. Listar empleados fallecidos\n");
   printf("6. Listar empleados por localidad\n");
   printf("7. Salir\n");
   printf("\nIngrese la opcion: ");
   scanf("%d", &opcion);
    if(opcion==1){ 
     l=llena(personas);
       if(!l){
        do{
		printf("Ingrese el DNI de la persona a ingresar:\n"); scanf("%d",&persona.dni);
		d=repetido(personas,persona.dni);
		}while(d);
        printf("Ingrese el nombre de la persona a ingresar:\n"); scanf("%s",persona.nombre);
		printf("Ingrese el apellido de la persona a ingresar:\n"); scanf("%s",persona.apellido);
		do{
		  printf("Ingrese los datos de nacimiento de la persona a ingresar:\n");
		  obtenerFecha(&persona.fechaNacimiento);
		valido= edad(persona.fechaNacimiento,fechaActual);
		}while(valido<0);
       persona.edad= valido;
       printf("Ingrese la ciudad de la persona a ingresar:\n"); scanf("%s",persona.ciudad);
       printf("Ingrese el codigo postal de la ciudad de la persona a ingresar:\n"); scanf("%s",persona.cp);
       printf("Ingrese el telefono de la persona a ingresar:\n"); scanf("%s",persona.telefono);
       printf("Ingrese el correo de la persona a ingresar:\n"); scanf("%s",persona.correo);
	   do{
       printf("Ingrese si actualmente la persona esta viva:\n"); scanf("%d",&persona.vive); // 1 si, 0 no
	   }while(persona.vive!=0 && persona.vive!=1);
		if(persona.vive==0){
			printf("Ingrese los datos de fallecimiento de la persona a ingresar:\n");
			obtenerFecha(&persona.fechaFallecimiento);
		}
         insertar(&personas,persona);
        } else {
          printf("La lista esta llena\n");
        }
    } else {
        if(opcion==2){
			v=vacia(personas);
			if(v){
				printf("La lista de personas esta vacia\n");
			} else {
			    printf("Ingrese el documento de la persona a eliminar: "); scanf("%d", &dni);
                pos = posicion(personas,dni);
                if(pos<0){
                    printf("La posicion ingresada es invalida\n");
                } else {
				suprimir(&personas,pos);
				printf("El empleado fue suprimido\n");
			}
			}
        } else {
            if(opcion==3){
				if(personas.cant>0){
				  printf("Los empleados registrados son: \n");
				  mostrar(personas);
				} else {
					printf("La lista esta vacia\n");
				}
            } else {
                if(opcion==4){
                  printf("Ingrese el documento de la persona a modificar: "); scanf("%d", &dni);
                  pos = posicion(personas,dni);
                    if(pos<0){
                     printf("La posicion ingresada es invalida\n");
                    } else {
                    modificar(&personas,pos);
                    }
                } else {
                    if(opcion==5){
                        listaFallecidos(&fallecidos,personas);
                        mostrarLSE(fallecidos);
                        limpiarLSE(&fallecidos);
                    } else {
                        if(opcion==6){
                        insertarLDE(&localidadPri,&localidadUlt,personas);
                        do{
                            printf("1. Mostrar en forma descendiente segun su dni\n");
                            printf("2. Mostrar en forma ascendiente segun su dni\n");
                            printf("Ingrese como desea ver la lista:"); scanf("%d",&opmenu);
                        }while(opmenu==0 && opmenu==1);
                        mostrarLDE(localidadPri,localidadUlt,opmenu);
                        }
                        limpiarLDE(&localidadPri,&localidadUlt);
                    }
                }    
            }
        }
    }
}while(opcion>0 && opcion<7);
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
 int posicion(TData a, int b){
   int i;
    for(i=0;i<a.cant;i++){
        if(a.p[i].dni==b){
            return i;
        }
    }
    return -1;
 }
 void insertar(TData *a, TPers b){
  int i,j;
  TPers aux;
   i = (*a).cant;
   (*a).p[i]=b;
   (*a).cant++;
    if((*a).cant>1){
        for(i=0;i<(*a).cant;i++){
            for(j=0;j<(*a).cant-1;j++){
                if((strcmp((*a).p[j].apellido,(*a).p[j+1].apellido)>0) || ((strcmp((*a).p[j].apellido,(*a).p[j+1].apellido)==0) && (strcmp((*a).p[j].nombre,(*a).p[j+1].nombre)>0)) || (strcmp((*a).p[j].apellido,(*a).p[j+1].apellido)==0) && (strcmp((*a).p[j].nombre,(*a).p[j+1].nombre)>=0) && ((*a).p[j].dni > (*a).p[j+1].dni)){
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
         printf("1. Nombre\n2. Apellido\n3. Fecha de Nacimiento\n4. Ciudad de residencia \n5. Direccion Postal\n6. Correo electronico\n7. Numero telefonico\n8. Fallecimiento\n9. Fecha de fallecimiento\n"); 
    printf("Seleccione la opcion que desea modificar:\n"); scanf("%d",&opcion);
    if(opcion==1){
        printf("Ingrese el nuevo nombre: "); scanf("%s", a->p[pos].nombre);
    } else {
        if(opcion==2){
             printf("Ingrese el nuevo apellido: "); scanf("%s", a->p[pos].apellido);
        } else {
            if(opcion==3){
                printf("Ingrese la fecha de nacimiento modificada:\n");
                obtenerFecha(&a->p[pos].fechaNacimiento);
                a->p[pos].edad=edad(a->p[pos].fechaNacimiento, fechaActual);
            } else {
                if(opcion==4){
                    printf("Ingrese la nueva ciudad de residencia: "); scanf("%s", a->p[pos].ciudad);
                } else {
                    if(opcion==5){
                        printf("Ingrese el nuevo codigo postal: "); scanf("%s", a->p[pos].cp);
                    } else {
                        if(opcion==6){
                             printf("Ingrese el nuevo correo electronico: "); scanf("%s", a->p[pos].correo);
                        } else {
                            if(opcion==7){
                                printf("Ingrese el nuevo numero telefonico: "); scanf("%s", a->p[pos].telefono);
                            } else {
                                if(opcion==8){
                                    printf("Ingrese si actualmente la persona esta viva: "); scanf("%d",&a->p[pos].vive);
                                    if(a->p[pos].vive==0){
                                        printf("Ingrese los datos de fallecimiento:\n");
                                        obtenerFecha(&a->p[pos].fechaFallecimiento);
                                    }
                                } else {
                                    if(opcion==9){
                                        printf("Ingrese los datos de fallecimiento:\n");
                                        obtenerFecha(&a->p[pos].fechaFallecimiento);
                                    }
                                }
                            }
                    }
                }
            }
        
        }
    }
}
}while(!(opcion>0 && opcion<10));
}

void mostrar(TData a){
  int i;
   for(i=0;i<a.cant;i++){
	printf("Datos del empleado %d:\n",i);
    printf("Nombre y apellido: %s %s\n",a.p[i].nombre,a.p[i].apellido);
    printf("DNI:%d\n",a.p[i].dni);
    printf("Fecha de nacimiento:%d/%d/%d\n",a.p[i].fechaNacimiento.anio,a.p[i].fechaNacimiento.mes,a.p[i].fechaNacimiento.dia);
    printf("Edad:%d\n",a.p[i].edad);
    printf("Ciudad:%s\n",a.p[i].ciudad);
    printf("Codigo postal:%s\n",a.p[i].cp);
    printf("Telefono: %s\n",a.p[i].telefono);
    printf("Correo:%s\n",a.p[i].correo);
    if(a.p[i].vive==0){
      printf("Fecha de fallecimiento:%d/%d/%d\n",a.p[i].fechaFallecimiento.anio,a.p[i].fechaFallecimiento.mes,a.p[i].fechaFallecimiento.dia);    
    }
   }  
}
void inicializarLSE(TFallecido **list){
  TFallecido *r;
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
        if(a.p[i].vive==0){
            insertarCabecera(&(*list),a.p[i]);
        }
    }
}
void mostrarLSE(TFallecido *list){
    TFallecido *aux;
    aux = list->next;
    printf("\n");
    while(aux!=NULL){
    printf("Nombre y apellido: %s %s\n",aux->info.nombre,aux->info.apellido);
    printf("DNI:%d\n",aux->info.dni);
    printf("Fecha de nacimiento:%d/%d/%d\n",aux->info.fechaNacimiento.anio,aux->info.fechaNacimiento.mes,aux->info.fechaNacimiento.dia);
    printf("Edad:%d\n",aux->info.edad);
    printf("Ciudad:%s\n",aux->info.ciudad);
    printf("Codigo postal:%s\n",aux->info.cp);
    printf("Telefono: %s\n",aux->info.telefono);
    printf("Correo:%s\n",aux->info.correo);
    printf("Fecha de fallecimiento:%d/%d/%d\n",aux->info.fechaFallecimiento.anio,aux->info.fechaFallecimiento.mes,aux->info.fechaFallecimiento.dia); 
    aux = aux->next;
    }
}
void inicializarLDE(TCiudad **pri, TCiudad **ult){
    TCiudad *r;
    r = (TCiudad *) malloc(sizeof(TCiudad));
    r->next=(*pri);
    r->back=(*pri);
    (*pri) = r;
    r = (TCiudad *) malloc(sizeof(TCiudad));
    r->next=(*ult);
    r->back=(*pri);
    (*ult) = r;
    (*pri)->next=(*ult);
}
void insertarLDE(TCiudad **pri, TCiudad **ult, TData a){
  TCiudad *r, *aux;
  int i;
  char ciudad[50];
  printf("Ingrese la ciudad para generar la lista: ");scanf("%s",ciudad);
   for(i=0;i<a.cant;i++){
       if(strcmp(a.p[i].ciudad,ciudad)==0){
           if((*pri)->next==(*ult)){
              r = (TCiudad *) malloc(sizeof(TCiudad));
              r->info=a.p[i];
              r->next=(*ult);
              r->back=(*pri);
              (*pri)->next=r;
              (*ult)->back=r;
           } else {
               aux = (*pri)->next;
               while(aux->next!=NULL && a.p[i].dni>aux->info.dni){
                   aux = aux->next;
               }
               r = (TCiudad *) malloc(sizeof(TCiudad));
               r->info = a.p[i];
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
void limpiarLDE(TCiudad **pri, TCiudad **ult){
    TCiudad *aux,*r;
    aux = (*pri)->next;
    while(aux->next!=NULL){
        r=aux;
        aux=aux->next;
        free(r);
    }
    (*pri)->next=(*ult);
    (*ult)->back=(*pri);
}
void mostrarLDE(TCiudad *pri, TCiudad *ult, int opcion){
  TCiudad *aux;
    if(opcion==1){
     aux = pri->next;
     while(aux->next!=NULL){
     printf("Nombre y apellido: %s %s\n",aux->info.nombre,aux->info.apellido);
     printf("DNI:%d\n",aux->info.dni);
     printf("Fecha de nacimiento:%d/%d/%d\n",aux->info.fechaNacimiento.anio,aux->info.fechaNacimiento.mes,aux->info.fechaNacimiento.dia);
     printf("Edad:%d\n",aux->info.edad);
     printf("Ciudad:%s\n",aux->info.ciudad);
     printf("Codigo postal:%s\n",aux->info.cp);
     printf("Telefono: %s\n",aux->info.telefono);
     printf("Correo:%s\n",aux->info.correo);
      if(aux->info.vive==0){
       printf("Fecha de fallecimiento:%d/%d/%d\n",aux->info.fechaFallecimiento.anio,aux->info.fechaFallecimiento.mes,aux->info.fechaFallecimiento.dia); 
      }
    aux = aux->next;
     }
    } else {
     aux = ult->back;
     while(aux->back!=NULL){
     printf("Nombre y apellido: %s %s\n",aux->info.nombre,aux->info.apellido);
     printf("DNI:%d\n",aux->info.dni);
     printf("Fecha de nacimiento:%d/%d/%d\n",aux->info.fechaNacimiento.anio,aux->info.fechaNacimiento.mes,aux->info.fechaNacimiento.dia);
     printf("Edad:%d\n",aux->info.edad);
     printf("Ciudad:%s\n",aux->info.ciudad);
     printf("Codigo postal:%s\n",aux->info.cp);
     printf("Telefono: %s\n",aux->info.telefono);
     printf("Correo:%s\n",aux->info.correo);
      if(aux->info.vive==0){
       printf("Fecha de fallecimiento:%d/%d/%d\n",aux->info.fechaFallecimiento.anio,aux->info.fechaFallecimiento.mes,aux->info.fechaFallecimiento.dia); 
      }
      aux = aux->back;
     }
    }
}