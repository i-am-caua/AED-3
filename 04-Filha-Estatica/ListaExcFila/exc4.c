#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *vet;
    int inicio, fim, qtd, tamanho;
} Fila;

Fila *criarFila (int tam) {
    Fila *f = malloc (sizeof(Fila));
    if (f == NULL) return NULL;
    f->vet = malloc (sizeof(char) * tam);
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
int isFull (Fila *f) {
    return f->qtd == f->tamanho;
}
int isEmpty (Fila *f) {
    return f->qtd == 0;
}
int inserir (Fila *f, char valor) {
    if (isFull(f)) return 0;
    if (f->fim == f->tamanho-1) f->fim = -1;
    f->vet[++f->fim] = valor;
    f->qtd++;
    return 1;
}
int remover (Fila *f, char *valorRemovido) {
    if (isEmpty(f)) return 0;
    *valorRemovido = f->vet[f->inicio];
    if (f->inicio == f->tamanho-1) f->inicio = -1;
    f->inicio++;
    f->qtd--;
    return 1;
}
int size (Fila *f) {
    return f->qtd;
}
void clear (Fila *f) {
    f->fim = -1;
    f->inicio = 0;
    f->qtd = 0;
}
int furaFila (Fila *f, char valor) {
    if (isFull(f)) return 0;
    if (isEmpty(f)) return inserir(f, valor);
    if (f->inicio == 0) f->inicio = f->tamanho-1;
    else f->inicio--;
    f->vet[f->inicio] = valor;
    f->qtd++;
    return 1;

}
void printFila (Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    char valorRemovido;
    while (!isEmpty(f)) {
        printf("%c%s", f->vet[f->inicio], f->qtd > 1 ? ", ": "");
        remover(f, &valorRemovido);
        inserir(filaAux, valorRemovido);
    }
    while (!isEmpty(filaAux)) {
        remover(filaAux, &valorRemovido);
        inserir (f, valorRemovido);
    }
    free (filaAux->vet);
    free (filaAux);
    
}
int main () {
    int op, tam;
    char valor;
    
    printf("Tamanho da fila: ");
    scanf("%d", &tam);
    
    Fila *f = criarFila(tam);
    if (f == NULL) return 1;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1.Inserir | 2.Remover | 3.Size | 4.Clear | 5.Print Fila | 6.Furar Fila | 0.Sair\n> ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Caractere: ");
                scanf(" %c", &valor);
                if (inserir(f, valor)) printf("Foi!\n");
                else printf("Fila cheia!\n");
                break;
            case 2:
                if (remover(f, &valor)) printf("Tirou: %c\n", valor);
                else printf("Fila Vazia!\n");
                break;
            case 3:
                printf("Tamanho: %d\n", size(f));
                break;
            case 4:
                clear(f);
                printf("Zerada.\n");
                break;
            case 5:
                printf("Fila: [");
                printFila (f);
                printf("]\n");
                break;
            case 6:
                printf("Caractere: ");
                scanf (" %c", &valor);
                if (furaFila(f, valor)) printf ("Fila furada!\n");
                else printf("Fila cheia, nao eh possivel furar!");
                break;
                
            case 0:
            printf("Encerrando!\n");
            break;
            default:
            printf("Invalido.\n");
            }
        } while (op != 0);

        free(f->vet);
        free(f);
        
        return 0;

}