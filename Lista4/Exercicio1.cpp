#include <iostream>
#include<vector>
using namespace std;


void merge(vector<int>& A, int p, int q, int r){
	int i, j;
	int B[A.size()];
	for( i=p; i<q; i++){
		B[i]=A[i];
		
	}
	for( j=q+1; j<r; j++){
		B[r+q+1-j]=A[j];
		
	}
	i=p;
	j=r;
	
	for(int k=p; k<r; k++){
		if(B[i]<=B[j]){
			A[k]= B[i];
			i++;
		}else{
			A[k]= B[j];
			j--;
		}
	}
	
}

void mergesort(vector<int>& A, int p, int r){
	int q;
	if(p<r){
		q= (p+r)/2;
			
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		merge(A, p, q, r);
		
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
	
	mergesort(a, 0, a.size()-1);
	
	for(int i=0; i<a.size(); i++)
		cout<<"\n"<<a[i];
	return 0;
}
