```
Jogo da Velha

*Descrições do Projeto*
Este é um jogo da velha implementado em linguagem C. O jogo é jogado em um tabuleiro 3x3 e suporta dois jogadores. Cada jogador alterna suas jogadas, escolhendo uma posição no tabuleiro até que haja um vencedor ou um empate.

*Regras do Jogo*
1- O jogo é jogado em um tabuleiro de 3x3.
2- Existem dois jogadores:
    Jogador 1: 'x'
    Jogador 2: '0' 
3- Os jogadores alternam suas jogadas, escolhendo uma posição vazia no tabuleiro.
4- O objetivo é alinhar três símbolos iguais ('x' ou '0') em:
    Uma linha horizontal,
    Uma coluna vertical, ou
    Uma diagonal (principal ou secundária). 
5- O jogo termina quando:
    Um jogador alinha três símbolos iguais (vitória), ou
    Todas as posições do tabuleiro forem preenchidas sem vencedor (empate).
   
*Como Jogar*
Quando o jogo é iniciado, o tabuleiro sera exibido da segunte forma:
  0   1   2
0 _ | _ | _
1 _ | _ | _
2 _ | _ | _

Os numeros do tabuleiros representam coordenadas (linha e coluna).
O jogador da vez deve digitar a posição a qual deseja jogar
Digitando a coordenada separando o numero da linha e o numero da coluna (por exemplo, 0 1, para jogar na primeira linha, segunda coluna
  0   1   2
0 _ | X | _
1 _ | _ | _
2 _ | _ | _
Após cada jogada, o tabuleiro sera exibido novamente, solicitando a coordenada desejada do seguinte jogador.
O jogo seguira alternando até que um jogador vença ou o jogo empate

*Condições de Vitória*
1 - Linha horizontal
  0   1   2
0 X | X | X
1 _ | _ | _
2 _ | _ | _

2 - Linha vertical
  0   1   2
0 X | _ | _
1 X | _ | _
2 X | _ | _

3 - Diagonal Principal
  0   1   2
0 X | _ | _
1 _ | X | _
2 _ | _ | X

4 - Diagonal Secundaria
  0   1   2
0 _ | _ | X
1 _ | X | _
2 X | _ | _
```
