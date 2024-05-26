//
// Created by Rafael on 07/05/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "Grafo.h"
#include "Matriz.h"
#include <fstream>

class Utils {

public:

    Utils(long seed);
    ~Utils();


    //Funções para grafos
    bool grafoVetorEhValido(Grafo* g, bool* v);
    bool graficoMatricialEhValido(Grafo *g, bool ** m);
    bool conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v);
    bool conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v);
    void imprimirGrafo(Grafo* g);
    void imprimirGrafoVetor(Grafo* g,bool * v);

    //Funções para Matrizes
    void imprimirMatriz(Matriz* m, string nome);
    void imprimirOperacaoDeMatrizes(Matriz *mA, Matriz *mB, Matriz *mC, char operacao);
    void imprimirSomaDeMatrizesVetorizadas(int ordem, int*mVA, int*mVB, int*mVC);
    void imprimirMultiplicacaoDeMatrizesVetorizadas(int ordem, int*mVA, int*mVB, int*mVC);
    void imprimirMatrizVetorizada(int *v, int n, string nome);
    bool EhValidaSomaMatrizVetorial(Matriz *mA, Matriz *mB, Matriz *mC, int *mVA, int *mVB, int *mVC);
    bool EhValidaMultiplicacaoMatrizVetorial(Matriz *mC, int *mVC);

private:
    ofstream file;
    string fileName;


};


#endif //UTILS_H
