#include <iostream>
#include <vector>

using namespace std;

// Algoritmo que dado um conjunto de pontos S calcula a sua casca convexa (convex_hull)

struct Ponto{
	int x, y;
	};
	
vector<Ponto> pontosCasca;

	
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
				return -1;
	}
	
}



int main(int argc, char** argv) {
	
	vector <Ponto> pontos;
	Ponto p1, p2, p3, p4, p5, p6;
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
	
	if(pontos.size()>3){

		//verifica o elemento mais a esquerda
		int posicao = 0;
    	for (int i = 1; i < pontos.size(); i++){
    		if (pontos[i].x < pontos[posicao].x)
           		posicao= i;
		}
		if(posicao!=0){
			Ponto aux;
			aux = pontos[0];
			pontos[0]= pontos[posicao];
			pontos[posicao]=aux;
			pontosCasca.push_back(pontos[posicao]);
	      
		}else{
			pontosCasca.push_back(pontos[0]);
		}
	
		
		  
	
		int valorAnterior, valorAtual, p1;
		for(int i=0; i<pontos.size(); i++){
			
					
			for(int j=i+1; j<pontos.size(); j++){
				printf("\n 1 ( %d , %d  ) 2 ( %d , %d  ) ", pontos[i].x, pontos[i].y, pontos[j].x, pontos[j].y  );
				valorAnterior=-2;
				
			
					for(int k=0; k<pontos.size(); k++){
						
						if(k!=j && k!=i){
							
							printf("\n 3 ( %d , %d  )", pontos[k].x, pontos[k].y );
							valorAtual = verificaPonto(pontos[i], pontos[j], pontos[k]);
							printf("\n i %d j %d k %d", i, j, k);
							printf(" %d \n", valorAtual);
								printf(" %d ", valorAnterior);
				
				   		if(valorAnterior==-2){
							valorAnterior= verificaPonto(pontos[i], pontos[j], pontos[k]);
						}else{
						
							if((valorAnterior!=valorAtual) && (valorAnterior!=0 && valorAtual!=0) && valorAnterior!=-2){
								  valorAnterior=3;
								  
									printf("oi");
								//	break;
							
							}				
							else{
									valorAnterior= valorAtual;
								}
						}
					/*	if(verificaPonto(pontos[i], pontos[j], pontos[k])==0){		
						printf("oi /n");						
							pontosCasca.push_back(pontos[j]);
							pontosCasca.push_back(pontos[k]);
												
						}*/
						}
					
				
				}	p1=j;
				
				printf("fim %d", valorAnterior);
				if(valorAnterior!=3){
						printf(" %d tt \n", valorAnterior);
						pontosCasca.push_back(pontos[p1]);
						
									
				}
			
			} 
				
		}
		
		for(int i=0; i<pontosCasca.size();i++){
	
		printf("\n Ponto ( %d , %d )", pontosCasca[i].x, pontosCasca[i].y);
		}
	}
		
	
	
	else
	printf("Quantidade de pontos insuficiente.\n");
	
	
	
	
	
	
	return 0;
}
