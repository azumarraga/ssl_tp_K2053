#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

typedef enum {
	IDENTIFICADOR,
	CONSTANTE,
	NUMERAL,
	ERROR,
	FDA
} token;

extern FILE * archivo;
extern token scanner();
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

#endif // SCANNER_H_INCLUDED



