//
// Created by Rafael on 03/05/2024.
//

#include "Grafo.h"

Grafo::Grafo(int ordem) {
    this->grau = 0;
    this->ordem = ordem;

    this->adjacencia = new bool* [ordem];

    for(int i = 0; i<this->ordem; i++) {
        this->adjacencia[i] = new bool[ordem];
        for(int j=0; j<this->ordem; j++) {
            this->adjacencia[i][j] = false;
        }
    }


}

Grafo::~Grafo() {

    for(int i = 0; i<this->ordem; i++) {
        delete this->adjacencia[i];
    }
        delete this->adjacencia;
}

void Grafo::incluirAresta(int i, int j) {

    if(i==j){ cout<<"Laço não permitido"<<endl; return; }

    if(this->adjacencia[i][j]) { cout<<"Multiaresta não permitido"<<endl; return; }

    this->adjacencia[i][j] = true;
    this->adjacencia[j][i] = true;
    this->grau++;

}



//TODO Depois voltar pra ordem = 100 e grau = fórmula
Grafo * Grafo::gerarGrafoOrdemCem() {

    int ordem = 5;

    Grafo* grafo = new Grafo(ordem);

    int grau = 5;// ordem*(1+rand()%10);

    for(int i=0;i<grau;i++) {
        int a = rand()%grafo->ordem;
        int b = rand()%grafo->ordem;

        while(a==b || grafo->adjacencia[a][b]) {
            a = rand()%grafo->ordem; b = rand()%grafo->ordem;
        }

        grafo->incluirAresta(a,b);

    }

    return grafo;
}

//Transforma a matriz de adjacencias binária em um vetor com a parte triangular superior
bool * Grafo::gerarRepresentacaoVetorial() {

    int nVetor = (this->ordem*(this->ordem+1))/2;

    bool* grafoVetorial = new bool[nVetor];

    int linha=0;
    int coluna=0;

    for(int i=0;i<nVetor;i++) {
        grafoVetorial[i]=this->adjacencia[linha][coluna];

        if(coluna == this->ordem-1) {
            linha ++;
            coluna = linha;
        }else {
            coluna++;
        }

    }

    return grafoVetorial;
}

//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor
int Grafo::getIndiceRepresentacaoVetorial(bool *vetor, int i, int j) {
    int linha = min(i,j);
    int coluna = max(i,j);
    return ((2*this->ordem - linha + 1)*linha/2 + (coluna-linha));
}
