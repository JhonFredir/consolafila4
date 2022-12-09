#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/*
Autores
Jhon Riascos
Luisa cardenas
Cristian Alvarado
Daniel Ramirez Restrepo
*/
int contador;

int main(int ac, char **argv)
{

  char *prompt = "(Eshell) $ ";
  printf("%s", prompt);

  char *lineptr;
  size_t n = 0;

  char *path = getenv("PATH");

  char route[200] = "";

  (void)ac;
  (void)argv;

  getline(&lineptr, &n, stdin);

  char *token = strtok(path, ":");

  contador = 0;
  while (token != NULL)
  {

    strcat(route, token);
    strcat(route, "/");
    strcat(route, lineptr);          // lineptr es el comando
    route[strcspn(route, "\n")] = 0; // eliminando el salto de linea que se tiene del getline.

    execve(route, argv, NULL);

    contador = contador + 1;
    token = strtok(NULL, ":");
    memset(route, 0, 200);
  }
  free(lineptr); 
  // consulta es necesario liberar las variables si el proceso principal se cierra por execve
  
  
  printf("%d\n", contador);


  return 0;
}