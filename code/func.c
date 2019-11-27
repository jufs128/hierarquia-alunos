#include "func.h"

void DFS(Grafo G, int *ciclo, int Antecessor[], int o){ //Busca em profundidade, verifica se há ciclo
    //int o vai ser utilizado para saber o a função da realização do DFS
    //0 se for para checar ciclo; 1 se for para pegar a ordem
    //Se for para checar ciclo, Cor é necessária, se for para pegar ordem, é para ignora-la
    int x;
    int Cor[100]; //Mostra status do vértice (se já foi visitado)

    for(x = 0; x < G->v; x++){
        Cor[x] = 0; //0 é branco (não visitou), 1 é preto (já visitou) e 2 é cinza (está em processo de ser visitado)
        Antecessor[x] = -1; //Primeiramente não é antecedido por nada
    }

    for(x = 0; x < G->v; x++){
        if(Cor[x] == 0){ //Se não foi visitado
            VisitaDFS(x,G,Cor,Antecessor, ciclo,o); //Visitar
        }
    }
}

void VisitaDFS(int u, Grafo G, int Cor[], int Antecessor[], int *ciclo, int o){ //DFS do vértice u
    if(o == 0){ //Se for para checar se há ciclo, muda a cor
        Cor[u] = 2; //Está sendo visitado
    }

    int v;
    for(v = 0; v < G->v; v++){
        if(G->matriz[u][v] == 1){ //Se existe a aresta (u,v)
            if(Cor[v] == 2){ //Se v ainda está sendo visitado e chegou nele novamente
                *ciclo = 1;  //Há ciclo no grafo
            } else if(Cor[v] == 0){ //Se ainda nao foi visitado
                Antecessor[v] = u; //O antecessor de v é u
                VisitaDFS(v,G,Cor,Antecessor,ciclo,o); //Visitar v
            }
        }
    }
    if(o==0){ //Se for para checar se há ciclo, muda a cor
        Cor[u] = 1; //Terminou de visitar
    }
}

void Swap (Grafo G, Aluno x, Aluno y){ //Inverte o comando
    if ((G->matriz[x.id-1][y.id-1] == 1) && (G->matriz[y.id-1][x.id-1] == 0)){ //Verifica se existe a aresta
        RemoveAresta(G,x,y);
        CriaAresta(G,y,x); //Inverte
        int ciclo;
        int A[100]; //Só para passar como parâmetro para DFS, não vai ser utilizado
        DFS(G, &ciclo, A, 0); //Verificar se criou ciclo
        if(ciclo == 1){ //Se criou
            RemoveAresta(G,y,x);
            CriaAresta(G,x,y); //Desfazer
            printf("S N\n"); //Imprime que não pode fazer
        } else { //Se não criou
            printf("S T\n"); //Inverteu
        }
    } else{ //Se não existe aresta
        printf("S N\n"); //Não inverte
    }
}

void Commander (Grafo G, TipoLista *Alunos, int a, int *novo) { //Acha quem o main novo que comanda certo aluno
    int c;
    for(c = 0; c < G->v; c++){
        if(G->matriz[c][a] == 1){ //Se exista algum que comanda Alunos[a]
            if((*novo == -1) || (Alunos->Alunos[c].idade < *novo)){ //Se eh o primeiro que comanda ou se a idade é menor
                *novo = Alunos->Alunos[c].idade; //Muda a idade
            }
            Commander(G,Alunos,c,novo); //Verificar se algum dos comandantes de c é mais novo (comanda indiretamente)
        }
    }
}

void ProcuraProximo(Grafo G, int i, int Antecessor[], int Impresso[]){ //Acha a ordem para ser impresso
    int j, x;
    for(j = 0; j < G->v; j++){
        if((Antecessor[j] == i) && (Impresso[j] == 0)){ //Se o antecessor é i e não foi impresso ainda
            x = j + 1;
            printf(" %d", x); //Imprime j + 1 (id do aluno)
            Impresso[j] = 1; //Muda para impresso
            ProcuraProximo(G,j,Antecessor,Impresso); //Procura o próximo a ser impresso
        }
    }
}

void Meeting (Grafo G, TipoLista *Alunos) { //Acha a ordem da reunião
    int ciclo = 0, Antecessor[100];
    int Impresso[100];
    DFS(G, &ciclo, Antecessor, 1); //Feito para achar a ordem de Antecessor
    int i;
    for(i = 0; i < G->v; i++){
        Impresso[i] = 0; //Nenhum foi impresso ainda
    }

    printf("M");
    for(i = 0; i < G->v; i++){
        if(Antecessor[i] == -1){ //Se é um dos vértices que não possui comandante
            printf(" %d", i + 1); //Imprime i + 1 (id do aluno)
            Impresso[i] = 1; //Marca i como impresso
            ProcuraProximo(G,i,Antecessor,Impresso); //Procura qual segue i
        }
    }
    printf("\n");
}
