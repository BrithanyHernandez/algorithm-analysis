#include<iostream>
using namespace std;

int factorial(int num);

int main(){
	int num;
	
	cout<<"Ingresa el numero a sacar el factorial: ";
	cin>>num;
	cout<<"\nFactorial: "<<factorial(num);
	
}

int factorial(int num){
	if(num==0)
		return 1;
	else
		return num*factorial(num-1);		
}
