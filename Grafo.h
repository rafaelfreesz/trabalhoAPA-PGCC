//
// Created by Rafael on 03/05/2024.
//

#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>

using namespace std;
class Grafo {

public:
    //Funções
    Grafo(int ordem);
    ~Grafo();

    static Grafo * gerarGrafoOrdemK(int ordem); //Questão 1

    void incluirAresta(int i, int j);
    bool* gerarRepresentacaoVetorial(); //Questão 3
    bool** gerarRepresentacaoMatricial(bool* v); //Questão 5
    int getIndiceRepresentacaoVetorialPA(int i, int j); //Questão 6 a utilizando PA
    int getIndiceRepresentacaoVetorialIt(int i, int j); //Questão 6 b utilizando Iteratividade
    int getIndiceRepresentacaoVetorialRec(int i, int j, int l); //Questão 6 c utilizando PA
    void getIndiceRepresentacaoMatricialSQ(int k, int *coordenadas); //Questão 7 a utilizando SQ
    void getIndiceRepresentacaoMatricialIt(int k, int *coordenadas); //Questão 7 b utilizando Iteratividade

    //Atributos
    int grau; //quantidade de arestas próprias
    int ordem; //quantidade de vertices;
    bool** adjacencia; //Matriz de adjacencia binária

};



#endif //GRAFO_H
