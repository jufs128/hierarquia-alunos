#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id; //Identificador do aluno
    int idade; //Idade do aluno
} Aluno;

typedef struct {
    Aluno Alunos[100]; //Lista de alunos; maximo de 100
    int Primeiro; //Primeiro indice
    int Ultimo; //Ultimo indice
} TipoLista;

void ListaVazia(TipoLista *Lista); //Cria lista vazia

void CadastraAluno(Aluno x, TipoLista *Lista); //Adiciona aluna a lista

#endif // LISTA_H
