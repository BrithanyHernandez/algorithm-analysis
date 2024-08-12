#include<iostream>
#define REN 2
#define COL 3

using namespace std;

int main() {
	int A[REN][COL], B[REN][COL], C[REN][COL];
	for (int i=0; i<REN; i++){
		for (int j=0; j<COL; j++){
			cout<<"\n Elemento "<<i<<j<<" de A:";
			cin>>A[i][j];
			cout<<"Elemento "<<i<<j<<" de B:";
			cin>>B[i][j];
			C[i][j]=A[i][j]+B[i][j];
			cout<<C[i][j]<<'\t';		
		}
		cout<<endl;
	}
}