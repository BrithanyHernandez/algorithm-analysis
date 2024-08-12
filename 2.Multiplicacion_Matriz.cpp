
#include<iostream>
#define REN_A 2
#define COL_A_REN_B 3
#define COL_B 4

using namespace std;

int main() {
	int A[REN_A][COL_A_REN_B],
	    B[COL_A_REN_B][COL_B],
	    C[REN_A][COL_B];
	    
    	for (int i=0; i<REN_A; i++)
		for (int j=0; j<COL_A_REN_B; j++){
			cout<<"\n Elemento "<<i<<j<<" de A:";
			cin>>A[i][j];
     	}
     	
     	for (int i=0; i<COL_A_REN_B; i++)
     	for (int j=0; j<COL_B; j++){
     	
		    cout<<"\n Elemento "<<i<<j<<" de B:";
			cin>>B[i][j];		
		}
		
		for (int i=0; i<REN_A; i++)
     	for (int j=0; j<COL_B; j++){
		 
     	    C[i][j]=0;
     	    
	     	for (int k=0; k<COL_A_REN_B; k++){
			
	     	    C[i][j]+=A[i][k]*B[k][j];
	     	    
	     	    cout<<C[i][j]<<'\t';
	 	    }		 
	
			cout<<endl;		
    	}
}
		
	
