#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED


extern int auxTI;
extern int auxTC;
extern int auxTN;
extern int auxTE;


typedef enum {
	IDENTIFICADOR,
	CONSTANTE,
	NUMERAL,
	ERROR,
	FDA
} token;



extern token tokenActual;

extern char *Tokens[];

extern char* nombreToken(token tok);

int tipoDeCaracter(char c);

token tipoDeToken(int estado);

int estadoAceptor(int estado);

int estadoCentinela(int estado);

int caracterIgnorado(char caracter);


extern token scanner();



#endif // SCANNER_H_INCLUDED


