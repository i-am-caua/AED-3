#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vet;
    int inicio, fim, qtd, tamanho;
} Fila;

Fila *criarFila (int tam) {
    Fila *f = malloc (sizeof(Fila));
    if (f == NULL) return NULL;
    f->vet = malloc (sizeof(int) * tam);
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
int inserir (Fila *f, int valor) {
    if (isFull(f)) return 0;
    if (f->fim == f->tamanho-1) f->fim = -1;
    f->vet[++f->fim] = valor;
    f->qtd++;
    return 1;
}
int remover (Fila *f, int *valorRemovido) {
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

void printFila (Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    int valorRemovido;
    while (!isEmpty(f)) {
        printf("%d%s", f->vet[f->inicio], f->qtd > 1 ? ", ": "");
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

int maisElementos (Fila *f1, Fila *f2) {
    return f1->qtd > f2->qtd;
}
int main () {
    int op, tam, filaEscolhida;
    int valor;
    
    printf("Tamanho das filas: ");
    scanf("%d", &tam);
    
    Fila *f1 = criarFila(tam);
    Fila *f2 = criarFila(tam);
    if (f1 == NULL || f2 == NULL) return 1;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1.Inserir | 2.Remover | 3.Size | 4.Clear | 5.Print Fila | 6.Comparar Filas | 0.Sair\n> ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Qual fila? (1 ou 2): ");
                scanf("%d", &filaEscolhida);
                printf("Valor: ");
                scanf(" %d", &valor);
                if (filaEscolhida == 1) {
                    if (inserir(f1, valor)) printf("Foi!\n");
                    else printf("Fila cheia!\n");
                } else {
                    if (inserir(f2, valor)) printf("Foi!\n");
                    else printf("Fila cheia!\n");
                }
                break;
            case 2:
                printf("Qual fila? (1 ou 2): ");
                scanf("%d", &filaEscolhida);
                if (filaEscolhida == 1) {
                    if (remover(f1, &valor)) printf("Tirou: %d\n", valor);
                    else printf("Fila Vazia!\n");
                } else {
                    if (remover(f2, &valor)) printf("Tirou: %d\n", valor);
                    else printf("Fila Vazia!\n");
                }
                break;
            case 3:
                printf("F1 tem %d elementos, F2 tem %d elementos\n", size(f1), size(f2));
                break;
            case 4:
                printf("Qual fila? (1 ou 2): ");
                scanf("%d", &filaEscolhida);
                if (filaEscolhida == 1) clear(f1);
                else clear(f2);
                printf("Zerada.\n");
                break;
            case 5:
                printf("F1: [");
                printFila(f1);
                printf("]\n");
                printf("F2: [");
                printFila(f2);
                printf("]\n");
                break;
            case 6:
                if (maisElementos(f1, f2)) printf("F1 possui mais elementos que F2\n");
                else printf("F1 nao possui mais elementos que F2\n");
                break;
                
            case 0:
            printf("Encerrando!\n");
            break;
            default:
            printf("Invalido.\n");
            }
        } while (op != 0);

        free(f1->vet);
        free(f1);
        free(f2->vet);
        free(f2);
        
        return 0;

}
   