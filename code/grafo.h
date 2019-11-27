#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"

struct grafo {
    int v; //Numero de vertices
    int a; //Numero de arestas
    int **matriz; //Matriz que representa o grafico
};

typedef struct grafo *Grafo; //Apontador do tipo grafo

int** InicializaMatriz(int n); //Inicializa amatriz do grafo (tudo 0)

Grafo InicializaGrafo(int n); //Inicializa o grafo

void CriaAresta(Grafo G, Aluno x, Aluno y); //Coloca a aresta desejada na matriz do grafo

void RemoveAresta(Grafo G, Aluno x, Aluno y); //Remove a aresta da matriz do grafo

void Imprime(int **m, int n); //Imprime a matriz (utilizada para teste)

#endif // GRAFO_H
