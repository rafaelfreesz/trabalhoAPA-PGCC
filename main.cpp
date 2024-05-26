#include <iostream>
#include "Grafo.h"
#include "Matriz.h"
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

    cout<<"Gerando duas matrizes simetricas: mA, mB"<<endl<<endl;
    Matriz* mA=Matriz::geraMatrizSimetricaOrdemK(k,0,5);
    Matriz* mB=Matriz::geraMatrizSimetricaOrdemK(k,0,5);
    Utils::imprimirMatriz(mA, "mA");
    Utils::imprimirMatriz(mB, "mB");

    cout<<"Soma das Matrizes"<<endl;
    Matriz* mC=Matriz::somarMatrizes(mA,mB);
    Utils::imprimirOperacaoDeMatrizes(mA,mB,mC, '+');
    cout<<endl;

    cout<<"Multiplicacao das Matrizes"<<endl;
    Matriz* mD=Matriz::multiplicarMatrizes(mA,mB);
    Utils::imprimirOperacaoDeMatrizes(mA,mB,mD, '*');
    cout<<endl;

    cout<<"Vetorizando as matrizes:"<<endl;
    int* mVA = mA->gerarRepresentacaoVetorial();
    int* mVB = mB->gerarRepresentacaoVetorial();

    Utils::imprimirMatrizVetorizada(mVA,k);
    Utils::imprimirMatrizVetorizada(mVB,k);
    cout<<endl;

    cout<<"Somando matrizes representadas por vetores"<<endl;
    int* mVC = Matriz::somarMatrizesVetorizadas(k,mVA, mVB);
    Utils::imprimirOperacaoDeMatrizesVetorizadas(k,mVA,mVB,mVC,'+');
    cout<<endl<<endl;

    cout<<"-----Avaliando validade da operacao de Soma-----"<<endl;
    if(!Utils::EhValidaSomaMatrizVetorial(mA,mB,mC,mVA,mVB,mVC)) {
        cout<<"Algum valor não é válido na conversão"<<endl;
        exit(100);
    }
        cout<<endl<<"Soma ok!"<<endl;

    cout<<endl<<endl;

    Utils::imprimirMatriz(mD,"md");
    cout<<"Multiplicando matrizes representadas por vetores"<<endl;
    int* mVD = Matriz::multiplicarMatrizesVetorizadas(k,mVA, mVB);
    Utils::imprimirOperacaoDeMatrizesVetorizadas(k,mVA,mVB,mVD,'*');
    cout<<endl;

    cout<<"-----Avaliando validade da operacao de Multiplicacao-----"<<endl;
    if(!Utils::EhValidaMultiplicacaoMatrizVetorial(mD,mVD)) {
        cout<<"Algum valor nao e valido na conversao"<<endl;
        exit(100);
    }
    cout<<endl<<"Multiplicacao ok!"<<endl;

    cout<<endl<<endl;



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
    return 0;
}

