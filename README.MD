
<center><b> Trabalho de Disciplina

Análise de Projeto de Algorítmos - 2035002 - 2024.1-A


Programa de Pós Graduação em Ciência da Computação
Mestrado em Ciência da Computação
Universidade Federal de Juiz de Fora
Departamento de Ciência da Computação
</center>

<b>Discentes</b>
- Rafael Freesz Resende Corrêa
- Pedro José de Sousa Filho;

Docentes:</b> Raul Fonseca Neto
<center><b>Considerações Gerais</b></center>

1. Para o referido trabalho, foram utilizadas as estruturas de dados a seguir:

~~~c++
//Representação do Grafo
class Grafo {
public:
    int grau; //quantidade de arestas próprias
    int ordem; //quantidade de vertices;
    bool** adjacencia; //Matriz de adjacencia binária
};

//Representação de matrizes
class Matriz {
public:
    int n; //Ordem da matriz
    int** m; //Matriz
};
~~~
3. Todos os códigos e estruturas utilizados para a os algoritmos mencionados estão presentes neste repositório.

3. O comando para compilação e execução do código é dado por 

~~~
Windows: g++ -O3 *.cpp; ./a.exe 
Linux: g++ -O3 *.cpp; ./a.out 
~~~

4. Os testes dos algoritmos constam respectivamente no arquivo <i>OUTPUT_0.TXT</i>

5. Para tais execuções, foi utilizada a <i>seed</i> 0.

<center><b>Enunciado</b></center>
<b>1 -</b> Gerar randomicamente um grafo não orientado com 100 vértices, com um número baixo de ligações (de uma a dez vezes o número de vértices).

<b>2 -</b> Implementar um algoritmo que gere a representação matricial (matriz adjacência binária)

<b>3 -</b> Implementar um algoritmo que, a partir da matriz, gere a representação vetorial (vetor binário) de sua parte triangular superior.

<b>4 -</b> Gerar o vetor compactado (vetor de índices inteiros) com endereçamento indireto.

<b>5 -</b> Implementar um algoritmo que a partir do vetor compactado gere a matriz de adjacência.

<b>6 -</b> Implementar a função de mapeamento que a partir da entrada $(i,j)$ da matriz de adjacência de ordem $n$ acesse a posição $k$ do vetor de índices. Implementar o cálculo analítico (progressão aritmética) e também os procedimentos iterativo e recursivo.

<b>7 -</b> Implementar a função de mapeamento inversa que a partir do índice $k$ do vetor acesse a posição $(i,j)$ da matriz de adjacência de ordem $n$. Implementar o cálculo analítico (algoritmo raiz quadrada) e também o procedimento iterativo.

<b>8 -</b> Implementar as operações:
- <b>a -</b> de soma (operação de união);
- <b>b -</b> produto direto (operação de interseção) entre duas matrizes utilizando suas respectivas representações vetoriais.

<b>Obs.:</b> Todos os algoritmos devem ser testados bem como determinado as suas funções de complexidade.

<center><b>Soluções</b></center>

1. 

~~~c++
//Gera um grafo aleatorio de ordem parametrizada
Grafo * Grafo::gerarGrafoOrdemK(int ordem) {

    Grafo* grafo = new Grafo(ordem);
    int grau =ordem*(1+rand()%10);

    for(int i=0;i<grau;i++) {
        int a = rand()%grafo->ordem;
        int b = rand()%grafo->ordem;

        while(a==b || grafo->adjacencia[a][b]) {
            a = rand()%grafo->ordem; b = rand()%grafo->ordem;
        }

        grafo->incluirAresta(a,b);
    }
    return grafo;
}
~~~

O algoritmo em questão varia de acordo com a quantidade de arestas $o$, onde $n\leq o\leq 100n$, onde $n$ é a ordem do grafo. Logo, o algoritmo é $O(100n) = O(n)$

O grafo resultante está presente no arquivo <i>OUTPUT_0.TXT</i> entre as linhas 3 e 107.

~~~
--------GRAFO GERADO--------
ORDEM: 100
GRAU: 900
MATRIZ DE ADJACENCIA: 
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1... 
0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0...
...
--------------------
~~~


2. A matriz de adjacencia em questão está nativamente presente na estrutura do grafo, podendo ser construida manualmente ou aleatoriamente pela função $gerarGrafoOrdemK(int\ ordem)$
~~~c++
//Representação do Grafo
class Grafo {
public:
    int grau; //quantidade de arestas próprias
    int ordem; //quantidade de vertices;
    bool** adjacencia; //Matriz de adjacencia binária
};
~~~

3. 
~~~c++
//Transforma a matriz de adjacencias binária simétrica em um vetor com a parte triangular superior
bool * Grafo::gerarRepresentacaoVetorial() {

    int nVetor = (this->ordem*(this->ordem+1))/2;
    bool* grafoVetorial = new bool[nVetor];
    int linha=0;
    int coluna=0;

    for(int i=0;i<nVetor;i++) {
        grafoVetorial[i]=this->adjacencia[linha][coluna];

        if(coluna == this->ordem-1) {
            linha ++;
            coluna = linha;
        }else {
            coluna++;
        }
    }
    return grafoVetorial;
}
~~~
A complexidade deste algoritmo está atrelada ao tamanho do vetor resultante.
A matriz de representação de um grafo é de ordem $n$, onde $n$ é a quantidade de nós.
Tal matriz possui $n^2$ elementos
Como a matriz é simétrica, um vetor contendo a sua parte triangular superior é suficiente para sua total representação.
Nessas condições, será gerado um vetor $V$ onde $|V|=n*(n+2)/2$.
Desta forma o algoritmo é $O(n^2)$.

4.
O grafo resultante é mostrado e testado no arquivo <i>OUTPUT_0.TXT</i> entre as linhas 109 e 10115.
O vetor é impresso na linha 110, a partir da linha 115, é realizado um teste de igualdade entre os valores do vetor e da matriz. É possivel observar que tais valores são validados
~~~
--------REPRESENTACAO VETORIAL DO GRAFO--------
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 1 1 1 0 1 0 0...
--------------------

--------TESTANDO REPRESENTAÇÃO VETORIAL DO GRAFO :--------
--------(i,j) | k | v[k]  :--------
M[0,0] = V[0] = 0
M[0,1] = V[1] = 0
M[0,2] = V[2] = 0
M[0,3] = V[3] = 1
M[0,4] = V[4] = 0
M[0,5] = V[5] = 0
M[0,6] = V[6] = 0
...
M[i,j] = V[k] = X
...
M[99,99] = V[5049] = 0
--------------------VALIDO
~~~

5.
 ~~~c++
 //Gerando a representação matricial a partir de sua representacao vetorial
bool ** Grafo::gerarRepresentacaoMatricial(bool *v) {

    bool** m = new bool*[this->ordem];
    for(int i=0;i<this->ordem;i++) {
       m[i] = new bool[this->ordem];
    }

    for(int i=0;i<this->ordem;i++) {
        for(int j = i; j <this->ordem;j++) {
            m[j][i] = m[i][j] = v[getIndiceRepresentacaoVetorialPA(i,j)];
        }
    }
    return m;
}
 ~~~

A conversão das estruturas depende do preenchimento da matriz de ordem $n$. Cada posição do vetor atribui valor a dois elementos da matriz ($m[i][j]$ e $m[j][i]$), custando $2*(n*(n-1))/2$. Logo, esta algoritmo possui $O(n^2)$.

A representação matricial gerada a partir do vetor é mostrada no relatório entre as linhas 10117 e 11218, sendo verificada tambem a validade da conversão.

~~~
--------REPRESENTACAO MATRICIAL GERADA A PARTIR DA REPRESENTACAO VETORIAL:--------
| 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 ...
| 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 ...
| 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 ...
| 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 ...
| 0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 1 ...
| 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 ...
| 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 1 ...
| 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 ...
| 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 ...
| 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 ...
...
| 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 ... 
| 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 ... 
| 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ... 
| 0 0 0 0 0 1 0 1 1 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 ... 
| 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 ... 
| 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ... 
| 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 ... 
| 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 ... 
| 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 1 0 0 1 0 1 ... 
--------------------VALIDO

~~~

6. 
Para tal foram criados três algoritmos:
- Algoritmo de Progressão Aritmética (PA):
~~~c++
//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do da PA)
int Grafo::getIndiceRepresentacaoVetorialPA(int i, int j) {
    int linha = min(i,j);
    int coluna = max(i,j);
    return ((2*this->ordem - linha + 1)*linha/2 + (coluna-linha));
}
~~~
- Algoritmo Iterativo (PA):
~~~c++
//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do Iterativo)
int Grafo::getIndiceRepresentacaoVetorialIt(int i, int j) {
    int linha = min(i,j);
    int coluna = max(i,j);

    int k = coluna;
    for(int l=0; l<linha; l++) {
        k+=this->ordem-l-1;
    }
    return k;
}
~~~
- Algoritmo Recursivo (PA):
~~~c++
//Converte uma posição i,j da matriz de adjacencia em sua respectiva posição no vetor (mét0do Recursivo)
int Grafo::getIndiceRepresentacaoVetorialRec(int i, int j, int l) {
    int linha = min(i,j);
    int coluna = max(i,j);

    if(linha==l) {
        return coluna;
    }else {
        return this->ordem-l-1+getIndiceRepresentacaoVetorialRec(linha,coluna,l+1);
    }
}
~~~

7. 