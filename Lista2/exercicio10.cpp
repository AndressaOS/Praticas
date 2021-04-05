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

int buscaInterna ( int pai, string vertice){
	
		for(int i=0; i<NumVertices; i++){
    			if(MatrizDeAdjacencias[elemento][i]!=0){
    				cout<< " " << Vertices[i] << "-";
    				int comparacao = Vertices[i].compare(vertice);
    				if((comparacao!=0) && !JaVisitado[i]){
    					pilha.push_back(i);
    					buscaInterna(i);
					}
    				
    				else
    					if (comparacao==0)
    					return i;
    			
				}
    	
			}
	
	
	

}

int buscaEmProfundidade( string vertice, int parada){

	vector <int> pilha;
	pilha.push_back(0);
	
	
	while( pilha.size() > 0){
	
		int elemento= pilha[0];
		JaVisitado[elemento]=1;
		cout<< "Caminho:" << Vertices[elemento];
			if(Vertices[elemento].compare(vertice)!=0){	
			for(int i=0; i<NumVertices; i++){
    			if(MatrizDeAdjacencias[elemento][i]!=0){
    				cout<< " " << Vertices[i] << "-";
    				int comparacao = Vertices[i].compare(vertice);
    				if((comparacao!=0) && !JaVisitado[i]){
    					pilha.push_back(i);
    					buscaInterna(i);
					}
    				
    				else
    					if (comparacao==0)
    					return i;
    			
				}
    	
			}
			pilha.erase(pilha.end());
		}else
			return elemento;
			
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
	
	int i = buscaEmProfundidade("F");
	if (i!=-1){
		cout << "\nO elemento foi encontrado na posicao " << i;
	}else{
		cout << "\nO elemento nao foi encontrado." ;
	}
	return 0;
}
