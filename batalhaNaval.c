#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = { 0 };
    int linhaH, colunaH; // Posição inicial do navio horizontal
    int linhaV, colunaV; // Posição inicial do navio vertical
    int i;
    int valido = 1;

    printf("=== BATALHA NAVAL ===\n");

    // Entrada do usuário para o navio horizontal
    printf("Digite a linha (0 a 9) do navio horizontal: ");
    scanf_s("%d", &linhaH);

    printf("Digite a coluna inicial (0 a 7) do navio horizontal: ");
    scanf_s("%d", &colunaH);

    // Entrada do usuário para o navio vertical
    printf("Digite a linha inicial (0 a 7) do navio vertical: ");
    scanf_s("%d", &linhaV);

    printf("Digite a coluna (0 a 9) do navio vertical: ");
    scanf_s("%d", &colunaV);

    // Verificar se as coordenadas estão dentro dos limites
    if (linhaH < 0 || linhaH >= TAMANHO_TABULEIRO || colunaH < 0 || colunaH + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal está fora do tabuleiro.\n");
        valido = 0;
    }

    if (colunaV < 0 || colunaV >= TAMANHO_TABULEIRO || linhaV < 0 || linhaV + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical está fora do tabuleiro.\n");
        valido = 0;
    }

    // Verificar sobreposição
    if (valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 3 || tabuleiro[linhaV + i][colunaV] == 3) {
                printf("Erro: Os navios estão sobrepostos.\n");
                valido = 0;
                break;
            }
        }
    }

    // Posicionar os navios
    if (valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;  // Horizontal
            tabuleiro[linhaV + i][colunaV] = 3;  // Vertical
        }

        // Mostrar o tabuleiro
        printf("\n=== TABULEIRO FINAL ===\n");
        for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
            for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
                printf("%d ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }
    }
    else {
        printf("Navios não foram posicionados devido a erro de entrada.\n");
    }

    return 0;
}
