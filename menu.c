//Menu
#include <stdio.h>
#include <stdlib.h>

int opciones(char cadena[240], int max){
	int op;
	do{
		printf("%s",cadena);
		scanf("%d",&op);
		if(op<1||op>max)
			printf("Dato invalido, intenta nuevamente");
	}while(op<1||op>max);
	return op;
}

int numero(char cadena [120]){
	int op;
		printf("%s",cadena);
	scanf("%d",&op);
	return op;
}