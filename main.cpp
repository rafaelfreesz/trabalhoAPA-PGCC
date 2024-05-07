#include <iostream>
#include "Grafo.h"
#include "Utils.h"


using namespace std;

int main()
{
    srand(0);

    Grafo* grafo = Grafo::gerarGrafoOrdemCem();

    Utils::imprimirGrafo(grafo);

    bool* grafoVetorial = grafo->gerarRepresentacaoVetorial();

    Utils::imprimirGrafoVetorial(grafo,grafoVetorial);

    if(!Utils::grafoVetorialEhValido(grafo,grafoVetorial)) {
        cout<<"Grafo vetor gerado nao e valido"<<endl;
        exit(1);
    }else {
        cout<<"Grafo vetor ok"<<endl;
    }

    bool** matriz = grafo->gerarRepresentacaoMatricial(grafoVetorial);

    if(!Utils::graficoMatricialEhValido(grafo,matriz)) {
        cout<<"Grafo matriz gerado nao e valido"<<endl;
        exit(1);
    }else {
        cout<<"Grafo matriz ok"<<endl;
    }



    for(int i=0;i<grafo->ordem;i++) {
        delete [] matriz[i];
    }
    delete [] matriz;
    delete [] grafoVetorial;
    delete grafo;
    return 0;
}

