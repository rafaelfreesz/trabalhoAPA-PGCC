#include <iostream>
#include "Grafo.h"
#include "Matriz.h"
#include "Utils.h"


using namespace std;

int main()
{
    long seed = clock();
    Utils* u = new Utils(seed);
    srand(seed);

    cout<<"1- Gerando grafo de ordem 100...";
    Grafo* grafo = Grafo::gerarGrafoOrdemK(100);
    cout<<"ok"<<endl;

    u->imprimirGrafo(grafo);

    cout<<"2- Gerando representacao vetorial... ";
    bool* vetor = grafo->gerarRepresentacaoVetorial(); //Questão 4
    cout<<"ok"<<endl;

    u->imprimirGrafoVetor(grafo,vetor);

    cout<<"3- Verificando representacao vetorial... ";
    if(!u->grafoVetorEhValido(grafo,vetor)) {
        cout<<"Grafo gerado em representação vetorial nao e valido"<<endl;
        exit(1);
    }
    cout<<"ok"<<endl;


    cout<<"4- Gerando representacao matricial a partir do vetor... ";
    bool** matriz = grafo->gerarRepresentacaoMatricial(vetor);
    cout<<"ok"<<endl;

    cout<<"5- Verificando representacao matricial convertida a partir do vetor... ";
    if(!u->graficoMatricialEhValido(grafo,matriz)) {
        cout<<"Grafo gerado em matriz a partir de vetor nao e valido"<<endl;
        exit(1);
    }
    cout<<"ok"<<endl;

    cout<<"6- Verificando conversao de todos os indices (i,j)->k... ";
    if(!u->conversoesDeIndiceMatrizVetorSaoValidas(grafo,vetor)) {
        cout<<"Conversores de indice de Matriz para Vetor nao sao validos"<<endl;
        exit(1);
    }
    cout<<"ok"<<endl;

    cout<<"7- Verificando conversao de todos os indices k->(i,j)... ";
    if(!u->conversoesDeIndiceVetorMatrizSaoValidas(grafo,vetor)) {
        cout<<"Conversores Matriz Vetor nao sao validos"<<endl;
        exit(1);
    }
    cout<<"ok"<<endl;

    //OPERAÇÕES COM MATRIZES
    int o=5;

    cout<<"8- Gerando matriz simetricas mA...";
    Matriz* mA=Matriz::geraMatrizSimetricaOrdemK(o,0,5);
    cout<<"ok"<<endl;

    u->imprimirMatriz(mA, "mA");

    cout<<"9- Gerando matriz simetricas mB...";
    Matriz* mB=Matriz::geraMatrizSimetricaOrdemK(o,0,5);
    cout<<"ok"<<endl;

    u->imprimirMatriz(mB, "mB");

    cout<<"10- Somando as matrizes...";
    Matriz* mC=Matriz::somarMatrizes(mA,mB);
    u->imprimirOperacaoDeMatrizes(mA,mB,mC, '+');
    cout<<"ok"<<endl;

    cout<<"11- Multiplicando as Matrizes...";
    Matriz* mD=Matriz::multiplicarMatrizes(mA,mB);
    u->imprimirOperacaoDeMatrizes(mA,mB,mD, '*');
    cout<<"ok"<<endl;

    cout<<"12- Vetorizando as matrizes...";
    int* mVA = mA->gerarRepresentacaoVetorial();
    u->imprimirMatrizVetorizada(mVA,o, "mA");
    int* mVB = mB->gerarRepresentacaoVetorial();
    u->imprimirMatrizVetorizada(mVB,o, "mB");
    cout<<"ok"<<endl;


    cout<<"13- Somando matrizes representadas por vetores...";
    int* mVC = Matriz::somarMatrizesVetorizadas(o,mVA, mVB);
    u->imprimirSomaDeMatrizesVetorizadas(o,mVA,mVB,mVC);
    cout<<"ok"<<endl;

    cout<<"14- Avaliando validade da operacao de Soma...";
    if(!u->EhValidaSomaMatrizVetorial(mA,mB,mC,mVA,mVB,mVC)) {
        cout<<"Algum valor não é válido na conversão"<<endl;
        exit(100);
    }
    cout<<"ok"<<endl;

    cout<<"15- Multiplicando matrizes representadas por vetores...";
    int* mVD = Matriz::multiplicarMatrizesVetorizadas(o,mVA, mVB);
    u->imprimirMultiplicacaoDeMatrizesVetorizadas(o,mVA,mVB,mVD);
    cout<<"ok"<<endl;

    cout<<"16- Avaliando validade da operacao de Multiplicacao...";
    if(!u->EhValidaMultiplicacaoMatrizVetorial(mD,mVD)) {
        cout<<"Algum valor nao e valido na conversao"<<endl;
        exit(100);
    }
    cout<<"ok"<<endl;

    for(int i=0;i<grafo->ordem;i++) {
        delete [] matriz[i];
    }
    delete [] matriz;
    delete mA;
    delete mB;
    delete mC;
    delete mD;
    delete [] mVA;
    delete [] mVB;
    delete [] mVC;
    delete [] mVD;
    delete [] vetor;
    delete grafo;
    delete u;
    return 0;
}

