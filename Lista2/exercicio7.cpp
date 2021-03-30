//Algoritmo baseado no https://www.geeksforgeeks.org/travelling-salesman-problem-implementation-using-backtracking/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
#define NumeroDeCidades 4


//Teste 1
  	/*
    int MatrizDeDistancias[NumeroDeCidades][NumeroDeCidades] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };*/
    
   //Teste 2
  	/*
    int MatrizDeDistancias[NumeroDeCidades][NumeroDeCidades] = {
        { 0, 10, 5, 20 },
        { 10, 0, 25, 25 },
        { 5, 25, 0, 30 },
        { 20, 25, 30, 0 }
    };*/
    
    //Teste 3
  	
    int MatrizDeDistancias[NumeroDeCidades][NumeroDeCidades] = {
        { 0, 12, 10, 20 },
        { 12, 0, 23, 25 },
        { 10, 23, 0, 30 },
        { 20, 25, 30, 0 }
    };
	vector<bool> FoiVisitado(NumeroDeCidades);


void cicloHamiltoniano( int posicaoAtual, int numCidadesVisitas, int custoMinimo, int& total)
{
  
    if (numCidadesVisitas == NumeroDeCidades && MatrizDeDistancias[posicaoAtual][0]) {
        total = min(total, custoMinimo + MatrizDeDistancias[posicaoAtual][0]);
        return;
    }
    
    for (int i = 0; i < NumeroDeCidades; i++) {
        if (!FoiVisitado[i] && MatrizDeDistancias[posicaoAtual][i]) {
           
            FoiVisitado[i] = true;
            cicloHamiltoniano(  i,  numCidadesVisitas + 1, custoMinimo + MatrizDeDistancias[posicaoAtual][i], total);
            FoiVisitado[i] = false;
        }
    }
};

int main(int argc, char** argv) {
	
   
     
    for (int i = 0; i < NumeroDeCidades; i++)
        FoiVisitado[i] = false;
  
  
    FoiVisitado[0] = true;
    
    int total = INT_MAX;
  
    cicloHamiltoniano ( 0, 1, 0, total);
        
    printf( " A distancia minima a ser percorrida e %d", total);
  
    return 0;
	

}
