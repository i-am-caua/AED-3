     #include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *vet;
    int inicio, fim, qtd, tamanho;
} FilaReal;

FilaReal *criarFila (int tam) {
    FilaReal *f = malloc (sizeof(FilaReal));
    if (f == NULL) return NULL;
    f->vet = malloc (sizeof(double) * tam);
    if (f->vet == NULL) {
        free(f);
        return NULL;
    }
    f->fim = -1;
    f->inicio = 0;
    f->qtd = 0;
    f->tamanho = tam;
    return f;
}

int isFull (FilaReal *f) {
    return f->qtd == f->tamanho;
}

int isEmpty (FilaReal *f) {
    return f->qtd == 0;
}

int inserir (FilaReal *f, double valor) {
    if (isFull(f)) return 0;
    if (f->fim == f->tamanho - 1) f->fim = -1;
    f->vet[++f->fim] = valor;
    f->qtd++;
    return 1;
}

int remover (FilaReal *f, double *valorRemovido) {
    if (isEmpty(f)) return 0;
    *valorRemovido = f->vet[f->inicio];
    if (f->inicio == f->tamanho - 1) f->inicio = -1;
    f->inicio++;
    f->qtd--;
    return 1;
}

int calcularEstatisticas(FilaReal *f, double *maior, double *menor, double *media) {
    if (isEmpty(f)) return 0;

    int n = f->qtd;
    double soma = 0.0;
    double valor;

    for (int i = 0; i < n; i++) {
        remover(f, &valor);

        if (i == 0) {
            *maior = valor;
            *menor = valor;
        } else {
            if (valor > *maior) *maior = valor;
            if (valor < *menor) *menor = valor;
        }

        soma += valor;
        inserir(f, valor);
    }

    *media = soma / n;
    return 1;
}

int main () {
    double valores[] = {10.5, 3.2, 8.9, 15.7, 6.4};
    int n = sizeof(valores) / sizeof(double);

    FilaReal *f = criarFila(n);
    if (f == NULL) return 1;

    for (int i = 0; i < n; i++) inserir(f, valores[i]);

    double maior, menor, media;
    if (calcularEstatisticas(f, &maior, &menor, &media)) {
        printf("Maior: %.2lf\n", maior);
        printf("Menor: %.2lf\n", menor);
        printf("Media: %.2lf\n", media);
    }

    free(f->vet);
    free(f);
    return 0;
}
