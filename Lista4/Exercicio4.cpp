#include <iostream>
#include<vector>
using namespace std;

int maiorElemento(vector<int>& A, int l, int r){
	int maior1, maior2;
	if(l==r){
		return l;
	}else{
		maior1= maiorElemento(A, l, (l+r)/2 ); 
		maior2= maiorElemento(A, ((l+r)/2 )+1,r); 
		
		if(A[maior1]>=A[maior2])
			return maior1;
		else
			return maior2;
	}
	
	
}
int main(int argc, char** argv) {
	
		vector<int> a;
	
	/*//Teste 1
	a.push_back(2);
	a.push_back(4);
	a.push_back(9);
	a.push_back(10);
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);*/
	
	/*//Teste 2
	a.push_back(12);
	a.push_back(8);
	a.push_back(7);
	a.push_back(10);
	a.push_back(4);
	a.push_back(3);
	a.push_back(6);
	a.push_back(13);*/

	//Teste 3
	a.push_back(22);
	a.push_back(8);
	a.push_back(7);
	a.push_back(10);
	a.push_back(47);
	a.push_back(34);
	a.push_back(26);
	a.push_back(23);
	a.push_back(2);
	
	int maior = maiorElemento(a, 0, a.size()-1);
	
	cout<<"O maior elemento esta na posicao: "<< maior;
	return 0;
}
