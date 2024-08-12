#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void Agregar_Pila(Nodo *&, int);	//prototipo
void Sacar_pila(Nodo *&, int &);

int main(){
	
	Nodo *pila=NULL;
	int dato, opcion;
	
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		Agregar_Pila(pila, dato);
		
		cout<<"Agregar otro elemento ala pila? (1. si/ 2.no)";
		cin>>opcion;
		
	}while(opcion==1);
	
	cout<<"\n\tElementos de pila\n";
	
	while(pila!=NULL){ //mientras no sea el final de pila
		Sacar_pila(pila, dato);
			cout<<"[ "<<dato<<" ]\n";
		
	}
	
}

void Agregar_Pila(Nodo *&pila, int n){
	
	Nodo *nuevo_nodo= new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	
	cout<<"\t\nElemento "<<n<<" ha sido agregado a PILA correctamente\n";
}

void Sacar_pila(Nodo *&pila, int &n){
	if(pila!=NULL){
		Nodo *aux=pila;
		n=aux->dato;
		pila=aux->siguiente;
		delete aux;
	}
}