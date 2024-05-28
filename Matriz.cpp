//
// Created by Rafael on 25/05/2024.
//

#include "Matriz.h"

//Construtores e Destrutores
Matriz::Matriz(int n) {
    this->m=new int*[n];
    for(int i=0;i<n;i++) {
        this->m[i]=new int[n];
    }
    this->n=n;
}

Matriz::~Matriz() {
    for(int i=0;i<this->n;i++) {
        delete[] this->m[i];
    }
        delete[] this->m;
}

//Funcoes e Metodos
//Retorna true se a matriz for simetrica
bool Matriz::ehSimetrica() {
   for(int i=0;i<this->n;i++) {
       for(int j=i+1;j<this->n;j++) {
           if(this->m[i][j]!=this->m[j][i]) {
               return false;
           }
       }
   }
   return true;
}

//Gera matriz de uma dada ordem k com valores entre min e max
Matriz * Matriz::geraMatrizSimetricaOrdemK(int n, int min, int max) {
    Matriz* m = new Matriz(n);

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            m->m[i][j]= min+rand()%(max-min);
            m->m[j][i]= m->m[i][j];
        }
    }
    return m;
}

//Soma duas matrizes mA e mB
Matriz * Matriz::somarMatrizes(Matriz *mA, Matriz *mB) {
    Matriz* mC = new Matriz(mA->n);

    for(int i=0;i<mC->n;i++) {
        for(int j=0;j<mC->n;j++) {
            mC->m[i][j] = mA->m[i][j] + mB->m[i][j];
        }
    }

    return mC;
}

//Multiplica duas matrizes mA e mB
Matriz *Matriz::multiplicarMatrizes(Matriz *mA, Matriz *mB) {
    Matriz* mC = new Matriz(mA->n);

    for(int i=0;i<mC->n;i++) {
        for(int j=0;j<mC->n;j++) {
            int s=0;
            for(int p=0;p<mC->n;p++) {
                s+=mA->m[i][p]*mB->m[p][j];
            }
            mC->m[i][j] = s;
        }
    }

    return mC;
}

//Soma suas matrizes simetricas, dadas representações vetoriais de sua parte triangular superior
int * Matriz::somarMatrizesVetorizadas(int ordem, int *mVA, int *mVB) {
    int* mVC = new int[(ordem*(ordem+1))/2];

    for(int i=0;i<ordem;i++) {
        for(int j=i;j<ordem;j++) {
            mVC[getIndiceRepresentacaoVetorialPA(i,j, ordem)]
            = mVA[getIndiceRepresentacaoVetorialPA(i,j, ordem)]
            + mVB[getIndiceRepresentacaoVetorialPA(i,j, ordem)];
        }
    }

    return mVC;
}

//Multiplica duas matrizes simetricas, dadas representações vetoriais de sua parte triangular superior
int * Matriz::multiplicarMatrizesVetorizadas(int ordem, int *mVA, int *mVB) {
    int* mVC = new int[ordem*ordem];

    for(int i=0;i<ordem;i++) {
        for(int j=0;j<ordem;j++) {
            int s=0;
            for(int p=0;p<ordem;p++) {
                s+=mVA[getIndiceRepresentacaoVetorialPA(i,p, ordem)]*mVB[getIndiceRepresentacaoVetorialPA(p,j, ordem)];
            }
            mVC[getIndiceRepresentacaoVetorialNaoSimetrica(i,j, ordem)] = s;
        }
    }

    return mVC;
}

//Transforma uma matria simetrica em sua versao vetorial triangular superior
int * Matriz::gerarRepresentacaoVetorial() {
    int nVetor = (n*(n+1))/2;

    int* matrizVetorizada = new int[nVetor];

    int linha=0;
    int coluna=0;

    for(int i=0;i<nVetor;i++) {
        matrizVetorizada[i]=this->m[linha][coluna];

        if(coluna == this->n-1) {
            linha ++;
            coluna = linha;
        }else {
            coluna++;
        }

    }

    return matrizVetorizada;
}

//Transforma (i,j) em k, onde M(i,j) = V[k] e M eh simetrica através do método da PA
int Matriz::getIndiceRepresentacaoVetorialPA(int i, int j, int n) {
    int linha = min(i,j);
    int coluna = max(i,j);
    return ((2*n - linha + 1)*linha/2 + (coluna-linha));
}

//Transforma (i,j) em k, onde M(i,j) = V[k] para matriz nao simetrica.
int Matriz::getIndiceRepresentacaoVetorialNaoSimetrica(int i, int j, int n) {
    return i*n+j;
}

