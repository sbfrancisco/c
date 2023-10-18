#include <stdio.h>
#include <string.h>
struct TAngulo {
    int grado;
    int min;
    int seg;
};  

struct TAngulo sumaAngulo (struct TAngulo c, struct TAngulo d);
struct TAngulo a,b,f,g,h;
char mensaje[35];
void main(){
    printf("Ingrese los grados de su primer angulo: \n");
    scanf("%d", &a.grado);
    do{
    printf("Ingrese los minutos de su primer angulo: \n");
    scanf("%d", &a.min);
    }while(a.min<0 || a.min>=59);
        do{
    printf("Ingrese los segundos de su primer angulo: \n");
    scanf("%d", &a.seg);
    }while(a.seg<0 || a.seg>=59);

    printf("Ingrese los grados de su segundo angulo: \n");
    scanf("%d", &b.grado);
    do{
    printf("Ingrese los minutos de su segundo angulo: \n");
    scanf("%d", &b.min);
    }while(b.min<0 || b.min>=59);
    do{
    printf("Ingrese los segundos de su segundo angulo: \n");
    scanf("%d", &b.seg);
    }while(b.seg<0 || b.seg>=59);
    printf("Ingrese los grados de su tercer angulo: \n");
    scanf("%d", &f.grado);
    do{
    printf("Ingrese los minutos de su tercer angulo: \n");
    scanf("%d", &f.min);
    }while(f.min<0 || f.min>=59);
        do{
    printf("Ingrese los segundos de su tercer angulo: \n");
    scanf("%d", &f.seg);
     }while(f.seg<0 || f.seg>=59);

    g= sumaAngulo(a,b);
    h= sumaAngulo(g,f);
        if(h.grado==180 && g.min==0 && g.seg==0){
            strcpy(mensaje, "La suma de los angulos es 180°");
        } else {
            strcpy(mensaje, "La suma de los angulos no es 180°");
        }
        printf("%s ", mensaje);
}

struct TAngulo sumaAngulo (struct TAngulo c, struct TAngulo d){
  struct TAngulo e;
   
    e.seg = (c.seg + d.seg)%60;
    e.min= ((c.seg + d.seg)/60)+((c.min+d.min)%60);
    e.grado = ((c.min + d.min)/60) + (c.grado+d.grado);
    return e;
}