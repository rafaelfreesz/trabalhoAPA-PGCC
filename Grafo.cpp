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

void Grafo::imprimirGrafo() {
    cout<<"Ordem: "<<this->ordem<<endl;
    cout<<"Grau: "<<this->grau<<endl;
    cout<<"Matriz de Adjacencia: "<<endl;

    for(int i=0;i<this->ordem;i++) {
        for (int j=0;j<this->ordem;j++) {
            cout<<this->adjacencia[i][j]<<" ";
        }
        cout<<endl;
    }

}
