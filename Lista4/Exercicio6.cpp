#include <iostream>
#include<vector>
using namespace std;

int LomutoPartition(vector<int>& A, int l, int r){
	int p=A[r];
	int s=l-1;
	for(int i= l; i<=r-1; i++){
		if(A[i]<=p){
			s++;
			swap(A[s], A[i]);
		}
	}
	swap(A[s+1], A[r]);
	return (s+1);
}

void QuickSort(vector<int>& A, int l, int r){
	if(l< r){
		int s = LomutoPartition(A, l, r);
		QuickSort(A, l, s-1);
		QuickSort(A, s+1, r);
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
	
	QuickSort(a, 0, a.size()-1);
	
	for(int i=0; i<a.size(); i++)
		cout<<"\n"<<a[i];
	
	return 0;
}
