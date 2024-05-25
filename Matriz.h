//
// Created by Rafael on 25/05/2024.
//

#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

using namespace std;
class Matriz {
public:
    Matriz(int n);
    ~Matriz();

    bool ehSimetrica(); //Verifica se a matriz eh simetrica
    int* gerarRepresentacaoVetorial();

    static Matriz *geraMatrizSimetricaOrdemK(int n, int min, int max);
    static Matriz* somarMatrizes(Matriz* mA, Matriz* mB);
    static Matriz *multiplicarMatrizes(Matriz *mA, Matriz *mB);
    static int* somarMatrizesVetorizadas(int ordem, int* mVA, int* mVB);
    static int* multiplicarMatrizesVetorizadas(int ordem, int* mVA, int *mVB);
    static int getIndiceRepresentacaoVetorialPA(int i, int j, int n);



    int n;
    int** m;

};



#endif //MATRIZ_H
