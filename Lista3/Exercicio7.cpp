#include <iostream>
#include<vector>
#include <numeric>
using namespace std;

int moedaFalsa(vector<int>& a, int l, int r) {
	int moedaF = 0; 
	if ((r - l) == 1) {
		return l;
	}
	else {
		
		int resto=0;
		
		if((r - l)%2==1){
			resto = r;
			r--;
		}
		
		int metade = (r - l) / 2;	
		
		int peso1=0, peso2=0;
		
		for(int i=l; i<(l+metade); i++)
			peso1 +=a[i];
	
		for(int i=(l+metade); i<r; i++)
			peso2 +=a[i];
	
		if (peso1 > peso2) {
			moedaF = moedaFalsa(a, l, l+metade);
		}
		else if (peso2 > peso1) {
			moedaF = moedaFalsa(a, l+metade, r);
		}
		else {
			return moedaF = resto;
		}

	}

	return moedaF;

}

int main(int argc, char** argv) {
	vector<int> a;
	
	/*//Teste 1
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(2);*/
	
	/*//Teste 2
	a.push_back(3);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);*/

	//Teste 3
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	
	int moeda=moedaFalsa(a, 0, a.size()-1);
	
	cout<<"\nA moeda falsa esta na posicao "<< moeda;
	
	return 0;
}
