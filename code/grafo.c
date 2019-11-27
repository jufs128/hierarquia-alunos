#include "grafo.h"

int** InicializaMatriz (int n) { //Inicializa a matriz
    int j, i;

    int **m = (int**)malloc(n*sizeof(int*)); //Ponteiro de ponteiros
    for(i = 0; i < n; i++){
        m[i] = (int*)malloc(n*sizeof(int)); //Para cada ponteiro (linha) cria outro (coluna)
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m[i][j] = 0; //Inicializa toda como 0
        }
    }

    return m;
}

Grafo InicializaGrafo (int n) {
    Grafo G = malloc(sizeof *G); //Cria a variável do grafo
    G->v = n; //Numero de vértices é o numero de membros da equipe
    G->a = 0; //Numero de arestas é inicialmente 0
    G->matriz = InicializaMatriz(n); //Inicializa a matriz do grafo
    return G;
}

void CriaAresta (Grafo G, Aluno x, Aluno y) { //Coloca a aresta desejada na matriz do grafo
    if (G->matriz[x.id - 1][y.id - 1] == 0){ //Verifica se a aresta já existe
        G->matriz[x.id - 1][y.id - 1] = 1; //Coloca como 1 na matriz
        G->a++; //Adiciona 1 ao número de arestas
    }
}

void RemoveAresta (Grafo G, Aluno x, Aluno y) { //Remove a aresta desejada na matriz do grafo
    if (G->matriz[x.id - 1][y.id - 1] == 1){ //Verifica se a aresta existe
        G->matriz[x.id - 1][y.id - 1] = 0; //Coloca como 0 na matriz
        G->a--; //Diminui 1 do numero de arestas
    }
}

void Imprime (int **m, int n){ //Imprime a matriz (utilizada para teste)
    int i, j;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
