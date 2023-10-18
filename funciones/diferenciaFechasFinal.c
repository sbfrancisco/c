 #include <stdbool.h>
#include <stdio.h>
struct TFecha{
    int dia;
    int mes;
    int año;
};
bool bisiesto (struct TFecha a);
int cantDias (struct TFecha a);
int sumaAño (struct TFecha a, struct TFecha b);
int sumaMes (struct TFecha a, struct TFecha b);
int sumaDias (struct TFecha b, struct TFecha a);
int diasPasados, diasPasados2, diasPasados3;
struct TFecha c,d;
void main(){
    printf("Ingrese el dia de su primer fecha: \n");
    scanf("%d", &c.dia);
    printf("Ingrese el mes de su primer fecha: \n");
    scanf("%d", &c.mes);
    printf("Ingrese el a%co de su primer fecha: \n", 164);
    scanf("%d", &c.año);
    printf("Ingrese el dia de su segunda fecha: \n");
    scanf("%d", &d.dia);
    printf("Ingrese el mes de su segunda fecha: \n");
    scanf("%d", &d.mes);
    printf("Ingrese el a%co de su segunda fecha: \n", 164);
    scanf("%d", &d.año);
    diasPasados =sumaAño(c,d) + sumaMes(c,d) + sumaDias(c,d);
    if(diasPasados<0){
    diasPasados = diasPasados*-1;
    }
    printf("La diferencia de la fecha %d/%d/%d y %d/%d/%d es de %d \n", c.dia, c.mes, c.año, d.dia, d.mes, d.año, diasPasados);
} 

bool bisiesto (struct TFecha a){
    return ((a.año%4==0 && a.año%100!=0) || (a.año%100==0 && a.año%400==0));
}

int cantDias (struct TFecha a){
    if(a.mes==1 || a.mes==3 || a.mes==5 || a.mes==7 || a.mes==8 || a.mes==10 || a.mes==12){
        return 31;
    } else {
        if(a.mes==4 || a.mes==6 || a.mes==9 || a.mes==11){
            return 30;
        } else {
            if(a.mes==2 && bisiesto(a)){
                return 29;
            } else {
                if(a.mes==2){
                    return 28;
                }
            }
        }
    }
 }

int sumaAño (struct TFecha a, struct TFecha b){
    int diasA;
    diasA = 0;
    if(b.año>=a.año){
    a.año++;
    while(b.año>=a.año){
        if(bisiesto(a)){
            diasA = diasA + 366;
        } else {
            diasA = diasA + 365;
        }
        a.año++;
    }
    } else {
        if(b.año<=a.año){
            a.año--;
            while(b.año<=a.año){
            if(bisiesto(a)){
            diasA = diasA - 366;
            } else {
            diasA = diasA - 365;
            }
            a.año--;
        }
    }
}
    return diasA;
}

int sumaMes (struct TFecha a, struct TFecha b){
    int diasM;
    diasM=0;
    if(b.mes>=a.mes){
        a.mes++;
    while(b.mes>=a.mes){
        diasM = diasM + cantDias(a);
        a.mes++;
    }
    } else {
    if(b.mes<a.mes){
    a.mes--;
    while(b.mes<=a.mes){
        diasM = diasM - cantDias(a);
        a.mes--;
    }
    }
    }
    return diasM;
}

int sumaDias (struct TFecha b, struct TFecha a){ 
    int diasD;
    diasD = 0;
    diasD = diasD + (cantDias(b) - b.dia);
    diasD = diasD - (cantDias(a) - a.dia);
    return diasD;
}