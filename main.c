#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
#include "tempo.h"
#include "inimigo.h"

int main(void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    do
    {
        fflush(stdin);
        menu();
    } while (sairMenu);

    return 0;
}

void menu(void)
{
    system("cls");
    printf("1 - Jogo\n2 - Selecionar Personagem\n3 - Placar\n4 - Sair\n");
    switch (getch())
    {
    case '1':
        jogo();
        break;
    case '2':
        selecionarPersonagem();
        break;
    case '3':
        placar();
        break;
    case '4':
        sair();
        break;
    case 27:
        sair();
        break;
    }
}

void jogo(void)
{
    vivo = 1;
    fflush(stdin);
    do
    {
        if (kbhit()) // Verifica se alguma tecla foi pressionada no teclado.
        {
            comandos();
        }
        if (tempoDecorrido() > 1)
        {
            novoTempo();

            inimigosSpawn();
        }
    } while (vivo);
}

void inimigosSpawn(void)
{
    srand(time(NULL));
    int lugarAleatorio = geraNumeroAleatorio(1, 8);
    int letraAleatoria = geraNumeroAleatorio(0, 26);

    inimigos[letraAleatoria].posicaoY = 0;
    inimigos[letraAleatoria].posicaoX = lugarAleatorio;

    for (int i = 0; i < 26; i++)
    {
        if (inimigos[i].posicaoY > -1)
        {
            inimigos[i].posicaoY++;
            exibirMapa(mapa);
        }
        if (inimigos[i].posicaoY > 8)
        {
            inimigos[i].posicaoY = -1;
        }
    }
}

void comandos(void)
{
    char tecla = getch();
    fflush(stdin);
    switch (tecla)
    {
    case 'a':
        teclaA();
        break;
    case 'd':
        teclaD();
        break;
    case 'w':
        teclaW();
        break;
    case 's':
        teclaS();
        break;
    case 27:
        teclaESC();
        break;
    }
    exibirMapa(mapa);
}

void exibirMapa(char mapa[y][x]) // Renderiza o mapa
{
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            int naoRenderizouPlayer = 1;
            int naoRenderizouInimigo = 1;

            for (int k = 0; k < 26; k++)
            {
                if (i == inimigos[k].posicaoY && j == inimigos[k].posicaoX)
                {
                    if (inimigos[k].posicaoY != 0 && inimigos[k].posicaoX != 0)
                    {
                        printf("%c ", inimigos[k].letra);
                        naoRenderizouInimigo = 0;
                    }
                }
                if (inimigos[k].posicaoY == JogadorPosicaoY && inimigos[k].posicaoX == JogadorPosicaoX)
                {
                    menuDeMorte();
                }
            }
            if (i == JogadorPosicaoY && j == JogadorPosicaoX && naoRenderizouInimigo)
            {
                printf("%c ", personagem);
                naoRenderizouPlayer = 0; // Não
            }
            if (naoRenderizouPlayer && naoRenderizouInimigo)
            {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

void menuDeMorte(void)
{
    system("cls");
    for (int i = 0; i < 26; i++)
    {
        inimigos[i].posicaoX = -1;
        inimigos[i].posicaoY = -1;
    }
    JogadorPosicaoY = 8;
    JogadorPosicaoX = 5;

    printf("Infelizmente você morreu! :(\n");
    system("pause");
    menu();
}

void selecionarPersonagem()
{
    system("cls");
    printf("Escolha seu número favorito de 0 a 9: ");
    personagem = getch();
    switch (personagem)
    {
    case '0':
        personagem = '0';
        menu();
        break;
    case '1':
        personagem = '1';
        menu();
        break;
    case '2':
        personagem = '2';
        menu();
        break;
    case '3':
        personagem = '3';
        menu();
        break;
    case '4':
        personagem = '4';
        menu();
        break;
    case '5':
        personagem = '5';
        menu();
        break;
    case '6':
        personagem = '6';
        menu();
        break;
    case '7':
        personagem = '7';
        menu();
        break;
    case '8':
        personagem = '8';
        menu();
        break;
    case '9':
        personagem = '9';
        menu();
        break;
    default:
        system("cls");
        printf("Personagem invalido!\n");
        system("pause");
        selecionarPersonagem();
        break;
    }
    fflush(stdin);
}

void placar(void)
{
    system("cls");
    printf("Em desenvolvimento :(\n");
    system("pause");
}

void sair(void)
{
    sairMenu = 0;
}