#include <iostream>
#include<vector>
using namespace std;



 void insertion_sort(vector<int>& A) {
	int v, j;
	
	for (int i=1; i< A.size(); i++){
		v = A[i];
		j = i - 1;
	
	while ((j >= 0 )and (A[j] > v )){
		A[j + 1]= A[j];
		j = j - 1;
		A[j + 1] = v;

	}
	

	}
	
	}

int main(int argc, char** argv) {
	
	vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(9);
	a.push_back(10);
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);

	insertion_sort(a);
	
	for (int i=0; i< a.size(); i++){
		cout<<"\n"<<a[i];
	}
	return 0;
}
