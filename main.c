#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.c"





int main(){
	
	token tokenActual;

	do{
	
	tokenActual=scanner();
	printf("%s \n", nombreToken(tokenActual));
	
	
	}while(tokenActual!=4);



	
/*
  char caracterLeido2, caracterLeido3;
caracterLeido2 = (char) getchar();
printf("Lei: %c \n", caracterLeido2);

ungetc(caracterLeido2,stdin);

caracterLeido3 = (char) getchar();
printf("Lei: %c \n", caracterLeido3);
*/
	
}















/*
int main()
{
   // FILE * archivo = fopen("datosPrueba.txt", "r");
 //FILE * archivo = fopen("datosPrueba.txt", "r");


    char nombre[20];
    token lexema;
    int estado = 0;
    int auxTI=0;
    int auxTC=0;
    int auxTN=0;
    int auxTE=0;

    //lexema = tokenActual;
   // while(!feof(archivo)){
     //   lexema = prox_token();

   int i=0;
   unsigned char tokenaux[200];

	while(archivo!=EOF){
         tokenActual = scanner();
         tokenaux[i]=tokenActual;
         i++;
         }



        switch(lexema){
            case 0: auxTI++;
                break;
            case 1: auxTC++;
                break;
            case 2: auxTN++;
                break;
            case 3: auxTE++;
                break;
    //  }


    printf("%s \n", nombreToken(lexema));
    }
/*
    printf("-------------------------------------------------\n");
    printf("IDENTIFICADORES: %d\n",auxTI);
    printf("CONSTANTES ENTERAS: %d\n",auxTC);
    printf("NUMERALES: %d\n",auxTN);
    printf("ERRORES: %d\n",auxTE);
    fclose(archivo);

    return EXIT_SUCCESS;
*/
