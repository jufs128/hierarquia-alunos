# hierarquia-alunos
  O programa recebe o número de alunos de uma equipe ou clube (N), o número de relações diretas de comando entre eles (M) e o número de ações que seram realizadas na entrada(I). Depois, estão as idades de cada um dos N integrantes, seguida das M relações e das I linhas de instruções. As três instruções possíveis são SWAP (S), que inverte a relação entre o membro X e Y, COMMANDER (C), a qual retorna a pessoa mais nova a comandar X, direta ou indiretamente, e MEETING (M), que imprime a ordem de fala nas reuniões, sendo que o comandante deve falar antes de seu subordinado.
  
  SWAP imprime "S T" se tiver sucesso, e "S N" no caso de formar um ciclo (em que a troca não pode ser feita). COMMANDER imprime "C K", onde K é a idade do membro inserido na entrada se possuir comandante, e "C * " se o membro não tiver comandante. MEETING imprime "M" + a ordem de fala, de quem fala primeiro a quem fala por último.
  
## Implementação
  Para implementar, as relações foram marcadas em um grafo, representado por uma matriz de adjacência, e as informações de cada aluno estão gravadas em um lista sequencial.
  
## Entrada
  A ordem de entrada é número de alunos (N), número de relações (M), número de instruções (I), N idades de cada integrante, M relações, I instruções. A saída imprime o resultado de cada instrução. Exemplo:
  
 #### Entrada:        
  
  3 3 6         
  30 35 38            
  1 2                     
  1 3                  
  2 3                     
  C 1                              
  C 3
  S 2 3
  S 1 2
  C 1
  M
  
 #### Saída:
 
  C *           
  C 30          
  S T           
  S N           
  C *           
  M 1 3 2         
  
## Compilação
  Na parta archives está includo um Makefile, basta digitar make na linha de comando.
  
## Execução
  A função funciona passando o nome do arquivo .txt como parâmetro, mas, caso isso não seja feito, pede para o usuário digitar o nome do arquivo no início da execução.
