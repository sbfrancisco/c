#include <string.h>
#include <stdio.h>
char resp1[30];
char resp2[30];
char resp3[30];
int puntosObtenidos, i;
void
main ()
{
  printf("Ingrese la primera respuesta que considere correcta el concursante:");
  fgets (resp1, 30, stdin);
  int longitud0 = strlen (resp1);
  resp1[longitud0 - 1] = '\0';
  fflush (stdin);
  
  printf("Ingrese la segunda respuesta que considere correcta el concursante:");
  fgets (resp2, 30, stdin);
  int longitud1 = strlen (resp2);
  resp2[longitud1 - 1] = '\0';
  fflush (stdin);
  printf("Ingrese la tercer respuesta que considere correcta el concursante:");
  fgets(resp3, 30, stdin);
  int longitud2 = strlen (resp3);
  resp3[longitud2 - 1] = '\0';
  fflush (stdin);
  if (strcmp (resp1, "Donatello") == 0)
    {
      puntosObtenidos = puntosObtenidos + 100;
      i = i + 1;
    }
        if (strcmp (resp2, "La piedad") == 0){
             puntosObtenidos = puntosObtenidos + 100;
             i = i + 1;
        }
                if (strcmp (resp3, "Rafael") == 0){
	            
	              puntosObtenidos = puntosObtenidos + 100;
	                 i = i + 1;
	}
  printf ("El concursante respondio %d preguntas correctamente, por lo cual suma %d",
     i, puntosObtenidos);
}
