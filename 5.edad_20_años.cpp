 //Programa que escriba la leyenda "Juanita en 20 años tendra 48 " utilizando struct
 #include<iostream>
 using namespace std;
 
 struct Persona{
 	char nombre[20];
 	int edad;
 }usuario;
 
 void ingresar_nombre();
 int edad_usuario(int edad);
 
 int main(){
 	int edad;
 	ingresar_nombre();
 	cout<<"Ingresa tu edad: ";
 	cin>>usuario.edad;
 	cout<<"En 20 anios tendras "<<edad_usuario(edad);

 	return 0;
 }
 
 
 void ingresar_nombre(){
 	cout<<"Nombre: ";
 	cin>> usuario.nombre;
 }
 
 int edad_usuario(int edad){
 	return usuario.edad+20;
 	
 }