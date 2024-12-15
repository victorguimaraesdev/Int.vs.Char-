# INT vs CHAR

**Criadores: victorguimaraesdev, Zelchi e CardosooDev**


Este é um jogo simples de console feito em C, onde o jogador interage com inimigos que aparecem aleatoriamente no mapa. O objetivo é evitar que o jogador seja atingido pelos inimigos enquanto controla um personagem usando o teclado.

## 🚀 Funcionalidades

- **Menu Principal:** O jogo começa com um menu onde o jogador pode escolher entre jogar, selecionar um personagem, ver o placar ou sair.
- **Seleção de Personagem:** O jogador escolhe um personagem representado por um número (de 0 a 9).
- **Jogo:** O jogo é uma batalha contra inimigos que surgem aleatoriamente no mapa. O jogador pode se mover pelas teclas `W`, `A`, `S`, `D`.
- **Inimigos:** Inimigos aparecem em posições aleatórias e descem pelo mapa. O objetivo é desviar deles.
- **Placar:** O placar está em desenvolvimento.
- **Tela de Morte:** Se o jogador colidir com um inimigo, o jogo mostra a tela de morte e reinicia o jogo.

## 🔧 Tecnologias Usadas

- **Linguagem:** C
- **Bibliotecas:** 
  - `stdio.h`: Para entrada e saída de dados.
  - `locale.h`: Para configurar o idioma do sistema.
  - `conio.h`: Para capturar entradas do teclado.
  - `time.h`: Para controlar o tempo no jogo.
  - `stdlib.h`: Para funções utilitárias como geração de números aleatórios.
- **Estrutura de Arquivos:** O código é modularizado em diferentes arquivos como `main.h`, `tempo.h`, `inimigo.h`, que contêm a lógica do jogo, tempo e inimigos, respectivamente.
