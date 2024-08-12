#include<iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#define num_empleados 100
using namespace std;

struct Empleado{	//actividad de equip.Estructuras
	char nombre[30];
	float sueldo;
	int departamento;
}empleados[num_empleados];

struct Nodo{	//actividad de equipo_Pilas
	int dato_P;									
	Nodo *siguiente;
};

struct Nodo_Arbol{	//actividad de equip.ARBOLES
	int valor;
	Nodo_Arbol* izquierdaA;	
	Nodo_Arbol* derechaA;
	// Constructor para inicializar un nodo con un valor dado
	Nodo_Arbol(int v): valor(v), izquierdaA(nullptr), derechaA(nullptr) {}
};

struct NodoListas{
    int datoL;
    NodoListas* siguienteL;
    NodoListas(int val) : datoL(val), siguienteL(nullptr) {}
};

void arreglos();	
void ingresarEmpleados(Empleado empleados[num_empleados], int cant_empleados);//actividad de equip.Estructuras
void mostrarEmpleados(Empleado empleados[num_empleados], int cant_empleados);//actividad de equip.Estructuras
//---------ACTIVIDAD DE EQUIPO DE PILAS----------------
void Pila(Nodo *&pila);						
void Agregar_Pila(Nodo *&, int);	//prototipos de PILA
void Sacar_Pila(Nodo *&, int &);	//prototipos de PILA
//-------ACTIVIDAD DE EQUIPO DE COLAS-------------
void Cola();
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void mostrarCola(Nodo *);
void eliminarPrimeroCola(Nodo *&, Nodo *&, int &);

//-------ACTIVIDAD DE LISTAS-------------
NodoListas* fusionarListas(NodoListas* , NodoListas* );
void imprimirLista(NodoListas*);
void ejecutarFusionListas();

//-------ACTIVIDAD DE ARBOLES-------------

class ArbolBinario{
	Nodo_Arbol* raiz;
	private:
	void liberarNodos(Nodo_Arbol* nodoA){
		if (nodoA != nullptr){
			liberarNodos(nodoA->izquierdaA);
			liberarNodos(nodoA->derechaA);
			delete nodoA;
		}
	}
	
	void agregarNodoPrivado(int valor, Nodo_Arbol* nodoA){
		if (valor < nodoA->valor){
			if (nodoA->izquierdaA != nullptr){
				agregarNodoPrivado(valor, nodoA->izquierdaA);
			}else{
				nodoA->izquierdaA = new Nodo_Arbol(valor);
			}
		}else{
			if(nodoA->derechaA != nullptr){
				agregarNodoPrivado(valor, nodoA->derechaA);
			}else{
				nodoA->derechaA = new Nodo_Arbol(valor);
			}
		}
	}
	
	void recorrerPreOrdenPrivado(Nodo_Arbol* nodoA) {
		if (nodoA != nullptr){
			cout << nodoA->valor << " ";
			recorrerPreOrdenPrivado(nodoA->izquierdaA);
			recorrerPreOrdenPrivado(nodoA->derechaA);
		}
	}
	
	void recorrerInOrdenPrivado(Nodo_Arbol* nodoA){
		if (nodoA != nullptr){
			recorrerInOrdenPrivado(nodoA->izquierdaA); 
			std::cout << nodoA->valor << " "; 
			recorrerInOrdenPrivado(nodoA->derechaA);
		}
	} 
	
	void recorrerPostordenPrivado(Nodo_Arbol* nodoA){
		if (nodoA != nullptr){
			recorrerPostordenPrivado(nodoA->izquierdaA); 
			recorrerPostordenPrivado(nodoA->derechaA); 
			std::cout << nodoA->valor << " ";
		}
	}
	
	public:
		ArbolBinario() : raiz(nullptr) {}
		~ArbolBinario(){
			liberarNodos(raiz);
		}
		
	void agregarNodo(int valor){
		if (raiz == nullptr){
			raiz = new Nodo_Arbol(valor);
		}else{
			agregarNodoPrivado(valor, raiz);
		}
	}
	
	void recorrerPreOrden() {
		std::cout << "Recorrido preorden del arbol: ";
		recorrerPreOrdenPrivado(raiz);
		std::cout << std::endl;
	}
	
	void recorrerInOrden(){
		std::cout << "Recorrido inorden del arbol: ";
		recorrerInOrdenPrivado(raiz);
		std::cout << std::endl;
	}
	
	void recorrerPostorden (){
		std::cout << "Recorrido postorden del arbol: ";
		recorrerPostordenPrivado(raiz);
		std::cout << std::endl;
	}
};

void mostrarMenuArbol(ArbolBinario& arbol);

//-------METODO SELECCION-------------
void BusquedaSecuencial();

//-------METODO INTERCMBIO-------------
void MetodoIntercambio();

//-------METODO SELECCION DIRECTA-------------
void SeleccionDirecta();

//-------ACTIVIDAD DE CONJUNTOS-------------
class Libro {
	private:
	    string titulo;
	    string autor;
	    string genero;
	    int num_paginas;
	
	public:
	    Libro(string _titulo, string _autor, string _genero, int _num_paginas) {
	        titulo = _titulo;
	        autor = _autor;
	        genero = _genero;
	        num_paginas = _num_paginas;
	    }
	
	    // Métodos para establecer y obtener los valores de los atributos
	    void setTitulo(string _titulo) { titulo = _titulo; }
	    string getTitulo() { return titulo; }
	
	    void setAutor(string _autor) { autor = _autor; }
	    string getAutor() { return autor; }
	
	    void setGenero(string _genero) { genero = _genero; }
	    string getGenero() { return genero; }
	
	    void setNumPaginas(int _num_paginas) { num_paginas = _num_paginas; }
	    int getNumPaginas() { return num_paginas; }
	
	    // Método para mostrar la información completa del libro
	    void mostrarInformacion() {
	        cout << "Titulo: " << titulo << endl;
	        cout << "Autor: " << autor << endl;
	        cout << "Genero: " << genero << endl;
	        cout << "Numero de paginas: " << num_paginas << endl;
	    }
};

class Biblioteca {
	private:
	    vector<Libro> libros;
	
	public:
	    // Método para añadir un libro a la colección
	    void agregarLibro(Libro libro) {
	        libros.push_back(libro);
	    }
	
	    // Método para mostrar todos los libros de la biblioteca
	    void mostrarLibros(){
	        if (libros.empty()){
	            cout << "\n\n*****La biblioteca esta vacia.*****" << endl;
	        } else {
	            cout << "\n\n*****Libros en la biblioteca:*****" << endl;
	            for (int i = 0; i < libros.size(); ++i) {
	                cout << "Libro " << i + 1 << ":" << endl;
	                libros[i].mostrarInformacion();
	                cout << endl;
	            }
	        }
	    }
	
	    // Método para buscar un libro por su título
	    void buscarPorTitulo(string titulo) {
	        bool encontrado = false;
	        cout << "\n\n*****Resultados de la busqueda por titulo ******" << titulo << "':" << endl;
	        for (int i = 0; i < libros.size(); ++i) {
	            if (libros[i].getTitulo() == titulo) {
	                libros[i].mostrarInformacion();
	                encontrado = true;
	            }
	        }
	        if (!encontrado) {
	            cout << "\n\n******No se encontraron libros con ese titulo.******" << endl;
	    }
	}
};

void Conjuntos(Biblioteca& biblioteca);  

//-------METODO INSERCCION-------------
void insercion(int* , int);
void imprimirArreglo(int* , int);
void ingresarValores(int*);


//-------METODO MERGE SORT-------------
void merge(vector<int>&, int, int, int);
void MergeSort(vector<int>&, int, int);
void imprimirArreglo(const vector<int>&);
vector<int> ingresarArreglo();
void ejecutarMergeSort();




int main(){
	int opcion, cant_empleados;
	Nodo *pila=NULL;
	ArbolBinario arbol;
	Biblioteca biblioteca;
	int arreglo[num_empleados];
	
	do{
		cout<<"\n\t MENU\n";
		cout<<"1. Arreglos"<<endl;
		cout<<"2. Registros"<<endl;
		cout<<"3. Conjuntos"<<endl;
		cout<<"4. Pilas"<<endl;
		cout<<"5. Colas"<<endl;
		cout<<"6. Listas"<<endl;
		cout<<"7. Arboles"<<endl;
		
		cout<<"\nMETODOS DE ORDENAMIENTO\n";
		cout<<"8. Busqueda Secuencial y Binaria"<<endl;
		cout<<"9. Intercambio"<<endl;
		cout<<"10. Seleccion Directa"<<endl;
		cout<<"11. Inserccion"<<endl;
		cout<<"12. Merge Sort"<<endl;
		
		
		cout<<"13.Salir"<<endl;
		cout<<"\nElija una opcion: ";
		cin>>opcion;
		
		
		switch(opcion){
		
			case 1:
				arreglos();
				
			break;
			
			case 2:
				cout<<"Ingresa la cantidad de empleados: ";
				cin>>cant_empleados;
				
				ingresarEmpleados(empleados, cant_empleados);
				mostrarEmpleados(empleados, cant_empleados);
				
			break;
			
			case 3:
				Conjuntos(biblioteca);
			
			break;
			
			case 4:
				
				Pila(pila);
				
			break;
			
			case 5:
				Cola();
			break;
			
			case 6:
				ejecutarFusionListas();	
			break;
			
			case 7:
				mostrarMenuArbol(arbol);
			break;
			
			case 8:
				BusquedaSecuencial();
			break;
			
			case 9:
				MetodoIntercambio();
			break;
			
			case 10:
				SeleccionDirecta();
			break;
			
			case 11:
				ingresarValores(arreglo);

			break;
			
			case 12:
				ejecutarMergeSort();
			break;		
		}
		
		cout<<"\n";
		system("pause");
		system("cls");
	
	}while(opcion!=13);	
	 	
}
			
void arreglos(){
	int arreglo1[10]={0};
	int arreglo2[10]={0};
	int suma[10]={0};
	int n,n2;
	
	cout<<"Suma de dos arreglos\n";
	cout<<"tamanio del arreglo 1: "; 
	cin>>n;
	cout<<"tamanio del arreglo 2: "; 
	cin>>n2;
	
	if(n==n2){
		cout<<"Ingresa los valores del Arreglo1\n";
		for(int i=0; i<n; i++){
			cin>>arreglo1[i];
		}
		
		cout<<"Ingresa los valores del Arreglo2\n";
		for(int j=0; j<n2; j++){
			cin>>arreglo2[j];
		}
		
		//suma de arreglo
		for (int i=0; i<n; ++i) {
        suma[i]=arreglo1[i] + arreglo2[i];
    	}
    	
    	cout<<"La suma de los elementos de los arreglos es: "<<endl;
    	
   		for(int i=0;i<n; ++i) {
        	cout << suma[i] << " ";
    	}
		cout<<endl;	
	}
	else{
		cout<<"El tamaño de los arreglos deben ser iguales\n";
	}
}

void ingresarEmpleados(Empleado empleados[num_empleados], int cant_empleados){	//actividad de equip.Estructuras

	cout << "REGISTRO DE EMPLEADOS\n";
	
    for (int i=0; i<cant_empleados; ++i){
    	
        cout<<"Empleado "<<i+1<<":\n";
        cout<<"Nombre: ";
        cin>>empleados[i].nombre;
        cout<<"Sueldo: ";
        cin>>empleados[i].sueldo;
        cout<<"Departamento: ";
        cin>>empleados[i].departamento;
    }
}

void mostrarEmpleados(Empleado empleados[num_empleados],int cant_empleados){//actividad de equip.Estructuras
	
	cout<<"\n\tDATOS DE LOS EMPLEADOS:\n";
	cout<<"________________________________________________________"<<endl;
	cout<<"\tNombre\t\tSueldo\t\tDepartamento\n";
	cout<<"________________________________________________________"<<endl;
	
    for (int i=0; i<cant_empleados; ++i){
        cout<<"\t"<<empleados[i].nombre<<"\t\t"<<empleados[i].sueldo<<"\t\t"<<empleados[i].departamento<<endl;
    }
    cout<<"________________________________________________________"<<endl;
	
}

void Pila(Nodo *&pila){
	int opc,dato_P;
	
	do {
        cout << "\nMENU DE PILA\n";
        cout << "1. Insertar elemento a la pila\n";
        cout << "2. Mostrar elementos de la pila\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout<<"Digite un numero: ";
                cin>>dato_P;
                Agregar_Pila(pila, dato_P);
            break;
                
            case 2:
                cout<<"\nElementos de la pila:\n";
                
                while(pila!=NULL){
                    Sacar_Pila(pila,dato_P);
                    cout<<"[ " <<dato_P<< " ]\n";
                }
            break;
            
            case 3:
                cout<<"Saliendo del programa de PILAS...\n";
                break;
        }
    }while(opc!=3);
	
}

void Agregar_Pila(Nodo *&pila, int n){	// Función para agregar un elemento a la pila
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato_P = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "\n\tElemento " << n << " ha sido agregado a la pila correctamente.\n";
}

void Sacar_Pila(Nodo *&pila, int &n){	// Función para sacar un elemento de la pila
	
    if (pila != NULL) {
        Nodo *aux = pila;
        n = aux->dato_P;
        pila = aux->siguiente;
        delete aux;
    }
}

void Cola(){
	
	int opc, dato_P;
	Nodo *frente = NULL;
	Nodo *fin = NULL;

    do{
        cout << "\t\nMENU DE COLAS\n";
        cout << "1. Insertar elemento a cola" << endl;
        cout << "2. Mostrar elementos a cola" << endl;
        cout << "3. Eliminar el primer elemento de la cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1: 
				cout << "\nDigite un numero: ";
                cin>>dato_P;
                insertarCola(frente, fin, dato_P);
            break;
                    
            case 2: 
				mostrarCola(frente);
                
            break;
            
            case 3:
				cout<<"\nEliminando el primer elemento de la cola"<<endl;
                eliminarPrimeroCola(frente, fin,dato_P);
                
                    if(frente!=NULL){
                        cout<<"El elemento eliminado fue: " <<dato_P<<endl;
                    }
                    else{
                        cout<<"La cola está vacía"<<endl;
                    }
                break;
            case 4: break;
        }
    } while(opc!= 4);
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato_P= n;
    nuevo_nodo->siguiente=NULL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true : false; 
}

void mostrarCola(Nodo *frente) {
    if(cola_vacia(frente)){
        cout<<"La cola esta vacia."<<endl;
        return;
    }
    cout<<"\nMostrando los elementos de la cola: ";
    Nodo *temp=frente;
    
    while(temp!=NULL){
        cout<<temp->dato_P<< " ";
        temp=temp->siguiente;
    }
    cout << endl;
}

void eliminarPrimeroCola(Nodo *&frente, Nodo *&fin, int &n) {
    if (frente == NULL) {
        cout<<"La cola esta vacia."<<endl;
        return;
    }
    else{
        n=frente->dato_P;
        Nodo *aux=frente;
        if(frente==fin) { // Si solo hay un elemento en la cola
            frente=NULL;
            fin=NULL;
        }
        else{
            frente=frente->siguiente;
        }
        delete aux;
    }
}

void mostrarMenuArbol(ArbolBinario& arbol) {
    int opcion, valor;

    do {
        cout<<"\nMENU DE ARBOLES: \n";
        cout<<"1. Agregar Nodo\n";
        cout<<"2. Recorrido Preorden\n";
        cout<<"3. Recorrido Inorden\n";
        cout<<"4. Recorrido Postorden\n";
        cout<<"5. Salir\n";
        cout<<"Ingrese su opcion: ";
        cin>>opcion;

        switch(opcion){
	        case 1:
	            cout<<"Ingrese el valor del nodo a agregar: ";
	            cin>>valor;
	            arbol.agregarNodo(valor);
	            break;
	
	        case 2:
	            arbol.recorrerPreOrden();
	            break;
	
	        case 3:
	            arbol.recorrerInOrden();
	            break;
	
	        case 4:
	            arbol.recorrerPostorden();
	            break;
	
	        case 5:
	            break;
    	}
    }while(opcion!=5);
}

void BusquedaSecuencial() {
    int n;
    cout<<"Ingrese la cantidad del arreglo: ";
    cin>>n;

    int Arreglo[n];
    cout<<"Ingrese los elementos:\n";
    for (int i=0; i<n; i++){
        cin>>Arreglo[i];
    }

    int buscar;
    cout<<"Ingrese el elemento a buscar: ";
    cin>>buscar;

    int indice=-1;
    for(int i=0; i<n; i++){
        if(Arreglo[i]==buscar) {
            indice=i;
            break;	// Si se encuentra el elemento, se actualiza el índice y sale del bucle
        }
    }

    if (indice!=-1){
        cout<<"El elemento "<<buscar<< "SE ENCUENTRA en la posición " <<indice<< endl;
    }else{
        cout<<"El elemento " <<buscar<< " NO SE ENCUENTRA en el arreglo."<<endl;
    }
}

void MetodoIntercambio(){
	int N, i, j, Aux, P=0, V=0;
	
	cout<<"Ingrese la cantidad de datos que desea: ";
    cin>>N;
    
    int A[N];
    
    cout<<"Ingrese los " <<N<< " valores:\n";
    
    for (int i=0; i<N; ++i){
        cin>>A[i];
    }
    
    //algoritmo de INTERCAMBIO
    for (i=0; i<N; i++){
        for (j=0; j<N-1; j++){

            if (A[j]>A[j+1]){	//CONDICION para el INTERCAMBIO(dependiento del Usuario o Metodo)
            					//compara el valor actual SI ES MAYOR con el siguiente valor
        
                Aux=A[j];	//variable auxiliar para no perder valor
                A[j]=A[j+1];
                A[j+1]=Aux;	// Intercambio de elementos utilizando una variable auxilia
            }
        }
    }
    cout<<"Arreglo Ordenado"<<endl;
    for(int k=0; k<N; k++) {
                cout<<A[k]<<"  ";
        }
    cout << "\n";
}

void SeleccionDirecta(){
	int n;
    cout<<"Ingrese la cantidad de numeros: ";
    cin>>n;

    int Arreglo[n];

    for(int i=0; i<n; i++){
        cin >> Arreglo[i];
    }

    int min, aux;
    //ALGORITMO DE SELECCION DIRECTA
    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(Arreglo[j]<Arreglo[min]){	//comparacion de variables
                min=j;
            }
        }
        
        aux=Arreglo[i];
        Arreglo[i] = Arreglo[min];	// Intercambio de elementos
        Arreglo[min] = aux;
    }

    cout << "Arreglo ordenado: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<Arreglo[i]<< " ";
    }
    cout << endl;
}

void Conjuntos(Biblioteca& biblioteca) {
    int opcion;
    string titulo;
    string autor;
    string genero;
    int num_paginas;

    do {
        cout << "\n--------Menu de opciones:-------" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar todos los libros" << endl;
        cout << "3. Buscar libro por titulo" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\nIngrese el titulo del libro: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "\nIngrese el autor del libro: ";
                getline(cin, autor);
                cout << "\nIngrese el genero del libro: ";
                getline(cin, genero);
                cout << "\nIngrese el numero de paginas del libro: ";
                cin >> num_paginas;

                Libro nuevoLibro(titulo, autor, genero, num_paginas);
                biblioteca.agregarLibro(nuevoLibro);
                break;
            }
            case 2:
                biblioteca.mostrarLibros();
                break;
            case 3:
                cout << "\n\n*****Ingrese el titulo del libro a buscar: *****";
                cin.ignore();
                getline(cin, titulo);
                biblioteca.buscarPorTitulo(titulo);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                break;
        }

    } while (opcion != 4);
}

NodoListas* fusionarListas(NodoListas* lista1, NodoListas* lista2) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    NodoListas* head; 
    NodoListas* actual; 

    if (lista1->datoL < lista2->datoL) {
        head = lista1;
        lista1 = lista1->siguienteL;
    } else {
        head = lista2;
        lista2 = lista2->siguienteL;
    }
    actual = head;

    while (lista1 && lista2) {
        if (lista1->datoL < lista2->datoL) {
            actual->siguienteL = lista1;
            lista1 = lista1->siguienteL;
        } else {
            actual->siguienteL= lista2;
            lista2 = lista2->siguienteL;
        }
        actual = actual->siguienteL;
    }
    if (lista1) actual->siguienteL = lista1;
    if (lista2) actual->siguienteL= lista2;

    return head;
}

void imprimirLista(NodoListas* head) {
    NodoListas* actual = head;
    while (actual) {
        cout << actual->datoL<< " ";
        actual = actual->siguienteL;
    }
    cout<<endl;
}

void ejecutarFusionListas() {
    NodoListas* lista1 = new NodoListas(1);
    lista1->siguienteL = new NodoListas(2);
    lista1->siguienteL->siguienteL= new NodoListas(4);

    NodoListas* lista2 = new NodoListas(1);
    lista2->siguienteL= new NodoListas(3);
    lista2->siguienteL->siguienteL= new NodoListas(4);

    cout << "Lista 1: ";
    imprimirLista(lista1);

    cout << "Lista 2: ";
    imprimirLista(lista2);

    NodoListas* lista_fusionada = fusionarListas(lista1, lista2);

    cout << "Lista fusionada: ";
    imprimirLista(lista_fusionada);
}

void merge(vector<int>& arreglo, int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int> izquierda(elementosIzq);
    vector<int> derecha(elementosDer);

    for (int i = 0; i < elementosIzq; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < elementosDer; j++) {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < elementosIzq && j < elementosDer) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (j < elementosDer) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while (i < elementosIzq) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
}

void MergeSort(vector<int>& arreglo, int inicio, int final) {
    if (inicio < final) {
        int mitad = inicio + (final - inicio) / 2;
        MergeSort(arreglo, inicio, mitad);
        MergeSort(arreglo, mitad + 1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

void imprimirArreglo(const vector<int>& arreglo) {
    cout << endl;
    for (int i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

vector<int> ingresarArreglo() {
    int cantidad;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> cantidad;

    vector<int> arreglo(cantidad);
    cout << "Ingrese los " << cantidad << " elementos del arreglo:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> arreglo[i];
    }

    return arreglo;
}

void ejecutarMergeSort() {
    vector<int> arreglo = ingresarArreglo();

    cout << "Arreglo original:" << endl;
    imprimirArreglo(arreglo);

    MergeSort(arreglo, 0, arreglo.size() - 1);

    cout << "\nValores ordenados:" << endl;
    imprimirArreglo(arreglo);
}

void insercion(int* n, int size) {
    for (int i=1; i <size; i++) {
        int actual=n[i];
        int j=i;
        while(j>0 && n[j-1]>actual){
            n[j]=n[j-1];
            j--;
        }
        n[j] = actual;
    }
}

void imprimirArreglo(int* n, int size) {
    cout<<"Arreglo ordenado:" <<endl;
    for (int i=0; i<size; i++){
        cout<<n[i]<< " ";
    }
    cout << endl;
}

void ingresarValores(int* n) {
    char opcion;
    int valor, size = 0;
    do {
        if(size<num_empleados) {
            cout<<"Ingrese un valor: ";
            cin>>valor;
            n[size++]=valor;
            cout<<"Desea ingresar otro valor? (s/n): ";
            cin>>opcion;
        } else{
            cout<<"El arreglo está lleno." << endl;
            break;
        }
    } while(opcion=='s');
    insercion(n, size);
    imprimirArreglo(n, size);
}
