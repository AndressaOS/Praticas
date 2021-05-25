#include <iostream>
#include<vector>
using namespace std;


void merge(vector<int> B, vector<int> C, vector<int>& A){
	int i=0, j=0, k=0;
	
	while(i<B.size() && j<C.size()){
		if(B[i]<=C[j]){
			A[k]=B[i];
			i++;
		}else{
			A[k]= C[j];
			j++;
		}
		k++;
	}
	
	if(i==B.size()){
		for (int l=j;l<C.size(); l++){
			A[k]= C[l];
			k++;
		}
	}else{
		for (int l=i;l<B.size(); l++){
			A[k]= B[l];
			k++;
		}		
	}
	
}

void mergesort(vector<int>& A){
	int metade;

	if(A.size()>1){
		metade = A.size()/2;
		vector<int> B, C;
		
		for(int i=0; i<metade; i++){
			B.push_back(A[i]);
		}
		
		for(int i=metade; i<A.size(); i++){
			C.push_back(A[i]);
		}
					
		mergesort(B);
		mergesort(C);
		merge(B, C, A);
		
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
	
	mergesort(a);
	
	for(int i=0; i<a.size(); i++)
		cout<<"\n"<<a[i];
		
	return 0;
}
