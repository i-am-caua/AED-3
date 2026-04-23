#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vet;
    int inicio, fim, qtd, tamanho;
} Fila;
typedef struct {
    int topo;
    int tam;
    int *vet;
} Pilha;

Pilha *criarPilha(int tam);
int isFullPilha(Pilha *p);
int isEmptyPilha(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p, int *valor);

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
void filaInversa (Fila *f) {
    Pilha *p = criarPilha(f->tamanho);
    int valorRemovido;
    while (!isEmpty(f)) {
        remover (f, &valorRemovido);
        push(p, valorRemovido);
    }
    while (!isEmptyPilha(p)) {
        pop(p, &valorRemovido);
        inserir(f, valorRemovido);
    }
    free (p->vet);
    free(p);
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
int main () {
    int op, tam;
    int valor;
    
    printf("Tamanho da fila: ");
    scanf("%d", &tam);
    
    Fila *f = criarFila(tam);
    if (f == NULL) return 1;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1.Inserir | 2.Remover | 3.Size | 4.Clear | 5.Print Fila | 6.Inverter Fila | 0.Sair\n> ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Valor: ");
                scanf(" %d", &valor);
                if (inserir(f, valor)) printf("Foi!\n");
                else printf("Fila cheia!\n");
                break;
            case 2:
                if (remover(f, &valor)) printf("Tirou: %d\n", valor);
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
                printf("Fila Invertida: ");
                filaInversa(f);
                printf("Fila: [");
                printFila (f);
                printf("]\n");
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
Pilha *criarPilha(int tam) {
    Pilha *p = malloc (sizeof(Pilha));
    if (p == NULL) return NULL;
    p->vet = malloc (sizeof(int) * tam);
    if (p->vet == NULL) {
        free(p->vet);
        return NULL;
    }
    p->topo = -1;
    p->tam = tam;
    return p;
}
int isFullPilha(Pilha *p) {
    return p->topo == p->tam - 1;
}
int isEmptyPilha(Pilha *p) {
    return p->topo == -1;
}
int push(Pilha *p, int valor) {
    if (isFullPilha(p)) return 0;
    p->vet[++p->topo] = valor;
    return 1;
}
int pop (Pilha *p, int *valor) {
    if (isEmptyPilha(p)) return 0;
    *valor = p->vet[p->topo--];
    return 1;
}
    