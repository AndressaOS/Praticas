#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

void maior_menor_rapido(vector<int>& A){
	
	int maior, menor, qntPares, extra=0;
	
	if(A.size()>2){
		qntPares = A.size()/2;
		
		extra = A.size()%2;
				
		if(A[0]>A[1]){
			maior = 0;
			menor = 1; 
		}else{
			maior = 1;
			menor = 0; 
		}
		
		for(int i=1; i<qntPares-1; i++){
			if(A[i*2]>A[(i*2+1)]){
				if( A[i*2]> A[maior]){
					maior = i*2;
				}
				if(A[i*2+1]< A[menor]){
					menor = i*2+1;
				}
					
			}else{
				if( A[i*2+1]> A[maior]){
					maior = i*2+1;
				}
				if(A[i*2]< A[menor]){
					menor = i*2;
				}
				
			}
			
		}
		
		if (extra ==1){
			if( A[qntPares*2]> A[maior]){
					maior = qntPares*2;
				}
			else{
			
			if(A[qntPares*2]< A[menor]){
					menor = qntPares*2;
			}}
		}
		
		cout<< "\nO maior esta na posicao: " << maior;
		cout<< "\nO menor esta na posicao: " << menor;
		
		
	}
}

void maior_menor_dc(vector<int>& A, vector<int>& minMax, int l, int r){
 
	if(r==l){
		minMax[0]= l;
		minMax[1] = l;
		
	}else if((r-l)==1){ 
			
			if(A[l]<=A[r]){
				
				minMax[0] = l;
				minMax[1] = r;
			}else{
				
				minMax[0] = r;
				minMax[1] = l;
			
			} 
			
	}
	else if((r-l)>1){
			vector<int> minMax2;
			minMax.push_back(0);
			minMax2.push_back(0);
			
			maior_menor_dc(A, minMax, l, floor((l+r)/2));
			
			maior_menor_dc(A, minMax2, floor((l+r)/2)+1, r);
		
			if(A[minMax2[0]]<A[minMax[0]]){
				minMax[0] = minMax2[0];
			}
			if(A[minMax2[1]]>A[minMax[1]]){
				minMax[1] = minMax2[1];
			}
	}
		



}

void maior_menor_fb(vector<int>& A){
	int maior, menor;
	
		if(A.size()>2){
			
			if(A[0]>A[1]){
				maior = 0;
				menor = 1; 
			}else{
				maior = 1;
				menor = 0; 
			}
			
			for(int i=2; i< A.size(); i++){
				if(A[i]>A[maior]){
					maior = i;
				}else{
					if(A[i]<A[menor]){
						menor = i;
					}
				}
			}
			
		cout<< "\nO maior esta na posicao: " << maior;
		cout<< "\nO menor esta na posicao: " << menor;
		
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
	
	maior_menor_rapido(a);
	maior_menor_fb(a);
 	
	vector<int> minMax;
	minMax.push_back(0);
	minMax.push_back(0);
 	
 	maior_menor_dc(a, minMax, 0, (a.size()-1));
 	
 	cout<< "\nO maior esta na posicao: " << minMax[1];
	cout<< "\nO menor esta na posicao: " << minMax[0];
	
	return 0;
}
