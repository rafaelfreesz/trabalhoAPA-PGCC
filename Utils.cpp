//
// Created by Rafael on 07/05/2024.
//

#include "Utils.h"

//Testa se a versão vetoria do grafo atende as expectativas
bool Utils::grafoVetorialEhValido(Grafo *g, bool *v) {

    cout<<"--------Testando representacao vetoria:--------"<<endl;
    bool valido = true;

    for(int i=0;i<g->ordem;i++) {
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorial(i,j)]) {
                cout<<"***** M["<<i<<","<<j<<"] != V["<<g->getIndiceRepresentacaoVetorial(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
                valido = false;
            }else {
                cout<<"M["<<i<<","<<j<<"] = V["<<g->getIndiceRepresentacaoVetorial(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
            }
        }
    }

    cout<<"--------------------"<<endl<<endl;

     return valido;
}

bool Utils::graficoMatricialEhValido(Grafo *g, bool **m) {
    cout<<"--------Testando representacao matricial:--------"<<endl;
    bool valido = true;
    string sm1,sm2;
    for(int i=0;i<g->ordem;i++) {
        sm1="| ";
        sm2="| ";
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != m[i][j]) {
                sm1+="*";
                sm2+="*";
                valido = false;
            }

            sm1+=to_string(g->adjacencia[i][j])+" ";
            sm2+=to_string(m[i][j])+" ";
        }
        sm1+="|";
        sm2+="|";
        cout<<sm1<<"     "<<sm2<<endl;
    }

    cout<<"--------------------"<<endl<<endl;

    return valido;
}

//Imprime na tela um dado Grafo
void Utils::imprimirGrafo(Grafo *g) {
    cout<<"--------GRAFO--------"<<endl;
    
    cout<<"Ordem: "<<g->ordem<<endl;
    cout<<"Grau: "<<g->grau<<endl;
    cout<<"Matriz de Adjacencia: "<<endl;

    for(int i=0;i<g->ordem;i++) {
        for (int j=0;j<g->ordem;j++) {
            cout<<g->adjacencia[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"--------------------"<<endl<<endl;
}

//Imprime na tela a versão vetorial da matriz de adjacencia;
void Utils::imprimirGrafoVetorial(Grafo *g, bool *v) {
    cout<<"--------REPRESENTAÇÃO VETORIAL DO GRAFO--------"<<endl;
    
    int nVetor = (g->ordem*(g->ordem+1))/2;
    
    for(int i=0;i<nVetor;i++) {
        cout<<v[i]<<" ";
    }cout<<endl;

    
    cout<<"--------------------"<<endl<<endl;
}
