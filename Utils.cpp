//
// Created by Rafael on 07/05/2024.
//

#include "Utils.h"

//Testa se a versão vetoria do grafo atende as expectativas
bool Utils::grafoVetorEhValido(Grafo *g, bool *v) {

    cout<<"--------Testando representacao vetoria:--------"<<endl;
    bool valido = true;

    for(int i=0;i<g->ordem;i++) {
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                cout<<"***** M["<<i<<","<<j<<"] != V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
                valido = false;
            }else {
                cout<<"M["<<i<<","<<j<<"] = V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
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

bool Utils::conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v) {

    cout<<"--------Testando validade dos converdores de indice de Matriz pra Vetor (valor(indice do vetor)) ---------"<<endl;

    cout<<"Indice | MAT | PA IT REC | iPA iIT iREC"<<endl;
    bool valido = true;
    for(int i=0;i<g->ordem;i++) {

        for(int j=0; j<g->ordem; j++) {
            cout<<"("+to_string(i)+","+to_string(j)+")      "+to_string(g->adjacencia[i][j])+"    ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialPA(i,j)])+" ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialIt(i,j)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialIt(i,j)])+ " ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialRec(i,j,0)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialRec(i,j,0)])+"       ";

            cout<<to_string(g->getIndiceRepresentacaoVetorialPA(i,j))+" ";
            cout<<to_string(g->getIndiceRepresentacaoVetorialIt(i,j))+" ";
            cout<<to_string(g->getIndiceRepresentacaoVetorialRec(i,j,0));

            cout<<endl;

        }

    }

    cout<<"--------------------"<<endl<<endl;
    return valido;
}

bool Utils::conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v) {

    cout<<"--------Testando validade dos converdores de indice de Vetor pra Matriz (valor(indice do vetor)) ---------"<<endl;

    cout<<"Indice | VET | SQ IT | iSQ iIT"<<endl;
    bool valido = true;
    int nVetor = (g->ordem*(g->ordem+1))/2;

    int coordenadas[2];
    for(int k=0;k<nVetor;k++) {
        cout<<to_string(k)+" ";
        g->getIndiceRepresentacaoMatricialSQ(v,k, coordenadas);

        if(g->adjacencia[coordenadas[0]][coordenadas[1]] != v[k]) {
            cout<<"*";
            valido = false;
        }
        cout<<"("+to_string(g->adjacencia[coordenadas[0]][coordenadas[1]])+" ";
        cout<<endl;
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
void Utils::imprimirGrafoVetor(Grafo *g, bool *v) {
    cout<<"--------REPRESENTACAO VETORIAL DO GRAFO--------"<<endl;
    
    int nVetor = (g->ordem*(g->ordem+1))/2;
    
    for(int i=0;i<nVetor;i++) {
        cout<<v[i]<<" ";
    }cout<<endl;

    
    cout<<"--------------------"<<endl<<endl;
}