#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.h"



int main(){

	token tokenAux=0;

	int tokensIDENTIFICADOR=0;
    int tokensCONSTANTE=0;
    int tokensNUMERAL=0;
    int tokensERROR=0;

	while(tokenAux!=FDA){

		tokenAux=scanner();
		
		if(tokenAux!=FDA){ 
			printf("%s \n", nombreToken(tokenAux));
		}
		
		switch(tokenAux){
	            case 0: tokensIDENTIFICADOR++;
	                break;
	            case 1: tokensCONSTANTE++;
	                break;
	            case 2: tokensNUMERAL++;
	                break;
	            case 3: tokensERROR++;
	                break;
				case 4: ;
					break;
					}

	}




	printf("-------------------------------------------------\n");
    printf("Identificadores: %d\n",tokensIDENTIFICADOR);
    printf("Constantes enteras: %d\n",tokensCONSTANTE);
    printf("Numerales: %d\n",tokensNUMERAL);
    printf("Errores: %d\n",tokensERROR);
}


