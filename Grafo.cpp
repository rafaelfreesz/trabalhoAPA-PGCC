//
// Created by Rafael on 03/05/2024.
//

#include "Grafo.h"

#include <cmath>

//Construtores e Destrutores
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

//Funções e Metodos
//Inclui aresta entre os nos i,j
void Grafo::incluirAresta(int i, int j) {

    if(i==j){ cout<<"Laço não permitido"<<endl; return; }

    if(this->adjacencia[i][j]) { cout<<"Multiaresta não permitido"<<endl; return; }

    this->adjacencia[i][j] = true;
    this->adjacencia[j][i] = true;
    this->grau++;

}

//Gera um grafo aleatorio de ordem parametrizada
Grafo * Grafo::gerarGrafoOrdemK(int ordem) {

    Grafo* grafo = new Grafo(ordem);

    int grau =ordem*(1+rand()%10);

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

//Transforma a matriz de adjacencias binária simétrica em um vetor com a parte triangular superior
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

//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do da PA)
int Grafo::getIndiceRepresentacaoVetorialPA(int i, int j) {
    int linha = min(i,j);
    int coluna = max(i,j);
    return ((2*this->ordem - linha + 1)*linha/2 + (coluna-linha));
}

//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do Iterativo)
int Grafo::getIndiceRepresentacaoVetorialIt(int i, int j) {
    int linha = min(i,j);
    int coluna = max(i,j);

    int k = coluna;
    for(int l=0; l<linha; l++) {
        k+=this->ordem-l-1;
    }
    return k;
}

//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do Recursivo)
int Grafo::getIndiceRepresentacaoVetorialRec(int i, int j, int l) {
    int linha = min(i,j);
    int coluna = max(i,j);

    if(linha==l) {
        return coluna;
    }else {
        return this->ordem-l-1+getIndiceRepresentacaoVetorialRec(linha,coluna,l+1);
    }
}

//Converte uma posição k do vetor em sua respectiva posição i,j da matriz de adjacencia (mét0do Raiz Quadrada)
void Grafo::getIndiceRepresentacaoMatricialSQ(int k, int *coordenadas) {


    int linha = (2*this->ordem+1-sqrt(4*(pow(this->ordem,2))+4*this->ordem-8*k-1))/2;
    int coluna = k - (2 * this->ordem - linha + 1) * linha / 2 + linha;

    coordenadas[0] = linha;
    coordenadas[1] = coluna;

}

//Converte uma posição k do vetor em sua respectiva posição i,j da matriz de adjacencia (mét0do Iterativo)
void Grafo::getIndiceRepresentacaoMatricialIt(int k, int *coordenadas) {
    int i = 0;
    int fator = this->ordem;

    while(k-fator>=0) {
        k-=fator;
        fator--;
        i++;
    }

    int j=i+k;

    coordenadas[0]=i;
    coordenadas[1]=j;

}


//Gerando a representação matricial a partir de sua representacao vetorial
bool ** Grafo::gerarRepresentacaoMatricial(bool *v) {

    bool** m = new bool*[this->ordem];

    for(int i=0;i<this->ordem;i++) {
       m[i] = new bool[this->ordem];
    }

    for(int i=0;i<this->ordem;i++) {
        for(int j = i; j <this->ordem;j++) {
            m[j][i] = m[i][j] = v[getIndiceRepresentacaoVetorialPA(i,j)];
        }
    }

    return m;

}
