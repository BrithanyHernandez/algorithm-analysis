//una erolinea desea automatizar la reserva y venta de espacios en sus aviones.Contruye un programa en c++ que asigne 
//los lugares e imprima el boleto
#include<iostream>
using namespace std;
#define FILA 4
#define COLM 4
#define FIL 10
#define COL 6
#define numero_pasajeros 10000
struct aerolinea{
	char nombre[10];
	char apellido[20];
	char origen[20];
	char destino[20];
	int dia;
	int hora;
	int clase;
	char fila;
	int columna;	
}pasajeros[numero_pasajeros];

void mapa_asiento( char asientos_primera[FILA][COLM]){
	cout<<"MAPA DE ASIENTOS\n";
	for(int i=0; i<FILA; i++){
		for(int j=0; j<COLM; j++){
			cout<<asientos_primera[i][j]<<" ";
		}
		cout<<endl;
	}
}

void mapa_asiento_sencillo( char asientos_sencillo[FILA][COL]){
	cout<<"MAPA DE ASIENTOS\n";
	for(int i=0; i<FIL; i++){
		for(int j=0; j<COL; j++){
			cout<<asientos_sencillo[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	char asientos_primera[FILA][COLM], asientos_sencillo[FIL][COL];
	int filaindice, num_pasajeros;
	
	for (int i =0; i < FILA; ++i){
        for (int j = 0; j<COLM; ++j) {
            asientos_primera[i][j] = 'O';	//coloque 0 en nuestra matriz
        }
    }
    
    for (int i = 0; i < FIL; ++i) {
        for (int j = 0; j < COL; ++j) {
            asientos_sencillo[i][j] = 'O';	//coloque 0 en nuestra matriz
        }
    }
	
	cout<<"Cuantos pasajeros desea registrar: "; cin>>num_pasajeros;	
	
	for(int i=0; i<num_pasajeros; i++){	
		cout<<"\nAerolinea"<<endl;
		cout<<"Nombre: ";
		cin>>pasajeros[i].nombre;
		cout<<"Apellido Paterno: ";
		cin>>pasajeros[i].apellido;
		cout<<"Origen: ";
		cin>>pasajeros[i].origen;
		cout<<"Destino: ";	
		cin>>pasajeros[i].destino;
		cout<<"Dia(ddmmaa): ";
		cin>>pasajeros[i].dia;
		cout<<"Hora: (hrmin)";
		cin>>pasajeros[i].hora;
		cout<<"Clase\n1.sencillo\n2.Primera clase\n";
		cin>>pasajeros[i].clase;
		
		switch(pasajeros[i].clase){
			case 1: 
					mapa_asiento_sencillo( asientos_sencillo);
					cout<<"\nElije tu asiento(A1):  ";
					cin>>pasajeros[i].fila>>pasajeros[i].columna;
					filaindice= pasajeros[i].fila -'A';	//ingresar ala matriz {0,1,2..} 
														//A esta en codigo ascii(64-64=0 {subindice 0}) 
					
					if( asientos_sencillo[filaindice][pasajeros[i].columna-1]=='O'){ //ingresa a columna{sunindice 0}
						asientos_sencillo[filaindice][pasajeros[i].columna-1]='X';	//cambia el 'O' por 'X'
						cout<<"Asiento reservado\n";
					}
					else{
						cout<<"Asiento Ocupado\n";
					}
					mapa_asiento_sencillo( asientos_sencillo);	//imprime la matriz actualizada
					
			break;
				
			case 2:
					mapa_asiento( asientos_primera);
					cout<<"\nElije tu asiento(A1)\n";
					cin>>pasajeros[i].fila>>pasajeros[i].columna;
					filaindice= pasajeros[i].fila -'A';	//ingresar ala matriz {0,1,2..} 
													    //A esta en codigo ascii(64-64=0 {subindice 0})
					if( asientos_primera[filaindice][pasajeros[i].columna-1]=='O'){
						asientos_primera[filaindice][pasajeros[i].columna-1]='X';
						cout<<"Asiento reservado\n";
					}
					else{
						cout<<"Asiento Ocupado\n";
					}
					mapa_asiento( asientos_primera);
			break;			
		}
	}
	
	//imprimir
	
	for(int i=0; i<num_pasajeros; i++){
		cout<<"\n_____________________\n";
		cout<<"\nBOLETO"<<endl;
		cout<<"Nombre del pasajero\t\tOrigen\t\tDestino\n";
		cout<<pasajeros[i].nombre<<" "<<pasajeros[i].apellido<<"\t\t"<<pasajeros[i].origen<<"\t\t"<<pasajeros[i].destino;
		cout<<"\n\nDia\t\tHora\t\tClase\t\tAsiento\n";
		cout<<pasajeros[i].dia<<"\t\t"<<pasajeros[i].hora<<"\t\t"<<pasajeros[i].clase<<"\t\t"<<pasajeros[i].fila<<pasajeros[i].columna;
		cout<<"\n_____________________\n";	
	}
	return 0;
}