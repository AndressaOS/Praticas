#include <iostream>
#include<vector>
using namespace std;

void geraSubconjuntos(int numero){
	String L, L1, L2;
	if(n==1){
		L="01";
	}else{
		L1= geraSubconjuntos(n-1);
		L1="0"+L1;
		L2="1"+L2;
		L=L1+L2;
	}
	
	
}

int main(int argc, char** argv) {
	
	
	return 0;
}
