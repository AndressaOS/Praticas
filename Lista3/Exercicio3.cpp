#include <iostream>
#include<vector>
using namespace std;


/*
ALGORITHM LexicographicPermute (n)
// Gera permuta��es em ordem lexicogr�fica
// Input: Um inteiro positivo n
// Resultado: uma lista de todas as permuta��es de {1, ..., n} em ordem lexicogr�fica
inicializar a primeira permuta��o com 12 ... n
enquanto a �ltima permuta��o tem dois elementos consecutivos em ordem crescente,
seja i seu maior �ndice tal que ai <ai + 1 // ai + 1> ai + 2> ...> um
encontre o maior �ndice j tal que ai <aj // j = i + 1 j� que ai <ai + 1
trocar ai com aj // ai + 1ai + 2 ... an permanecer� em ordem decrescente
inverter a ordem dos elementos de ai + 1 para um inclusivo
adicione a nova permuta��o � lista */

void LexicographicPermute(int n){
	
}

int main(int argc, char** argv) {
	LexicographicPermute(5);
	return 0;
}
