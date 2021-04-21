#include <iostream>
#include<vector>
using namespace std;

class No{
	private:

	No *esq, *dir;
	int valor;

	public:
		
	No(int valor){
		this->valor = valor;
		esq = NULL;
		dir = NULL;
	}

	int getValor(){
		return valor;
	}

	No* getEsq(){
		return esq;
	}

	No* getDir(){
		return dir;
	}

	void setEsq(No *no){
		esq = no;
	}

	void setDir(No *no){
		dir = no;
	}	
	
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore(){
		raiz = NULL;
	}
	
	No* getRaiz(){
		return raiz;
	}

	void setRaiz(No *no){
		raiz = no;
	}
	void procuraPosicaoInserir(No *no, int valor){
			
			if(valor> no->getValor()){
				if(no->getDir()!=NULL)
					procuraPosicaoInserir(no->getDir(), valor);
				else{
					No *no1= new No(valor);
					
					no->setDir(no1);
				}
					
						
			}else{
				
				if(valor< no->getValor()){
					if(no->getEsq()!=NULL)
						procuraPosicaoInserir(no->getEsq(), valor);
					else{
					No *no2= new No(valor);
					
					no->setEsq(no2);
					}
				}else{
					cout<<"\nJa existe esse elemento. ";
				}
			}
			
		
		
	}
	
	No* procuraPosicao(No *no, int valor){
			
		if(valor== no->getValor()){
			return no;
		}else{
		
			if(valor> no->getValor()){
				if(no->getDir()!=NULL)
					procuraPosicao(no->getDir(), valor);
				else
					return NULL;
						
			}else{
						
				if(no->getEsq()!=NULL)
					procuraPosicao(no->getEsq(), valor);
				else
					return NULL;
			
			}
		}
	}
	
	void inserir(int valor){
		
		if(raiz==NULL){
			
			raiz= new No(valor);
		
		}else{
			procuraPosicaoInserir(raiz, valor);		
			
		}
	}
	
	No* buscar(int valor){
		
			if(raiz==NULL){
				return NULL;
		
			}else{
				return procuraPosicao(raiz, valor);		
			
		}	
		
		
		
	}
	
	void mostraArvore(No* no, int b) {
   		if (no == NULL) {
        
        	for (int i = 0; i < b; i++) printf("      ");
    		printf("*\n");
        	return;
    	}
			mostraArvore(no->getDir(), b+1);
			imprimeNo(no->getValor(), b);
			mostraArvore(no->getEsq(), b+1);
	}

	
	void imprimeNo(int valor, int b) {
       	for (int i = 0; i < b; i++) printf("      ");
    	printf("%d\n", valor);
	}
	
};

int main(int argc, char** argv) {
	
	Arvore arvore;
	No *no = NULL;
	
	/*
	//Teste 1
	arvore.inserir(10);
	arvore.inserir(5);
	arvore.inserir(8);
	arvore.inserir(15);
	arvore.inserir(12);
	arvore.inserir(13);
	arvore.inserir(20);
	arvore.mostraArvore(arvore.getRaiz(), 0);
	no = arvore.buscar(22);*/
	
	/*
	//Teste 2
	arvore.inserir(10);
	arvore.inserir(4);
	arvore.inserir(8);
	arvore.inserir(15);
	arvore.inserir(22);
	arvore.inserir(17);
	arvore.inserir(21);
	arvore.mostraArvore(arvore.getRaiz(), 0);
	no = arvore.buscar(8);*/
	
	//Teste 3
	arvore.inserir(30);
	arvore.inserir(40);
	arvore.inserir(38);
	arvore.inserir(15);
	arvore.inserir(22);
	arvore.inserir(17);
	arvore.inserir(21);
	arvore.mostraArvore(arvore.getRaiz(), 0);
	no = arvore.buscar(15);
	
	
	if(no!=NULL)
	cout<< "\O no "<< no->getValor()<<" foi encontrado.";
	else
	cout<< "\nO no nao foi encontrado.";
	
	
	
	
	return 0;
}
