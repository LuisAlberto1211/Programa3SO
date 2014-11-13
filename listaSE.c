#include <stdio.h>
#include <stdlib.h>
int existe=0;

//estructura de nodo
typedef struct nodo
{
	int proc;
	int tam;
        int paginas;
	struct nodo *sig;
} nodot;

typedef nodot *ptrNodo;	//apuntador a tipo nodo
typedef nodot *ptrH;	//apuntador al primer nodo de la lista
typedef nodot *ptrT;	//apuntador al primer nodo de la lista

/*Crea un nuevo nodo y en el campo de dato almacena el valor como parámetro
 regresa el nodo recién creado*/
int validaVacio(ptrH *h){
	return (*h==NULL ? 1:0);
}
 void listaNodo(ptrNodo nodo){
	printf("(%d, %d)",nodo->proc, nodo->tam);
 }
 void listar(ptrH *h){
	if(*h==NULL)
		printf("\n\tLa lista está vacía");
	else{
		ptrNodo i=*h;
		printf("\n");
		while(i!=NULL){
			printf("Proceso: %d, Tamanio de Proceso: %d, Paginas: %d\n",i->proc, i->tam, i->paginas);
			i=i->sig;
			}
		}
 }
 ptrNodo creaNodo(int proc, int tam, int paginas){
	ptrNodo nuevoNodo=(ptrNodo)malloc(sizeof(nodot));
	if(nuevoNodo!=NULL){
		nuevoNodo->proc=proc;
		nuevoNodo->tam=tam;
                nuevoNodo->paginas=paginas;
		nuevoNodo->sig=NULL;
	}
	return nuevoNodo;
}

void insertaNodoInicio(ptrH *h, ptrT *t, int proc, int tam, int paginas ){
	ptrNodo nuevo=creaNodo(proc, tam, paginas);
	if(*h==NULL)	//Sí la lista está vacía
		*t=nuevo;
	nuevo->sig=*h;
	*h=nuevo;
}
void insertaNodoFinal(ptrH *h, ptrT *t, int proc, int tam, int pag){
	ptrNodo nuevo=creaNodo(proc, tam, pag);
	ptrNodo fin=*t;
	if(*h==NULL)
		*h=nuevo;
	else
		fin->sig=nuevo;
	*t=nuevo;
}
/*Agrega a la lista que regresa como parámetro , e inserta otro nodo después de el*/
void insertaNodo(ptrH *h,ptrT *t,ptrNodo ant,int proc, int tam, int pag){
	ptrNodo nuevo=creaNodo(proc, tam, pag);
	ptrNodo fin=*t;
	if(ant!=NULL){	//si el nodo anterior existe
		if(ant==*t)	//si está al final de la lista se inserta en el final
			insertaNodoFinal(h,t,proc, tam, pag);
		else{ //si no está al final de la lista
			nuevo->sig=ant->sig;
			ant->sig=nuevo;
		}
	}
	else {	//si no hay nodo anterior
		*h=nuevo;
		*t=nuevo;
	}
}
void eliminaNodo(ptrH *h, ptrT *t, ptrNodo ant){
	if(ant->sig==*t){
		ant->sig=NULL;
		*t=ant;
		}
	else
		ant->sig=ant->sig->sig;
	
}
ptrNodo buscaNodo(ptrH *h, ptrT *t, int proc){
	ptrNodo nodo=*h;
	while(nodo!=NULL&&(nodo->proc)!=proc){
		nodo=nodo->sig;
	}
	return nodo;
}

ptrNodo buscaNodoAnterior(ptrH *h, ptrT *t, int proc){
	ptrNodo nodo=*h;
	existe=0;
	if(nodo->proc==proc){
		existe=1;
		return NULL;
		}
	else{
		while(nodo->sig!=NULL){
			if((nodo->sig->proc)==proc){
				existe=1;
				return nodo;
			}
			nodo=nodo->sig;
		}
	}
	return nodo;
}

void insertaNodoD(ptrH *h, ptrT *t,int proc, int tam, int nuevoP, int nuevoT, int pag){
	ptrNodo ant=buscaNodo(h,t,proc);
	if(ant!=NULL)
		insertaNodo(h,t,ant,nuevoP, nuevoT, pag);
	else
		printf("No se encuentra dato %d", proc);
}

ptrNodo eliminaNodoA(ptrH *h, ptrT *t, int proc){
	ptrNodo ant=buscaNodoAnterior(h,t,proc);
	ptrNodo aux=*h;
	if(existe==1){	//si encontró el dato
		if(ant!=NULL){	//si no es el primer nodo
			aux= ant->sig;
			eliminaNodo(h,t,ant);
			printf("Entra aqui");
			}
		else if(*h==*t)
			*h=*t=NULL;
		else
			*h=(aux->sig); 
	}
	else
		printf("No se encuentra el dato: %d",proc);
	return aux;
}
void 
actualizaDato(ptrH *h, ptrT *t, int proc, int nuevoP, int nuevoT){
	ptrNodo aux=buscaNodo(h,t,proc);
	if(aux!=NULL)
	{
		aux->proc=nuevoP;
		aux->tam=nuevoT;
	}
	else
		printf("No se encuentra dato: %d", proc);
}
