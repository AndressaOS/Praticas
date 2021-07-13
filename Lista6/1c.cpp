#include <iostream>
using namespace std;

int Fibonacci(int x){
	

	if((x==0)|| (x==1))
		return 1;
	else{
		int soma = 2;
		int ant = 1;	
		for (int i=3; i<x; i++){
			int aux = soma;
			soma += ant;
			ant = aux;			
			
		}
		return soma;
	}
}

int main(int argc, char** argv) {
	
	cout<< "O nesimo numero e: "<<	Fibonacci(6);
	return 0;
}
