#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
#define NumeroDeCidades 4


void cicloHamiltoniano(int MatrizDeDistancias[NumeroDeCidades][NumeroDeCidades], vector<bool>& FoiVisitado, vector<string>& Ciclo, vector<string>& NomeCidades,int posicaoAtual, int numCidadesVisitas, int custoMinimo, int& ans)
{
  
    if (numCidadesVisitas == NumeroDeCidades && MatrizDeDistancias[posicaoAtual][0]) {
        ans = min(ans, custoMinimo + MatrizDeDistancias[posicaoAtual][0]);
        Ciclo.push_back(NomeCidades[posicaoAtual]);
        return;
    }
  
  
    for (int i = 0; i < NumeroDeCidades; i++) {
        if (!FoiVisitado[i] && MatrizDeDistancias[posicaoAtual][i]) {
           
            FoiVisitado[i] = true;
            
            cicloHamiltoniano(MatrizDeDistancias, FoiVisitado,Ciclo, NomeCidades, i,  numCidadesVisitas + 1, custoMinimo + MatrizDeDistancias[posicaoAtual][i], ans);
            FoiVisitado[i] = false;
        }
    }
};

int main(int argc, char** argv) {

  	
    int MatrizDeDistancias[NumeroDeCidades][NumeroDeCidades] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };
  
   vector<string> NomeCidades;
   NomeCidades.push_back("A");
   NomeCidades.push_back("B");
   NomeCidades.push_back("C");
   NomeCidades.push_back("D");
   
    vector<bool> FoiVisitado(NumeroDeCidades);
     vector<string> Ciclo(NumeroDeCidades);
     
     
    for (int i = 0; i < NumeroDeCidades; i++)
        FoiVisitado[i] = false;
  
  
    FoiVisitado[0] = true;
    Ciclo.push_back(NomeCidades[0]);
    int ans = INT_MAX;
  
    cicloHamiltoniano (MatrizDeDistancias, FoiVisitado, Ciclo, NomeCidades, 0, 1, 0, ans);
    
     for (int i = 0; i < Ciclo.size(); i++){
     	cout << Ciclo[i];
	 }
        
  
    cout << ans;
  
    return 0;
	

}
