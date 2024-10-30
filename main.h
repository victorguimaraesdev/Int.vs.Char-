#define y 10
#define x 10

char mapa[y][x] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Menu //
void menu(void);
int sairMenu = 1;

void jogo(void);
void selecionarPersonagem(); // Selecionar personagem.
char personagem = '1'; // Personagem inicial, caso não haja escolha de personagem.
void placar(void);
void sair(void);

// Jogo //
int JogadorPosicaoY = 8; // Posição inicial Y
int JogadorPosicaoX = 5; // Posição inicial X
void comandos();
int vivo = 1; // Estado de vida do jogador.
void exibirMapa(char mapa[y][x]);

// Comandos //
void teclaA()
{
    if (JogadorPosicaoX > 1) // Impede o jogador entrar na coluna 0
    {
        JogadorPosicaoX--;
    }
}
void teclaD()
{
    if (JogadorPosicaoX < x - 2) // Impede o jogador de entrar na coluna 9
    {
        JogadorPosicaoX++;
    }
}
void teclaESC()
{
    vivo = 0;
}
// Adicionei teclas W e S apenas para teste.
void teclaW()
{
    if (JogadorPosicaoY > 1)
    {
        JogadorPosicaoY--;
    }
}
void teclaS()
{
    if (JogadorPosicaoY < y - 2)
    {
        JogadorPosicaoY++;
    }
}
