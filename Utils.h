//
// Created by Rafael on 07/05/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "Grafo.h"


class Utils {

public:
    static bool grafoVetorialEhValido(Grafo* g, bool* v);
    static bool graficoMatricialEhValido(Grafo *g, bool **m);
    static void imprimirGrafo(Grafo* g);
    static void imprimirGrafoVetorial(Grafo* g,bool * v);


};


#endif //UTILS_H
