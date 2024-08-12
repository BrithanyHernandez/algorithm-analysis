#include <iostream>
#include <cstdlib>
#define MAX 15
using namespace std;

void verificarSimetria(int mat_sim[MAX][MAX]);

int main(){
    int mat_sim[MAX][MAX];
    int fila, columna;
    
    cout<<"Ingresa el tamanio de fila: "; cin>>fila;
    cout<<"Ingresa el tamanio de columnas: "; cin>>columna;
    
    if(fila==columna){
    	for(int i=0; i<fila; i++){
    		for(int j=0; j<columna; j++){
    			cout<<"Elemento "<<i<<j<<": ";
    			cin>>mat_sim[i][j];
			}
		}
		verificarSimetria(mat_sim);
	}
	else{
		cout<<"\nMatriz asimetrica. La matriz ha ingresar debe ser cuadrada\n";
	}

    return 0;
}

void verificarSimetria(int mat_sim[MAX][MAX]){
	int fila,columna;
	
    for(int i=0; i<fila; i++){
        for(int j=i+1; j<columna; j++){	//empezando desde la sig.fila
            if(mat_sim[i][j] != mat_sim[j][i]){	 //verifica si el elemento no es igual a su reflejo en la diagonal
                cout << "La matriz no es simetrica" << endl;
                exit(0); // Sale del programa
            }
        }
    }
    cout << "La matriz es simetrica" << endl;
}
