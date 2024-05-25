//
// Created by Rafael on 07/05/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "Grafo.h"
#include "Matriz.h"


class Utils {

public:
    //Funções para grafos
    static bool grafoVetorEhValido(Grafo* g, bool* v);
    static bool graficoMatricialEhValido(Grafo *g, bool ** m);
    static bool conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v);
    static bool conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v);
    static void imprimirGrafo(Grafo* g);
    static void imprimirGrafoVetor(Grafo* g,bool * v);

    //Funções para Matrizes
    static void imprimirMatriz(Matriz* m, string nome);
    static void imprimirOperacaoDeMatrizes(Matriz *mA, Matriz *mB, Matriz *mC, char operacao);
    static void imprimirMatrizVetorizada(int *v, int n);


};


#endif //UTILS_H
