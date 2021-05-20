#include <iostream>
#include<vector>
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

void maior_menor_dc(vector<int>& A, int menor, int maior, int l, int r){
	if(r==l){
		menor = A[l];
		maior = A[l];
	}else{
		if(r-l==1){
			if(A[l]<=A[r]){
				menor = A[l];
				maior = A[r];
			}else{
				menor = A[r];
				maior = A[l];
			}
		}else{
			int menor2, maior2;
			maior_menor_dc(A, menor, maior, l, (l+r)/2);
			maior_menor_dc(A, menor2, maior2, ((l+r)/2)+1, r);
			if(menor2<menor)
				menor = menor2;
			if(maior2> maior)
				maior = maior2;
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
	maior_menor_dc(a,);
	
	return 0;
}
