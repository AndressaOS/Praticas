#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

//Implementação baseada no algoritmo disponível em: https://pt.wikipedia.org/wiki/Busca_em_largura

using namespace std;

 int NoEsquerdo(int posicao){
    return (2 * posicao);
 }
 int NoDireito(int posicao){
	return (2 * posicao) + 1;
 }
 
 int busca_Largura (vector<string>& ListaNos, int inicio, string letra){
    bool achou = false;
    int posicao, posicaoEncontrada, noEsq, noDir;
 
    posicao = inicio;
    posicaoEncontrada = -1;
    if (ListaNos[inicio] == letra ) {
      achou = true;
      posicaoEncontrada = inicio;
   }
    while ((!achou) && (posicao <= ListaNos.size()) ){
    	
    
      if (ListaNos[noEsq = NoEsquerdo(posicao)] == letra ){
        achou = true;
        return posicaoEncontrada = noEsq;
      } else 
	  if (ListaNos[noDir = NoDireito(posicao)] == letra) {
        achou = true;
        return posicaoEncontrada = noDir;
     }
      posicao++;
   }

}

int main(int argc, char** argv) {
	vector<string> ListaNos;
	
	
	ListaNos.push_back("R");   
  	ListaNos.push_back("G");   
  	ListaNos.push_back("Q");   
  	ListaNos.push_back("Y");   
  	ListaNos.push_back("J");  
  	ListaNos.push_back("B");    
  	ListaNos.push_back("E");  
  	ListaNos.push_back("P"); 
  
 
  cout << "\n A letra J esta no no numero: " << busca_Largura(ListaNos, 1, "B");
  cout << "\n A letra B esta no no numero: " << busca_Largura(ListaNos,1, "B");

	
	return 0;
	
}
