//prueba de lista

#include <stdio.h>
#include <stdlib.h>
#include "listaSE.c"
#include "menu.c"
int main(void){
	int dato, datoN, dato2, dato2N;
	int op;
	ptrH h=NULL;
	ptrT t=NULL;
	ptrNodo aux=NULL;
	do{
	switch(op=opciones("\n\n\n\tIngresa una opcion\n\t1)Listar datos\n\t2)Insertar nuevo al final\n\t3)Insertar nuevo dato después de otro\n\t4)Eliminar dato\n\t5)Buscar Elemento\n\t6)Actualizar dato\n\t7)Salir\n\t",7))
	{
		case 1:
			listar(&h);
			break;
		case 2:
			dato=numero("\n\tIngresa un numero entero:\t");
			dato2=numero("\n\tIngresa un numero entero:\t");
			insertaNodoFinal(&h,&t,dato, dato2);
			break;
		case 3:
			dato=numero("\n\tIngresa el dato anterior:\t");
			datoN=numero("\n\tIngresa el dato a insertar:\t");
			dato2N=numero("\n\tIngresa el dato a insertar:\t");
			insertaNodoD(&h,&t,dato,datoN, dato2, dato2N);
			break;
		case 4:
			dato=numero("\n\tIngresa el dato a eliminar:\t");
			aux=eliminaNodoA(&h,&t,dato);
			if(aux!=NULL){
				printf("\n\tDato borrado:\t");
				listaNodo(aux);
				}
			break;
		case 5:
			dato=numero("\n\tIngresa el dato a buscar:\t");
			dato2=numero("\n\tIngresa el dato a buscar:\t");
			aux=buscaNodo(&h,&t,dato, dato2);
			if(aux!=NULL){
				printf("\n\tDato encontrado:\t");
				listaNodo(aux);
				}
			else
				printf("\n\tDato %d no encontrado",dato);
			break;
		case 6:
			dato=numero("\n\tIngresa el dato a actualizar:\t");
			datoN=numero("\n\tIngresa el nuevo dato:\t");
			dato=numero("\n\tIngresa el dato a actualizar:\t");
			datoN=numero("\n\tIngresa el nuevo dato:\t");
			actualizaDato(&h,&t,dato,datoN, dato2, dato2N);
			break;
		case 7:
			printf("\tSaliendo del programa\n\tGracias por su preferencia");
			system("pause");
			break;
	}
	}while(op!=7);
	
}
