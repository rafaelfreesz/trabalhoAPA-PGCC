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
    static Matriz* somarMatrizes(Matriz* mA, Matriz* mB); //Questao 8a - Soma matrizes
    static Matriz *multiplicarMatrizes(Matriz *mA, Matriz *mB); //Questao 8b - Multiplica matrizes

    static int* somarMatrizesVetorizadas(int ordem, int* mVA, int* mVB);
    static int* multiplicarMatrizesVetorizadas(int ordem, int* mVA, int *mVB);
    static int getIndiceRepresentacaoVetorialPA(int i, int j, int n);
    static int getIndiceRepresentacaoVetorialNaoSimetrica(int i, int j, int n);



    int n; //Ordem da matriz
    int** m; //Matriz

};



#endif //MATRIZ_H
