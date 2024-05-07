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

    void incluirAresta(int i, int j);


    //Atributos
    int grau; //quantidade de arestas próprias
    int ordem; //quantidade de vertices;
    bool** adjacencia; //Matriz de adjacencia binária

    static Grafo * gerarGrafoOrdemCem(); //Questão 1
    bool* gerarRepresentacaoVetorial(); //Questão 3
    int getIndiceRepresentacaoVetorial(int i, int j); //Questão 4
    bool** gerarRepresentacaoMatricial(bool* v);






};



#endif //GRAFO_H
