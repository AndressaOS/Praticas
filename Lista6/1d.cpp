#include <iostream>
#include <vector>

using namespace std;

int ChangeMaking(vector<int>& data, vector<int>& moedas, int n){
	
	if(data[n-1]==-1){
		int tamanho = moedas.size();
		int troco = n; 
		int quantidade =0;
		while ((tamanho!=0)||(troco!=0)){
			int aux = troco/moedas[tamanho-1];
			troco = troco - (moedas[tamanho-1]*aux);
			quantidade+= aux; 
			tamanho--;
		}
		data [n-1]= quantidade;
				
	}else{
		return data[n-1];
	}
}

void inicializa(vector <int> &data){
    for(int i=0; i<100; i++){
        data.push_back(-1);
    }
}

int main(int argc, char** argv) {
	vector <int> moedas;
	moedas.push_back(1);
	moedas.push_back(5);
	moedas.push_back(10);
	moedas.push_back(25);
	moedas.push_back(50);
	moedas.push_back(100);
	
	vector<int> data;
	inicializa(data);
	
	int valor = 99;
	
	cout<<"\nA quantidade minima de moedas e: "<<	ChangeMaking(data, moedas, valor);
	
	return 0;
}
