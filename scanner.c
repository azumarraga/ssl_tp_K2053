#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/////////SCANNER.H////////


typedef enum {
	IDENTIFICADOR,
	CONSTANTE,
	NUMERAL,
	ERROR,
	FDA
} token;


extern FILE * archivo;

extern token tokenActual;
extern char * p;
extern char *Tokens[];
extern int auxTI;
extern int auxTC;
extern int auxTN;
extern int auxTE;
char* nombreToken(token tok);
token prox_token(void);
void match(token tok);









/////////////////////////////
char* Tokens[] = {"IDENTIFICADOR", "CONSTANTE ENTERA", "NUMERAL", "ERROR", "FIN DE ARCHIVO"};


char* nombreToken(token tok) {
	return Tokens[tok];
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



token scanner(){
		token tok;
	    char caracterLeido;
	    int estado=0;
	    int estadoColumna;
	    
	    while (!estadoAceptor(estado)) {
	    		
			caracterLeido = (char) getchar();
			 
			printf("Lei: %c \n", caracterLeido);
			 
			 
			estadoColumna = tipoDeCaracter(caracterLeido);
			printf("tipo de caracter(estadoFila): %d  \n", estado);
			printf("tipo de caracter(estadoColumna): %d  \n", estadoColumna);
		
			
			estadoColumna = tipoDeCaracter(caracterLeido);
			estado = tabla[estado][estadoColumna];
				printf("estado en tabla(estado): %d  \n \n", estado);
			
				if (estadoCentinela(estado))
				{
					ungetc(caracterLeido,stdin);

					printf("llegue aca ");
				}
				else if (!caracterIgnorado(caracterLeido))
				{
       				  //   insertarEnEntrada(entrada, &indexEntrada, c);
                }
	
		}
	tok = tipoDeToken(estado);
	return tok;
	
	
}

