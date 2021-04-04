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

int buscaEmLargura( string vertice){

	vector <int> fila;
	fila.push_back(0);
	
	
	while( fila.size() > 0){
	
		int elemento= fila[0];
		JaVisitado[elemento]=1;
			if(Vertices[elemento].compare(vertice)!=0){	
			for(int i=0; i<NumVertices; i++){
    			if(MatrizDeAdjacencias[elemento][i]!=0){
    				cout<< Vertices[i];
    				int comparacao = Vertices[i].compare(vertice);
    				if((comparacao!=0) && !JaVisitado[i])
    					fila.push_back(i);
    				else
    					if (comparacao==0)
    					return i;
    			
				}
    	
			}
			fila.erase(fila.begin());
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
	
	int i = buscaEmLargura("A");
	if (i!=-1){
		cout << "O elemento foi encontrado na posicao " << i;
	}else{
		cout << "O elemento nao foi encontrado." ;
	}
	return 0;
}
