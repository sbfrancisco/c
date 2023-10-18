// Francisco Natale
#include <string.h>
#include <stdio.h>
int esMayuscula(char c);
char aMinuscula(char c);
int esVocal(char c);
int esConsonante(char c);
// perfiles de funciones
char carac;
char mensaje[50];
// lexico
int main(){
    printf("Ingrese el caracter a analizar: \n");
    scanf("%c", &carac);
    if(esConsonante(carac)){
        strcpy(mensaje, "Este caracter es una consonante\n");
    }else{
      if(esVocal(carac)){
        strcpy(mensaje, "Este caracter es una vocal\n");
      }else{
        strcpy(mensaje, "Este caracter no es ni consonante, ni vocal\n");
          }
        }
    printf("%s", mensaje);
}

// funciones
int esMayuscula(char c){
 return ((c >= 'A') && (c <= 'Z'));
}

char aMinuscula(char c){
return (c + ('a'-'A'));
}

int esVocal(char c){
char a; // lexico local
    if(esMayuscula(c)){
      a = aMinuscula(c);
    } else{
      a = c;
    }
  return ((a == 'a')||a == 'e') ||(a == 'i')||(a == 'o')||(a == 'u');
}
int esConsonante(char c){
char a; 
    if (esMayuscula(c)){
      a = aMinuscula(c);
    }else{
      a = c;
    }
  return (((a >= 'a') && (a <= 'z')) && (!(esVocal(a))));
}