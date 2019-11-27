#ifndef FUNC_H
#define FUNC_H

#include "grafo.h"

void DFS(Grafo G, int *ciclo, int Antecessor[], int o); //Faz o DFS a partir do vértice 1

void VisitaDFS(int u, Grafo G, int Cor[], int Antecessor[], int *ciclo, int o); //Visita todos os vértices possíveis a partir de certo vértice

void Swap(Grafo G, Aluno x, Aluno y); //Verifica se é possível e realiza o comando SWAP

void Commander(Grafo G, TipoLista *Alunos, int a, int *novo); //Realiza o comando COMMANDER

void ProcuraProximo(Grafo G, int i, int Antecessor[], int Impresso[]); //Acha o proximo vertica a ser impresso

void Meeting (Grafo G, TipoLista *Alunos); //Imprime a ordem da reunião

#endif // FUNC_H
