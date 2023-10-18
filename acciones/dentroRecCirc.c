#include <stdiobool.h>
#include <stdio.h>
struct TPunto{
    float x;
    float y;
};
struct TPunto a,b,c,f;
float r;
float ci, re;
void obtenerPunto(struct TPunto *d);
void obtenerPuntosCirc(struct TPunto *e, float *radio);
void dentroCirculo(struct TPunto e, struct TPunto c, float radio, float *circ);
void dentroRec(struct TPunto d,e,h, float *rec);
void dondeEsta (float circ, float rec);
void main(){
    obtenerPunto(&a); // vertice opuesto del rectangulo
    obtenerPunto(&b); // vertice inferior del rectangulo
    obtenerPunto(&c); // puntos a analizar
    obtenerPuntosCirc(&f,&r); // punto del centro del circulo y radio
    dentroRec(a,b,c,&re); // variable para analizar si esta dentro rectangulo
    dentroCirculo(f,r,&ci);
    dondeEsta(re,ci);
}

void obtenerPunto(struct TPunto *d){
    scanf("%f", &(*d).x);
    scanf("%f", &(*d).y);
}
void obtenerPuntosCirc(struct TPunto *e, float *radio){
    scanf("%f", &(*e).x);
    scanf("%f", &(*e).y);
    scanf("%f", &(*radio));
}
void dentroCirculo(struct TPunto e, struct TPunto c, float radio, float *circ){
    float diam;
    diam = sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
    if(diam<=radio){
        *circ=1;
    } else {
        *circ=0;
    }
}
void dentroRec(struct TPunto d,e,h, float *rec){
    if(d.x>=h.x && e.x<=h.x)&&(d.y>=h.y && e.y<=h.y){
        *rec=1;
    } else {
        *rec=0;
    }
}
void dondeEsta (float circ, float rec){
    if(circ==1 && rec==1){
        printf("Esta en el circulo y en el rectangulo \n");
    } else {
        if(circ==1 && rec==0){
        printf("Esta en el circulo\n");
        } else {
            if(circ==0 && rec==1){
        printf("Esta en el rectangulo\n");
        } else {
            if(circ==0 && rec==0){
        printf("No esta en el rectangulo ni en el circulo \n");
        }
       }
      }
    }
}