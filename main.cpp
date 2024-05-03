#include <iostream>
#include "Grafo.h"


using namespace std;

int main()
{
    srand(0);

    Grafo* grafo = Grafo::gerarGrafoOrdemCem();

    grafo->imprimirGrafo();

    return 0;
}

