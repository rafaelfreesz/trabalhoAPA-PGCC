#include <iostream>
#include "Grafo.h"


using namespace std;

int main()
{
    srand(0);

    Grafo* grafo = Grafo::gerarGrafoOrdemCem();

    bool* grafoVetorizado = grafo->gerarRepresentacaoVetorial();


    delete grafoVetorizado;

    grafo->imprimirGrafo();

    return 0;
}

