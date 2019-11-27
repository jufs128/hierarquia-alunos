#include "lista.h"
#include "grafo.h"
#include "func.h"
#include <time.h>

int main(int argc, char *argv[]) {
    //Medir tempo
    //clock_t tempoInicial;
    //clock_t tempoFinal;
    //tempoInicial = clock();

    char NomeArq[100];
    if(argc > 1){ //Verifica se o nome do arquivo foi colocado como parâmetro
        strcpy(NomeArq,argv[1]); //Copia o nome para string NomeArq
    } else { //Se não foi colocado, pede para inserir
        printf("Digite o nome do arquivo de entrada: ");
        scanf("%s",NomeArq); //Lê da stdin
    }
    FILE *arq;
    arq = fopen(NomeArq,"r"); //Abre o arquivo para leitura
    if(arq==NULL){ //Se arquivo inserido não está na pasta
        printf("Erro ao abrir arquivo de entrada.\n"); //Dá erro
        return 1;
    }

    int N, M, I;
    fscanf(arq,"%d %d %d",&N,&M,&I); //Lê o número de alunos, de relações e de instruções

    int i, aux;
    Aluno A;
    TipoLista *ListaAlunos = malloc(sizeof(TipoLista)); //Lista de alunos
    ListaVazia(ListaAlunos); //Inicialmente lista está vazia
    for(i = 0; i < N; i++){
        fscanf(arq,"%d",&aux); //Lê idade do aluno
        A.id = i + 1; //id
        A.idade = aux; //idade
        CadastraAluno(A,ListaAlunos); //Cadastra o aluno na ordem que foi inserido
    }

    int x, y;
    Grafo G = InicializaGrafo(N); //Inicializa grafo
    for(i = 0; i < M; i++){
        fscanf(arq,"%d %d",&x,&y); //Lê a relação
        if (x != y){ //Verifica se x é diferente de y
            CriaAresta(G,ListaAlunos->Alunos[x-1],ListaAlunos->Alunos[y-1]); //Cria a aresta
        }
    }

    char inst[1]; //String de 1 caracter
    int *MaisNovo;
    for(i = 0; i < I; i++){
        fscanf(arq,"%s",inst); //Lê qual é a intrução
        if(strcmp(inst,"S") == 0){ //Se é swap
            fscanf(arq,"%d %d",&x,&y); //Lê quem comanda quem
            Swap(G,ListaAlunos->Alunos[x-1],ListaAlunos->Alunos[y-1]); //Verifica e realiza o swap
        } else if(strcmp(inst,"C") == 0){ //Se é commander
            fscanf(arq,"%d",&x); //Lê de qual aluno
            *MaisNovo = -1; //Inicialmente como -1
            Commander(G,ListaAlunos,x-1,MaisNovo); //Procura o comandante mais novo
            printf("C ");
            if(*MaisNovo == -1){ //Se ainda é -1 não possui comandante
                printf("*\n"); //Imprime *
            } else{ //Se é diferente de -1
                printf("%d\n",*MaisNovo); //Imprime a idade encontrada
            }
        } else if(strcmp(inst,"M") == 0){ //Se é meeting
            Meeting(G,ListaAlunos); //Acha a ordem de fala
        } else { //Se não é nenhum
            printf("Comando nao reconhecido\n"); //Mensagem de erro
        }
    }

    //tempoFinal = clock();
    //printf("%f,",(tempoFinal- tempoInicial) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
