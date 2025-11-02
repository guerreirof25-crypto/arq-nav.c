long tamanho(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "rb");
    if (!arq) return -1;

    long bytes = 0;
    while (fgetc(arq) != EOF)
        bytes++;

    fclose(arq);
    return bytes;
}
