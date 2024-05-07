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
        cout<<"Grafo vetorial gerado nao e valido"<<endl;
        exit(1);
    }else {
        cout<<"Grafo vetorial ok"<<endl;
    }


    delete [] grafoVetorial;
    delete grafo;
    return 0;
}

