#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[100];
    int numeroLinha, contador = 0;
    char idade[4], estado[3];

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o número da linha: ");
    scanf("%d", &numeroLinha);

    if (numeroLinha <= 0) {
        printf("registro nao encontrado\n");
        fclose(arquivo);
        return 0;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;

        if (contador == numeroLinha) {
            strncpy(idade, linha + 10, 3);
            idade[3] = '\0';

            strncpy(estado, linha + 20, 2);
            estado[2] = '\0';

            printf("Idade: %s\n", idade);
            printf("Estado: %s\n", estado);

            fclose(arquivo);
            return 0;
        }
    }

    printf("registro nao encontrado\n");
    fclose(arquivo);
    return 0;
}
