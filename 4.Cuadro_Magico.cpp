#include <iostream>
using namespace std;

void cuadroMagico(int orden);

int main(){
	
    int orden;
    cout<<"Ingresa el orden del cuadro magico: ";
    cin>>orden;
    
    if(orden%2==0){
        cout<<"El orden debe ser impar";
    }
	else{
		cuadroMagico(orden);
	}	    

    return 0;
}

void cuadroMagico(int orden){

    int cuadro[15][15] ={0};
    int fila=0;
    int columna=orden/2;	//paso 2. colocar en medio de la 1er fila
    					// 5/2-> 2 (subindice 2) [el subindice de la matriz empieza en 0]
    int i=1;

    while (i<=orden*orden){	//total de espacios de la matriz
        cuadro[fila][columna]=i;
        
        int siguienteFila=(fila-1+orden) % orden;	//paso3.Colocar arriba
        int siguienteCol=(columna+1) % orden;	//paso3.Colocar ala derecha

        if(cuadro[siguienteFila][siguienteCol]!=0){	//paso6.Ya hay numero en casilla Y se coloca abajo
            fila=(fila + 1) % orden;
        } else {
            fila=siguienteFila;
            columna=siguienteCol;
        }
		i++;
    }

    cout<<"\n\n     CUADRO MAGICO de "<<orden<<"x"<<orden<<"\n\n";
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            cout<<cuadro[i][j] << "\t";
        }
        cout << endl;
    }
}