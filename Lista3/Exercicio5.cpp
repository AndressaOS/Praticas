#include <iostream>
#include<vector>
using namespace std;



int busca_binaria(vector<int>& A, int K){
	int m=0;
	int l = 0; 
	int r = A.size();
	while (l <= r){
		
		m = (l + r)/2;
		
		if (K == A[m]){
				return m;
		}
		
		else{
		
			if (K<A[m] )
				r = m - 1;
			else 
				l = m + 1;
		} 

	}
	return -1;
	
}


int main(int argc, char** argv) {
	vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(9);
	a.push_back(15);
	a.push_back(20);
	a.push_back(21);
	a.push_back(25);
	a.push_back(37);

	int i= busca_binaria(a,21 );
	
	if(i!=-1)
		cout<<"Elemento encontrado na "<<i+1<< " posicao. " ;
	else
		cout<<"Elemento nao encontrado.";
	
	return 0;
}
