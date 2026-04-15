#include <stdio.h>
#include <stdlib.h>
#define ERRO -99999999.0

typedef struct {
    int fim, inicio, tamanho;
    double *vet;
} Fila;
typedef struct {
    int topo;
    int tam;
    double *vet;
 } Pilha;

Pilha *criarPilha(int tam);
int isFullPilha(Pilha *p);
int isEmptyPilha(Pilha *p);
int push(Pilha *p, double valor);
double pop(Pilha *p);

Fila *criarFila (int tamanho) {
    Fila *f = malloc (sizeof(Fila));
    if (f == NULL) {
        return NULL;
    }

    f->vet = malloc (tamanho * sizeof(double));
    if (f->vet == NULL) {
        free(f);
        return NULL;
    }

    f->inicio = 0;
    f->fim = -1;
    f->tamanho = tamanho;
    return f;
}
int isEmpty (Fila *f) {
    return f->inicio > f->fim;
}
int isFull (Fila *f) {
    return f->fim == f->tamanho - 1;
}
int inserir (Fila *f, double valor) {
    if (isFull(f)) return 0;

    f->fim++;
    f->vet[f->fim] = valor;
    return 1;
}
double remover (Fila *f) {
    if (isEmpty(f)) {
        return ERRO;
    }
    return f->vet[f->inicio++];
}
int size (Fila *f) {
    return (f->fim - f->inicio) + 1;
}
void clear (Fila *f) {
    f->fim = -1;
    f->inicio = 0;
}
void filaInversa (Fila *f) {
    Pilha *p = criarPilha(f->tamanho);
   while (!isEmpty(f)) {
        push(p, remover(f));
    }
    clear (f);
    while (!isEmptyPilha(p)) {
        inserir(f, pop(p));
    }
}
void printFila (Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    while (!isEmpty(f)) {
        printf("%.2f%s", f->vet[f->inicio], f->inicio < f->fim ? ", ": "");
        inserir(filaAux, remover(f));
    }
    clear(f);
    while (!isEmpty(filaAux)) {
        inserir (f, remover(filaAux));
    }
    free (filaAux->vet);
    free (filaAux);
    
}

int main() {
    int op, tam;
    double val;
    
    printf("Tamanho da fila: ");
    scanf("%d", &tam);
    
    Fila *f = criarFila(tam);
    if (f == NULL) return 1;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1.Inserir | 2.Remover | 3.Size | 4.Clear | 5.Inverter | 0.Sair\n> ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
            printf("Valor: ");
            scanf("%lf", &val);
            if (inserir(f, val)) printf("Foi!\n");
            else printf("Fila cheia!\n");
            break;
            case 2:
            val = remover(f);
            if (val == ERRO) printf("Fila vazia!\n");
            else printf("Tirou: %.2f\n", val);
            break;
            case 3:
            printf("Tamanho: %d\n", size(f));
            break;
            case 4:
            clear(f);
            printf("Zerada.\n");
            break;
            case 5:
            if (isEmpty(f)) {
                printf("Vazia.\n");
                break;
            }
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
    p->vet = malloc (sizeof(double) * tam);
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
int push(Pilha *p, double valor) {
    if (isFullPilha(p)) return 0;
    p->vet[++p->topo] = valor;
    return 1;
}
double pop (Pilha *p) {
    if (isEmptyPilha(p)) return ERRO;
    return p->vet[p->topo--];
}
    