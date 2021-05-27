#include <iostream>
#include<vector>
using namespace std;

void johnson_trotter(int n){
	int numPosicoes = n;
	int dir=-1;
	vector <int> a;
	for(int i=1; i<n; i++){
		a.pushback(i);
			cout<<" - "<<i;
	}
	
	for(int i=1; i<n; i++){
		cout<<" - "<<i;
	}
	
	
	
}



int main(int argc, char** argv) {
	johnson_trotter(5);
	return 0;
}
