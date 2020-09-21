#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

static char entrada[30];
char * p;
FILE* archivo;


char* Tokens[] = {"IDENTIFICADOR", "CONSTANTE ENTERA", "NUMERAL", "ERROR", "FIN DE ARCHIVO"};


char* nombreToken(token tok) {
	return Tokens[tok];
}


int pedirAScanner = 1;
token tokenActual;
/*
token prox_token() { // proximo token UTIL
	if (pedirAScanner == 1) {
             printf("holaa");
		do {
			tokenActual = scanner();
      printf("tokenActial : %d",tokenActual);
		} while (tokenActual == FDA);
		pedirAScanner = 0;
	}
	return tokenActual;
}
*/


token prox_token() { // proximo token UTIL
	/*if (pedirAScanner == 1) {
             printf("entro al if \n ");
             tokenActual = scanner();
               printf("pedi token : %d \n \n",tokenActual);
	/*do {
			tokenActual = scanner();
      printf("tokenActial : %d",tokenActual);
		} while (tokenActual == FDA);
		pedirAScanner = 0;
	}*/
	int i=0;
	unsigned char tokenaux[200];

	while(archivo!=EOF){
         tokenActual = scanner();
         tokenaux[i]=tokenActual;
         i++;
         }
	}




enum {
	digito,
	letra,
	numeral,
	espacio,
	fda,
	error
};

int tipoDeCaracter(char c){
    if ( c >= '0' && c <= '9' )                                  {return digito;}
    else if(( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' )){return letra;}
    else if (c == '#')                                           {return numeral;}
    else if (c == ' ' || c == '	' || c == '\n')                  {return espacio;} //el primero es un espacio y el segundo una tabulacion!
    else if (c == EOF)                                           {return fda;}
    else                                                         {return error;}
}

token tipoDeToken(int estado){
    switch (estado){
        case 4: return CONSTANTE;
        case 5: return IDENTIFICADOR;
        case 6: return NUMERAL;
        case 7: return ERROR;
        case 8: return FDA;
        default: return (token)-1;
    }
}

int estadoAceptor(int estado) {
	return (estado == 4 || (estado ==5) || (estado == 6) || (estado == 7) || (estado ==8));
}

int estadoCentinela(int estado) {
	return (estado == 4 || estado == 5 || estado == 6 || estado == 7);
}

int caracterIgnorado(char caracter) {
	return (caracter == ' ' || caracter == '\n');
}


static int tabla[9][6]={
         //     Dig Letr # Esp eof otro
        /*0- */{ 1,  2,  6,  0,  8,  3}, // Inicial
        /*1  */{ 1,  4,  4,  4,  4,  4}, // Casos de cte entera
        /*2  */{ 2,  2,  5,  5,  5,  5}, // Casos de identificador
        /*3  */{ 7,  7,  7,  7,  7,  3}, // Casos de error
        /*4+ */{99, 99, 99, 99, 99, 99}, // Aceptor para cte entera
        /*5+ */{99, 99, 99, 99, 99, 99}, // Aceptor para identificador
        /*6+ */{99, 99, 99, 99, 99, 99}, // Aceptor para numeral
        /*7+ */{99, 99, 99, 99, 99, 99}, // Aceptor para los errores
        /*8+ */{99, 99, 99, 99, 99, 99} // Fin de archivo

};

void iniciarEntrada(char* b) {
	b[0] = '\0';
}

void insertarEnEntrada(char* b, int* s, char c) {
	b[(*s)++] = c;
	b[*s] = '\0';
}
token scanner() {
    FILE * archivo = fopen("datosPrueba.txt", "r");
	char c;
	int es;
	int estado = 0;
	int indexEntrada = 0;
	token tok;
	//char dd;
    //char *entrada[0] = '\0';
    //char *p = entrada;
    iniciarEntrada(entrada);
	p = entrada;
	while (estado!=8) {
		printf("estado actual: %d  \n", estado);
        c = (char) fgetc(archivo);

       printf("leido: %c  \n", c);
      //  c= getchar();
       // printf("tipo de caracter(es): %c  \n",dd );
	    //putchar(dd);

		es = tipoDeCaracter(c);

		printf("tipo de caracter(es): %d  \n", es);


		estado = tabla[estado][es];
        printf("estado en tabla(estado): %d  \n \n", estado);

		if (estadoCentinela(estado)){
			ungetc(c, archivo);}
		else if (!caracterIgnorado(c)){
            insertarEnEntrada(entrada, &indexEntrada, c);
                }
	}
	tok = tipoDeToken(estado);

		printf("numerotoken %d \n", tok);
	    printf("nombre token %s \n", nombreToken(tok));

	return tok;
}

