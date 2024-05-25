//
// Created by Rafael on 07/05/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "Grafo.h"


class Utils {

public:
    static bool grafoVetorEhValido(Grafo* g, bool* v);
    static bool graficoMatricialEhValido(Grafo *g, bool ** m);
    static bool conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v);
    static bool conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v);
    static void imprimirGrafo(Grafo* g);
    static void imprimirGrafoVetor(Grafo* g,bool * v);

    static int** geraMatrizSimetricaOrdemK(int k,int min, int max);

    static void imprimirMatriz(int k, int** m, string nome);
    static bool ehSimetrica(int k, int** m);
    static int** somarMatrizes(int k, int** mA, int** mB);
    static int** multiplicarMatrizes(int k, int** mA, int** mB);
    static void imprimirOperacaoDeMatrizes(int** mA, int** mB, int** mC, int n, char operacao);


};


#endif //UTILS_H
