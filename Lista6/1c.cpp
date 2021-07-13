#include <iostream>
#include <vector>
using namespace std;

void IniciaFibonacci(vector<int> &fibo, int x){
	
	fibo.push_back(0);
	fibo.push_back(1);
	fibo.push_back(1);
	
	for (int i=3; i<=x; i++){
		fibo.push_back(-1);
	}
}

int Fibonacci(vector<int> &fibo, int x){
		
	if (fibo[x]==-1){
		fibo[x]= Fibonacci(fibo, x-1) + Fibonacci(fibo, x-2);
	}else{
		return fibo[x];
	}
	
}

int main(int argc, char** argv) {
	
	vector<int> fibo;
	
	int x = 5; 
	
	IniciaFibonacci(fibo, x);
	cout<< "O nesimo numero e: "<<	Fibonacci(fibo, x);
	return 0;
}
