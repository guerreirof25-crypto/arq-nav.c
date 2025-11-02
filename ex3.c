#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s nome_arquivo\n", argv[0]);
        return 1;
    }

    const char *arquivo = argv[1];
    const char *meio = "|meio|";
    FILE *f = fopen(arquivo, "r+b");
    if (!f) {
        perror("Nao abriu");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    long metade = tamanho / 2;
    long sobra = tamanho - metade;
    char *buf = NULL;

    if (sobra > 0) {
        buf = malloc((size_t)sobra);
        fseek(f, metade, SEEK_SET);
        fread(buf, 1, (size_t)sobra, f);
    }

    fseek(f, metade, SEEK_SET);
    fwrite(meio, 1, strlen(meio), f);
    if (sobra > 0) {
        fwrite(buf, 1, (size_t)sobra, f);
        free(buf);
    }

    fclose(f);
    return 0;
}
