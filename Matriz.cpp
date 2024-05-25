//
// Created by Rafael on 25/05/2024.
//

#include "Matriz.h"

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

Matriz * Matriz::somarMatrizes(Matriz *mA, Matriz *mB) {
    Matriz* mC = new Matriz(mA->n);

    for(int i=0;i<mC->n;i++) {
        for(int j=0;j<mC->n;j++) {
            mC->m[i][j] = mA->m[i][j] + mB->m[i][j];
        }
    }

    return mC;
}

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
