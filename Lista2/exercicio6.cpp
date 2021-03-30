#include <iostream>
#include <vector>

//Algoritmo baseado em https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/

using namespace std;


struct Ponto{
	int x, y;
	};

vector<Ponto> pontosCasca;
vector<Ponto> pontos;	


	
//verifica o lado da reta que está o ponto
int verificaPonto(Ponto PontoA, Ponto PontoB, Ponto PontoC){
int a, b, c;

a = PontoB.y - PontoA.y;
b = PontoA.x - PontoB.x;
c = (PontoA.x * PontoB.y)- (PontoB.x * PontoA.y);

int total;

total = (a * PontoC.x) + ( b * PontoC.y);

if(total>c)
	return 1;
	else {
		if(total ==c)
			return 0;
			else
				return 2;
	}
	
}

//verifica ponto mais a esquerda
int verificaPontoMaisAEsquerda(){
		int posicao = 0;
    	for (int i = 1; i < pontos.size(); i++){
    		if (pontos[i].x < pontos[posicao].x)
           		posicao= i;
		}
		if(posicao!=0){
			return posicao;
	      
		}else{
			return 0;
		}
}

void cascaConvexa(){
	if(pontos.size()>3){
		int posicao, l;
		l= verificaPontoMaisAEsquerda();
		posicao = l; 
		int q;
    do
    {
        pontosCasca.push_back(pontos[posicao]);
        q = (posicao+1)%pontos.size();
        for (int i = 0; i < pontos.size(); i++){
            if (verificaPonto(pontos[posicao], pontos[i], pontos[q]) == 2)
               q = i;
        }
        posicao = q;
  
    } while (posicao != l);  
	}	
	else{
		if(pontos.size()==3){		
			for(int i=0; i<3; i++){
				pontosCasca.push_back(pontos[i]);
			}
		}
				
		else
			printf("Quantidade de pontos insuficiente.\n");
	}
}



int main(int argc, char** argv) {
	
	
	Ponto p1, p2, p3, p4, p5, p6;
	
	//Teste 1
/*
	p1.x=1;
	p1.y=1;
	pontos.push_back(p1);
	p2.x=1;
	p2.y=5;
	pontos.push_back(p2);
	p3.x=5;
	p3.y=1;
	pontos.push_back(p3);
	p4.x=2;
	p4.y=4;
	pontos.push_back(p4);
	p5.x=5;
	p5.y=6;
	pontos.push_back(p5);
	p6.x=3;
	p6.y=2;
	pontos.push_back(p6);*/
	
	//Teste 2

	p1.x=1;
	p1.y=1;
	pontos.push_back(p1);
	p2.x=20;
	p2.y=-5;
	pontos.push_back(p2);
	p3.x=5;
	p3.y=1;
	pontos.push_back(p3);
	p4.x=20;
	p4.y=12;
	pontos.push_back(p4);
	p5.x=-30;
	p5.y=10;
	pontos.push_back(p5);
	p6.x=-30;
	p6.y=-15;
	pontos.push_back(p6);
	
	//Teste 3
	/*
	p1.x=-1;
	p1.y=-1;
	pontos.push_back(p1);
	p2.x=-1;
	p2.y=5;
	pontos.push_back(p2);
	p3.x=5;
	p3.y=1;
	pontos.push_back(p3);
	p4.x=2;
	p4.y=4;
	pontos.push_back(p4);
	p5.x=5;
	p5.y=6;
	pontos.push_back(p5);
	p6.x=3;
	p6.y=2;
	pontos.push_back(p6);*/
	
	cascaConvexa();

	for(int i=0; i<pontosCasca.size(); i++){
		printf("\n Ponto ( %d , %d )", pontosCasca[i].x, pontosCasca[i].y);
	}
		
	return 0;
}
