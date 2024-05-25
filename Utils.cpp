//
// Created by Rafael on 07/05/2024.
//

#include "Utils.h"

//Testa se a versão vetoria do grafo atende as expectativas
bool Utils::grafoVetorEhValido(Grafo *g, bool *v) {

    cout<<"--------Testando representacao vetoria:--------"<<endl;
    bool valido = true;

    for(int i=0;i<g->ordem;i++) {
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                cout<<"***** M["<<i<<","<<j<<"] != V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
                valido = false;
            }else {
                cout<<"M["<<i<<","<<j<<"] = V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
            }
        }
    }

    cout<<"--------------------"<<endl<<endl;

     return valido;
}

bool Utils::graficoMatricialEhValido(Grafo *g, bool **m) {
    cout<<"--------Testando representacao matricial:--------"<<endl;
    bool valido = true;
    string sm1,sm2;
    for(int i=0;i<g->ordem;i++) {
        sm1="| ";
        sm2="| ";
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != m[i][j]) {
                sm1+="*";
                sm2+="*";
                valido = false;
            }

            sm1+=to_string(g->adjacencia[i][j])+" ";
            sm2+=to_string(m[i][j])+" ";
        }
        sm1+="|";
        sm2+="|";
        cout<<sm1<<"     "<<sm2<<endl;
    }

    cout<<"--------------------"<<endl<<endl;

    return valido;
}

bool Utils::conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v) {

    cout<<"--------Testando validade dos converdores de indice de Matriz pra Vetor (valor(indice do vetor)) ---------"<<endl;

    cout<<"Indice | MAT | PA IT REC | iPA iIT iREC"<<endl;
    bool valido = true;
    for(int i=0;i<g->ordem;i++) {

        for(int j=0; j<g->ordem; j++) {
            cout<<"("+to_string(i)+","+to_string(j)+")      "+to_string(g->adjacencia[i][j])+"    ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialPA(i,j)])+" ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialIt(i,j)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialIt(i,j)])+ " ";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialRec(i,j,0)]) {
                cout<<"*";
                valido = false;
            }
            cout<<to_string(v[g->getIndiceRepresentacaoVetorialRec(i,j,0)])+"       ";

            cout<<to_string(g->getIndiceRepresentacaoVetorialPA(i,j))+" ";
            cout<<to_string(g->getIndiceRepresentacaoVetorialIt(i,j))+" ";
            cout<<to_string(g->getIndiceRepresentacaoVetorialRec(i,j,0));

            cout<<endl;

        }

    }

    cout<<"--------------------"<<endl<<endl;
    return valido;
}

bool Utils::conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v) {

    cout<<"--------Testando validade dos converdores de indice de Vetor pra Matriz (valor(indice do vetor)) ---------"<<endl;

    cout<<"Indice | VET | SQ      iSQ   | IT     iIT"<<endl;
    bool valido = true;
    int nVetor = (g->ordem*(g->ordem+1))/2;

    int coordenadas[2];
    for(int k=0;k<nVetor;k++) {
        if(k<10){cout<<" ";}
        cout<<to_string(k);

        //Testando função raiz quadrada
        g->getIndiceRepresentacaoMatricialSQ(k,coordenadas);

        if(g->adjacencia[coordenadas[0]][coordenadas[1]] != v[k]) {
            cout<<"*";
            valido = false;
        }
        cout<<"        "+to_string(v[k]);
        cout<<"     "+to_string(g->adjacencia[coordenadas[0]][coordenadas[1]])+" ";
        cout<<"    ("+to_string(coordenadas[0])+","+to_string(coordenadas[1])+")";

        //Testando função iterativa
        g->getIndiceRepresentacaoMatricialIt(k,coordenadas);

        if(g->adjacencia[coordenadas[0]][coordenadas[1]] != v[k]) {
            cout<<"*";
            valido = false;
        }
        cout<<"     "+to_string(g->adjacencia[coordenadas[0]][coordenadas[1]])+" ";
        cout<<"   ("+to_string(coordenadas[0])+","+to_string(coordenadas[1])+")";

        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
    return valido;
}

//Imprime na tela um dado Grafo
void Utils::imprimirGrafo(Grafo *g) {
    cout<<"--------GRAFO--------"<<endl;
    
    cout<<"Ordem: "<<g->ordem<<endl;
    cout<<"Grau: "<<g->grau<<endl;
    cout<<"Matriz de Adjacencia: "<<endl;

    for(int i=0;i<g->ordem;i++) {
        for (int j=0;j<g->ordem;j++) {
            cout<<g->adjacencia[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"--------------------"<<endl<<endl;
}

//Imprime na tela a versão vetorial da matriz de adjacencia;
void Utils::imprimirGrafoVetor(Grafo *g, bool *v) {
    cout<<"--------REPRESENTACAO VETORIAL DO GRAFO--------"<<endl;
    
    int nVetor = (g->ordem*(g->ordem+1))/2;
    
    for(int i=0;i<nVetor;i++) {
        cout<<v[i]<<" ";
    }cout<<endl;

    
    cout<<"--------------------"<<endl<<endl;
}

int ** Utils::geraMatrizSimetricaOrdemK(int k, int min, int max) {
    int** m = new int*[k];

    for(int i=0;i<k;i++) {
        m[i]=new int[k];
    }

    for(int i=0;i<k;i++) {
        for(int j=i;j<k;j++) {
            m[i][j]= min+rand()%(max-min);
            m[j][i]= m[i][j];
        }
    }

    return m;

}

void Utils::imprimirMatriz(int k, int **m, string nome) {
    cout<<"---------- Matriz "+nome+" ----------"<<endl;
    if(ehSimetrica(k,m)) {
        cout<<"EH SIMETRICA"<<endl;
    }else {
        cout<<"NAO EH SIMETRICA"<<endl<<endl;
    }
    for(int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

bool Utils::ehSimetrica(int k, int **m) {
    for(int i=0;i<k;i++) {
        for(int j=i+1;j<k;j++) {
            if(m[i][j]!=m[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int** Utils:: somarMatrizes(int k, int** mA, int** mB) {

    int** mC = new int*[k];

    for(int i=0;i<k;i++) {
        mC[i] = new int[k];
        for(int j=0;j<k;j++) {
            mC[i][j] = mA[i][j] + mB[i][j];
        }
    }

    return mC;
}

int ** Utils::multiplicarMatrizes(int k, int **mA, int **mB) {
    int** mC = new int*[k];

    for(int i=0;i<k;i++) {
        mC[i] = new int[k];
        for(int j=0;j<k;j++) {
            int s=0;
            for(int p=0;p<k;p++) {
                s+=mA[i][p]*mB[p][j];
            }
            mC[i][j] = s;
        }
    }

    return mC;
}

void Utils::imprimirOperacaoDeMatrizes(int** mA, int** mB, int** mC, int n, char operacao) {
    string saida="";
    string sma,smb,smc;

    for(int i=0;i<n;i++) {
        sma=smb=smc="";

        for(int j=0;j<n;j++) {
            sma+="  "+to_string(mA[i][j]);
            smb+="  "+to_string(mB[i][j]);
            smc+="  "+to_string(mC[i][j]);

            if(mC[i][j]<10) {smc+=" ";}

            if(operacao=='+' && mC[i][j]!=(mA[i][j]+mB[i][j])) {
                cout<<"Soma deu errado"<<endl;
                exit(100);
            }
        }

        if(i!=0) {
            cout<<sma+"   "+smb+"   "+smc<<endl;
        }else {
            cout<<sma+"  "+operacao+smb+"  ="+smc<<endl;
        }

    }
}


