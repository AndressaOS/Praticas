#include <iostream>
#include<vector>
using namespace std;


/*
ALGORITHM LexicographicPermute (n)
// Gera permutações em ordem lexicográfica
// Input: Um inteiro positivo n
// Resultado: uma lista de todas as permutações de {1, ..., n} em ordem lexicográfica
inicializar a primeira permutação com 12 ... n
enquanto a última permutação tem dois elementos consecutivos em ordem crescente,
seja i seu maior índice tal que ai <ai + 1 // ai + 1> ai + 2> ...> um
encontre o maior índice j tal que ai <aj // j = i + 1 já que ai <ai + 1
trocar ai com aj // ai + 1ai + 2 ... an permanecerá em ordem decrescente
inverter a ordem dos elementos de ai + 1 para um inclusivo
adicione a nova permutação à lista */

void LexicographicPermute(int n){
	
}

int main(int argc, char** argv) {
	LexicographicPermute(5);
	return 0;
}
