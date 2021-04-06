//Baseado no algoritmo disponivel em : https://gist.github.com/marcoscastro/7951eb79467c892f3e63
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack> 

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
vector <int> pilha;



int buscaEmProfundidade(int v, string vertice){
	stack<int> pilha;
	while(true)	{
		if(!JaVisitado[v]){
			cout << "Vertice "<< Vertices[v]<<"\n";
			JaVisitado[v] = 1; 
			pilha.push(v); // insere "v" na pilha
		}
 
		bool achou = false;
	int i;
		
			for(i=0; i<NumVertices; i++){
	
    			if(MatrizDeAdjacencias[v][i]!=0){
    				
    				int comparacao = Vertices[i].compare(vertice);
    			
    				if((comparacao!=0) && !JaVisitado[i]){
    						
    				   	achou = true;
						break;
    				
					}
    				
    				else{
						
    						if (comparacao==0){  
									cout << "Vertice "<< Vertices[i]<<"\n"	;				
    						
    								return i;
						}
    					}
    			
				}
    	
			}
 
		if(achou)
			v = i; 
		else{
		
			pilha.pop();
		
			if(pilha.empty())
				break;
			
			v = pilha.top();
		}
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
	
	int i = buscaEmProfundidade(0, "F");

	if (i!=-1){
		cout << "\nO elemento foi encontrado na posicao " << i;
	}else{
		cout << "\nO elemento nao foi encontrado." ;
	}
	return 0;
}
