//
// Created by Rafael on 07/05/2024.
//

#include "Utils.h"

#include <cmath>

Utils::Utils(long seed) {
    int k=0;
    this->file.open("OUTPUT_"+to_string(k)+".TXT", ios_base::in);
    while(this->file.is_open()) {
        this->file.close();
        k++;
        this->file.open("OUTPUT_"+to_string(k)+".TXT", ios_base::in);
    }
    this->fileName="OUTPUT_"+to_string(k)+".TXT";
    this->file.open("OUTPUT_"+to_string(k)+".TXT", ios_base::out);
    this->file<<"----------RELATORIO DE RESULTADOS (SEED "+to_string(seed)+")----------"<<endl<<endl;
}

Utils::~Utils() {
    this->file.close();
    cout<<endl<<"----------RELATORIO EMITIDO NO ARQUIVO "+this->fileName+"----------"<<endl;
}

//Testa se a versão vetoria do grafo atende as expectativas
bool Utils::grafoVetorEhValido(Grafo *g, bool *v) {

    this->file<<"--------TESTANDO REPRESENTAÇÃO VETORIAL DO GRAFO :--------"<<endl;
    this->file<<"--------(i,j) | k | v[k]  :--------"<<endl;
    bool valido = true;

    for(int i=0;i<g->ordem;i++) {
        for(int j = 0 ; j<g->ordem; j++) {
            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                this->file<<"***** M["<<i<<","<<j<<"] != V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
                valido = false;
            }else {
                this->file<<"M["<<i<<","<<j<<"] = V["<<g->getIndiceRepresentacaoVetorialPA(i,j)<<"] = "<<g->adjacencia[i][j]<<endl;
            }
        }
    }
    if(valido) {
        this->file<<"--------------------VALIDO"<<endl<<endl;
    }else {
        this->file<<"--------------------NAO VALIDO"<<endl<<endl;
    }


     return valido;
}

bool Utils::graficoMatricialEhValido(Grafo *g, bool **m) {
    this->file<<"--------REPRESENTACAO MATRICIAL GERADA A PARTIR DA REPRESENTACAO VETORIAL:--------"<<endl;
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
        this->file<<sm1<<"     "<<sm2<<endl;
    }
    if(valido) {
        this->file<<"--------------------VALIDO"<<endl<<endl;
    }else {
        this->file<<"--------------------NAO VALIDO"<<endl<<endl;
    }

    return valido;
}

bool Utils::conversoesDeIndiceMatrizVetorSaoValidas(Grafo *g, bool *v) {

    this->file<<"--------TESTANDO CONVERSÃO M(i,j) -> V[k] ---------"<<endl;


    this->file<<"Coordenadas;Valor na Matriz;Valor do PA; Valor IT; Valor REC;Indice do do PA; Indice do IT; Indice do REC"<<endl;
    bool valido = true;


    for(int i=0;i<g->ordem;i++) {

        for(int j=0; j<g->ordem; j++) {
            this->file<<"("+to_string(i)+","+to_string(j)+");"+to_string(g->adjacencia[i][j])+";";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialPA(i,j)]) {
                this->file<<"*";
                valido = false;
            }
            this->file<<to_string(v[g->getIndiceRepresentacaoVetorialPA(i,j)])+";";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialIt(i,j)]) {
                this->file<<"*";
                valido = false;
            }
            this->file<<to_string(v[g->getIndiceRepresentacaoVetorialIt(i,j)])+ ";";

            if(g->adjacencia[i][j] != v[g->getIndiceRepresentacaoVetorialRec(i,j,0)]) {
                this->file<<"*";
                valido = false;
            }
            this->file<<to_string(v[g->getIndiceRepresentacaoVetorialRec(i,j,0)])+";";

            this->file<<to_string(g->getIndiceRepresentacaoVetorialPA(i,j))+";";
            this->file<<to_string(g->getIndiceRepresentacaoVetorialIt(i,j))+";";
            this->file<<to_string(g->getIndiceRepresentacaoVetorialRec(i,j,0));

            this->file<<endl;

        }

    }
    if(valido) {
        this->file<<"--------------------VALIDO"<<endl<<endl;
    }else {
        this->file<<"--------------------NAO VALIDO"<<endl<<endl;
    }
    return valido;
}

bool Utils::conversoesDeIndiceVetorMatrizSaoValidas(Grafo *g, bool *v) {

    this->file<<"--------TESTANDO CONVERSAO  V[k] ->M(i,j) ---------"<<endl;

    this->file<<"Indice;Valor no vetor;Valor por SQ;Indice por SQ;Valor por IT;Indice por iIT"<<endl;
    bool valido = true;
    int nVetor = (g->ordem*(g->ordem+1))/2;

    int coordenadas[2];
    for(int k=0;k<nVetor;k++) {
        this->file<<to_string(k)+";";

        //Testando função raiz quadrada
        g->getIndiceRepresentacaoMatricialSQ(k,coordenadas);

        if(g->adjacencia[coordenadas[0]][coordenadas[1]] != v[k]) {
            this->file<<"*";
            valido = false;
        }
        this->file<<to_string(v[k])+";";
        this->file<<to_string(g->adjacencia[coordenadas[0]][coordenadas[1]])+";";
        this->file<<"("+to_string(coordenadas[0])+","+to_string(coordenadas[1])+");";

        //Testando função iterativa
        g->getIndiceRepresentacaoMatricialIt(k,coordenadas);

        if(g->adjacencia[coordenadas[0]][coordenadas[1]] != v[k]) {
            this->file<<"*";
            valido = false;
        }
        this->file<<to_string(g->adjacencia[coordenadas[0]][coordenadas[1]])+";";
        this->file<<"("+to_string(coordenadas[0])+","+to_string(coordenadas[1])+");";

        this->file<<endl;
    }
    if(valido) {
        this->file<<"--------------------VALIDO"<<endl<<endl;
    }else {
        this->file<<"--------------------NAO VALIDO"<<endl<<endl;
    }
    return valido;
}

//Imprime na tela um dado Grafo
void Utils::imprimirGrafo(Grafo *g) {
    this->file<<"--------GRAFO GERADO--------"<<endl;
    
    this->file<<"ORDEM: "<<g->ordem<<endl;
    this->file<<"GRAU: "<<g->grau<<endl;
    this->file<<"MATRIZ DE ADJACENCIA: "<<endl;

    for(int i=0;i<g->ordem;i++) {
        for (int j=0;j<g->ordem;j++) {
            this->file<<g->adjacencia[i][j]<<" ";
        }
        this->file<<endl;
    }
    
    this->file<<"--------------------"<<endl<<endl;
}

//Imprime na tela a versão vetorial da matriz de adjacencia;
void Utils::imprimirGrafoVetor(Grafo *g, bool *v) {
    this->file<<"--------REPRESENTACAO VETORIAL DO GRAFO--------"<<endl;
    
    int nVetor = (g->ordem*(g->ordem+1))/2;
    
    for(int i=0;i<nVetor;i++) {
        this->file<<v[i]<<" ";
    }this->file<<endl;

    
    this->file<<"--------------------"<<endl<<endl;
}


void Utils::imprimirMatriz(Matriz* m, string nome) {
    this->file<<"---------- MATRIZ SIMÉTRICA "+nome+" GERADA----------"<<endl;

    for(int i=0;i<m->n;i++) {
        for (int j=0;j<m->n;j++) {
            this->file<<m->m[i][j]<<" ";
        }
        this->file<<endl;
    }

    this->file<<"--------------------";
    if(m->ehSimetrica()) {
        this->file<<"EH SIMETRICA"<<endl<<endl;
    }else {
        this->file<<"NAO EH SIMETRICA"<<endl<<endl;
    }
}



void Utils::imprimirOperacaoDeMatrizes(Matriz *mA, Matriz *mB, Matriz *mC, char operacao) {

    if(operacao=='+') {
        this->file<<"----------RESULTADO DA SOMA DAS MATRIZES----------"<<endl;
    }else {
        this->file<<"----------RESULTADO DA MULTIPLICACAO DAS MATRIZES----------"<<endl;
    }
    string saida="";
    string sma,smb,smc;

    for(int i=0;i<mA->n;i++) {
        sma=smb=smc="";

        for(int j=0;j<mA->n;j++) {
            sma+=" "+to_string(mA->m[i][j]);
            smb+=" "+to_string(mB->m[i][j]);
            smc+=" "+to_string(mC->m[i][j]);

            if(mC->m[i][j]<10) {smc+=" ";}

            if(operacao=='+' && mC->m[i][j]!=(mA->m[i][j]+mB->m[i][j])) {
                this->file<<"Soma deu errado"<<endl;
                exit(100);
            }
        }

        if(i!=0) {
            this->file<<sma+"   "+smb+"   "+smc<<endl;
        }else {
            this->file<<sma+"  "+operacao+smb+"  ="+smc<<endl;
        }

    }

    this->file<<"--------------------MATRIZ RESULTANTE ";
    if(mC->ehSimetrica()) {
        this->file<<"EH SIMETRICA"<<endl<<endl;
    }else {
        this->file<<"NAO EH SIMETRICA"<<endl<<endl;
    }
}

void Utils::imprimirSomaDeMatrizesVetorizadas(int ordem, int *mVA, int *mVB, int *mVC) {

    this->file<<"----------RESULTADO DA SOMA DAS MATRIZES VETORIZADAS----------"<<endl;
    int nVetor = (ordem*(ordem+1))/2;

    for(int j=0;j<nVetor;j++) {
        this->file<<to_string(mVA[j])<<" ";
    }

    this->file<<endl<<"+"<<endl;

    for(int j=0;j<nVetor;j++) {
        this->file<<to_string(mVB[j])<<" ";
    }

    this->file<<endl<<"="<<endl;

    for(int j=0;j<nVetor;j++) {
        this->file<<to_string(mVC[j])<<" ";
    }
    this->file<<endl<<"----------"<<endl<<endl;
}

void Utils::imprimirMultiplicacaoDeMatrizesVetorizadas(int ordem, int *mVA, int *mVB, int *mVC) {

    this->file<<"----------RESULTADO DA MULTIPLICACAO DAS MATRIZES VETORIZADAS----------"<<endl;
    int nVetorSim = (ordem*(ordem+1))/2;
    int nVetor = ordem*ordem;

    for(int j=0;j<nVetorSim;j++) {
        this->file<<to_string(mVA[j])<<" ";
    }

    this->file<<endl<<"*"<<endl;

    for(int j=0;j<nVetorSim;j++) {
        this->file<<to_string(mVB[j])<<" ";
    }

    this->file<<endl<<"="<<endl;

    for(int j=0;j<nVetor;j++) {
        this->file<<to_string(mVC[j])<<" ";
    }
    this->file<<endl<<"----------"<<endl<<endl;
}


void Utils::imprimirMatrizVetorizada(int *v, int n, string nome) {

    this->file<<"----------VERSAO VETORIZADA DA MATRIZ "+nome+"----------"<<endl;
    int nVetor = (n*(n+1))/2;

    for(int i=0;i<nVetor;i++) {
        this->file<<v[i]<<" ";
    }this->file<<endl;

    this->file<<"----------"<<endl<<endl;

}

bool Utils::EhValidaSomaMatrizVetorial(Matriz *mA, Matriz *mB, Matriz *mC, int *mVA, int *mVB, int *mVC) {
    bool ehValido=true;
    this->file<<"------------TESTANDO RESULTADO DA SOMA DAS MATRIZES VETORIAIS --------------"<<endl;
    this->file<<"Indice M[i,j];Indices V;Valor mA;Valor mVA;Valor mB;Valor mVB;Valor mC;Valor mVC "<<endl;

    for(int i=0;i<mA->n;i++) {
        for(int j=0;j<mA->n;j++) {
            string s="("+to_string(i)+","+to_string(j)+");";
            s+=to_string(Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n))+";";
            s+=to_string(mA->m[i][j])+";";
            s+=to_string(mVA[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)])+";";
            s+=to_string(mB->m[i][j])+";";
            s+=to_string(mVB[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)])+";";
            s+=to_string(mC->m[i][j])+";";
            s+=to_string(mVC[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)])+";";

            this->file<<s<<endl;

            if(mA->m[i][j]!=mVA[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)] ||
                mB->m[i][j]!=mVB[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)] ||
                mC->m[i][j]!=mVC[Matriz::getIndiceRepresentacaoVetorialPA(i,j,mA->n)]) {
                ehValido = false;
                this->file<<"***"<<endl;
            }

        }
    }

    this->file<<"--------------------";
    if(ehValido) {
        this->file<<"VALIDO"<<endl<<endl;
    }else {
        this->file<<"NAO VALIDO"<<endl<<endl;
    }


    return ehValido;
}

bool Utils::EhValidaMultiplicacaoMatrizVetorial(Matriz *mC, int *mVC){
    bool ehValido=true;
    this->file<<"------------TESTANDO RESULTADO DO PRODUTO DAS MATRIZES VETORIAIS --------------"<<endl;
    this->file<<"Indice M[i,j];Indices V;Valor mC;Valor mVC"<<endl;

    for(int i=0;i<mC->n;i++) {
        for(int j=0;j<mC->n;j++) {
            string s="("+to_string(i)+","+to_string(j)+");";
            s+=to_string(Matriz::getIndiceRepresentacaoVetorialNaoSimetrica(i,j,mC->n))+";";
            s+=to_string(mC->m[i][j])+";";
            s+=to_string(mVC[Matriz::getIndiceRepresentacaoVetorialNaoSimetrica(i,j,mC->n)])+";";

            this->file<<s<<endl;

            if(mC->m[i][j]!=mVC[Matriz::getIndiceRepresentacaoVetorialNaoSimetrica(i,j,mC->n)]) {
                ehValido = false;
                this->file<<"***"<<endl;
                }

        }
    }
    this->file<<"--------------------";
    if(ehValido) {
        this->file<<"VALIDO"<<endl<<endl;
    }else {
        this->file<<"NAO VALIDO"<<endl<<endl;
    }

    return ehValido;
}


