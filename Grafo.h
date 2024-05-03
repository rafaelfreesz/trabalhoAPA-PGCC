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

    void imprimirGrafo();

    //Atributos
    int grau; //quantidade de arestas próprias
    int ordem; //quantidade de vertices;
    bool** adjacencia; //Matriz de adjacencia binária






};



#endif //GRAFO_H
