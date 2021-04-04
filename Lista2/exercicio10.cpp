#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

#define NumVertices 6 

int MatrizDeAdjacencias[NumVertices][NumVertices] = {
        { 0, 1, 1, 0 , 0, 0 },
        { 1, 0, 0, 1 , 1, 0 },
        { 1, 0, 0, 0 , 0, 1 },
        { 0, 1, 0, 0 , 0, 0 },
        { 0, 1, 0, 0 , 0, 0 },
        { 0, 0, 1, 0 , 0, 0 },
        
    };
vector <string> Vertices;
vector <int> JaVisitado;

int buscaEmProfundidade(string vertice){

	vector <int> pilha;
	pilha.push_back(0);
	
	
	while( pilha.size() > 0){
	
		int elemento= pilha.size()-1;
		JaVisitado[elemento]=1;
	
		
			for(int i=0; i<NumVertices; i++){
    			if(MatrizDeAdjacencias[elemento][i]!=0){
    				cout<< Vertices[i];
    				int comparacao = Vertices[i].compare(vertice);
    				if((comparacao!=0) && !JaVisitado[i])
    					pilha.push_back(i);
    				else
    					if (comparacao==0)
    					return i;
    			
				}
    	
			}
			pilha.erase(pilha.end());
		 
		
			
	}
		
	return -1;
   
 
}

int main(){
	
	Vertices.push_back("A");
	Vertices.push_back("B");
	Vertices.push_back("C");
	Vertices.push_back("D");
	Vertices.push_back("E");
	Vertices.push_back("F");
	
	for(int i=0; i<NumVertices; i++)
		JaVisitado.push_back(0);
	
	int i = buscaEmProfundidade("E");
	if (i!=-1){
		cout << "O elemento foi encontrado na posicao " << i;
	}else{
		cout << "O elemento nao foi encontrado." ;
	}
	return 0;
}
