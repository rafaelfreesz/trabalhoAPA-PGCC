#include <iostream>
#include "Grafo.h"
#include "Utils.h"


using namespace std;

int main()
{
    srand(0);

    Grafo* grafo = Grafo::gerarGrafoOrdemCem();

    Utils::imprimirGrafo(grafo);

    bool* vetor = grafo->gerarRepresentacaoVetorial(); //Questão 4

    Utils::imprimirGrafoVetor(grafo,vetor);

    if(!Utils::grafoVetorEhValido(grafo,vetor)) {
        cout<<"Grafo gerado em representação vetorial nao e valido"<<endl;
        exit(1);
    }

    cout<<"Grafo gerado em representacao vetorial ok"<<endl<<endl;


    bool** matriz = grafo->gerarRepresentacaoMatricial(vetor);

    if(!Utils::graficoMatricialEhValido(grafo,matriz)) {
        cout<<"Grafo gerado em matriz a partir de vetor nao e valido"<<endl;
        exit(1);
    }

    cout<<"Grafo gerado em matriz a partir de vetor ok"<<endl<<endl;


    if(!Utils::conversoesDeIndiceMatrizVetorSaoValidas(grafo,vetor)) {
        cout<<"Conversores de indice de Matriz para Vetor nao sao validos"<<endl;
        exit(1);
    }

    cout<<"Conversores de indice de Matriz para Vetor ok"<<endl<<endl;


    if(!Utils::conversoesDeIndiceVetorMatrizSaoValidas(grafo,vetor)) {
        cout<<"Conversores Matriz Vetor nao sao validos"<<endl;
        exit(1);
    }

    cout<<"Conversores Vetor Matriz ok"<<endl<<endl;

    //Gerando duas matrizes e sua soma
    int k=5;

    cout<<"Gerando tres matrizes simetricas: A, B, C=(A+B)"<<endl<<endl;
    int** mA=Utils::geraMatrizSimetricaOrdemK(k,0,5);
    int** mB=Utils::geraMatrizSimetricaOrdemK(k,0,5);
    Utils::imprimirMatriz(k,mA, "m1");
    Utils::imprimirMatriz(k,mB, "m2");

    cout<<"Soma das Matrizes"<<endl;
    int** mC=Utils::somarMatrizes(k,mA,mB);
    Utils::imprimirOperacaoDeMatrizes(mA,mB,mC,k, '+');
    cout<<endl;

    cout<<"Multiplicacao das Matrizes"<<endl;
    int** mD=Utils::multiplicarMatrizes(k,mA,mB);
    Utils::imprimirOperacaoDeMatrizes(mA,mB,mD,k, '*');
    cout<<endl;





    for(int i=0;i<grafo->ordem;i++) {
        delete [] matriz[i];
    }
    delete [] matriz;
    for(int i=0;i<k;i++) {
        delete mA[i];
        delete mB[i];
        delete mC[i];
    }
    delete [] mA;
    delete [] mB;
    delete [] mC;
    delete [] vetor;
    delete grafo;
    return 0;
}

