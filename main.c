#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.c"



int main(){
	
	token tokenActual=0;
	
	int tokensIDENTIFICADOR=0;
    int tokensCONSTANTE=0;
    int tokensNUMERAL=0;
    int tokensERROR=0;
			
	while(tokenActual!=4){
		
			tokenActual=scanner();
		printf("%s \n", nombreToken(tokenActual));
		
		switch(tokenActual){
	            case 0: tokensIDENTIFICADOR++;
	                break;
	            case 1: tokensCONSTANTE++;
	                break;
	            case 2: tokensNUMERAL++;
	                break;
	            case 3: tokensERROR++;
	                break;
					}
					
	}


/*	do{
	
	tokenActual=scanner();
	printf("%s \n", nombreToken(tokenActual));
	
	switch(tokenActual){
            case 0: tokensIDENTIFICADOR++;
                break;
            case 1: tokensCONSTANTE++;
                break;
            case 2: tokensNUMERAL++;
                break;
            case 3: tokensERROR++;
                break;
				}
	
	}while(tokenActual!=4);
	*/

	printf("-------------------------------------------------\n");
    printf("Identificadores: %d\n",tokensIDENTIFICADOR);
    printf("Constantes enteras: %d\n",tokensCONSTANTE);
    printf("Numerales: %d\n",tokensNUMERAL);
    printf("Errores: %d\n",tokensERROR);
}


