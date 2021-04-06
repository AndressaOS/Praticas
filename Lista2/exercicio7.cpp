//Algoritmo baseado no https://www.geeksforgeeks.org/travelling-salesman-problem-greedy-approach/
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
	vector<int> FoiVisitado(NumeroDeCidades);

	


void caixeiroViajante()
{
	
    int soma = 0;
    int cont = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    FoiVisitado[0] = 1;
    int rota[NumeroDeCidades];

   
    while (i < NumeroDeCidades && j < NumeroDeCidades)
    {
 
       
        if (cont >= NumeroDeCidades - 1)
        {
            break;
        }
 
        
        if (j != i && (FoiVisitado[j] == 0))
        {
            if (MatrizDeDistancias[i][j] < min)
            {
                min = MatrizDeDistancias[i][j];
                rota[cont] = j + 1;
            }
        }
        j++;
 
      
        if (j == NumeroDeCidades)
        {
            soma += min;
            min = INT_MAX;
            FoiVisitado[rota[cont] - 1] = 1;
            j = 0;
            i = rota[cont] - 1;
            cont++;
        }
    }
 
   
    i = rota[cont - 1] - 1;
 
    for (j = 0; j < NumeroDeCidades; j++)
    {
 
        if ((i != j) && MatrizDeDistancias[i][j] < min)
        {
            min = MatrizDeDistancias[i][j];
            rota[cont] = j + 1;
        }
    }
    soma += min;
    
     for (j = 0; j < NumeroDeCidades; j++)
    {
 
         cout << "\n"<< rota[j];
    }
 
    cout << ("O menor custo é : ");
    cout << (soma);

   	
}
int main(int argc, char** argv) {
     
    for (int i = 0; i < NumeroDeCidades; i++)
        FoiVisitado[i] = 0;
  
  
   caixeiroViajante();
   
  
    return 0;
	

}
