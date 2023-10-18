#include <stdio.h>
#include <string.h>
struct TCortina {
    int precio;
    char tipo;
};
int precioFinal;
struct TCortina cortina1, cortina2, cortina3;

void obtenerCortina(struct TCortina *e){
printf("Ingrese el precio de la cortina: \n");
scanf("%d", &(*e).precio);
printf("Ingrese el tipo de la cortina: \n");
scanf(" %c", &(*e).tipo);
}
void precio (struct TCortina a, struct TCortina b, struct TCortina c, int *res){
    if((a.tipo == b.tipo) && (b.tipo == c.tipo)){
        *res = (a.precio + b.precio + (c.precio * 0.70));
    } else {
        *res = a.precio + b.precio + c.precio;
    }

}
void main(){
    obtenerCortina(&cortina1);
    obtenerCortina(&cortina2);
    obtenerCortina(&cortina3);
    precio(cortina1,cortina2,cortina3,&precioFinal);
        printf("El valor de la cortina es de %d", precioFinal);
}