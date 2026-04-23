#include <stdio.h>
#include <stdlib.h>
typedef struct NO {
    char caractere;
    struct NO *proximoNo;
} NO;
typedef struct {
    NO *inicio, *fim;
    int qtd;
} Fila;
typedef struct {
    char *vtr;
    int tam;
    int topo;
} Pilha;
int isFullPilha (Pilha *p);
int isEmptyPilha (Pilha *p);
void push (Pilha *p, char c);
char pop (Pilha *p);
Pilha *criarPilha (int tam);
Fila *criarFila () {
    Fila *f = malloc (sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}
int isEmpty (Fila *f) {
    return f->qtd == 0;
}

void inserir (Fila *f, char carac) {
    NO *novoNo = malloc (sizeof(NO));
    novoNo->caractere = carac;
    novoNo->proximoNo = NULL;
    if (isEmpty(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
        f->qtd++;
        return;
    }
    f->fim->proximoNo = novoNo;
    f->fim = novoNo;
    f->qtd++;
}
char remover (Fila *f) {
    if (isEmpty(f)) return '\0';
    NO *noRemovido = f->inicio;
    f->inicio = f->inicio->proximoNo;
    char valor = noRemovido->caractere;
    f->qtd--;
    if (f->inicio == NULL) f->fim = NULL;
    free (noRemovido);
    return valor;
}
int size (Fila *f) {
    return f->qtd;
}
void clear (Fila *f) {
    while (!isEmpty(f)) {
        remover(f);
    }  
}
void mostrar (Fila *f) {
    if (isEmpty(f)) {
        printf ("Fila Vazia.\n");
        return;
    }
    NO *noAux = f->inicio;
    while (noAux != NULL) {
        printf ("%c ", noAux->caractere);
        noAux = noAux->proximoNo;
    }
    printf ("\n");

}
void inverter (Fila *f, int flag) {
    Pilha *p = criarPilha(f->qtd);
    while (!isEmpty(f)) {
        push (p, remover(f));
    }
    if (flag) {
        while (!isEmptyPilha(p)) {
            inserir(f, pop(p));
        }
        free (p->vtr);
        free (p);
    } else {
        while (!isEmptyPilha(p)) {
            printf ("%c ", pop(p));
        } 
        free (p->vtr);
        free (p);
    }
}

int main () {

    int op;
    char carac;
    Fila *fila = criarFila();
    char palavra[20];

    do {
        printf ("1. Inserir\n2. Remover\n3. Tamanho Fila\n4. Clear Fila\n5. Print Fila\n6. Size sem remover\n7. Fila inversa e destruir\n8. Fila inversa\n9. Ler palavra\n10. Encerrar\n>");
        scanf ("%d", &op);
        switch (op) {

        case 1:
            printf ("Digite o valor a inserir: ");
            scanf (" %c", &carac);
            inserir(fila, carac);
            break;
        case 2:
            if (isEmpty(fila)) {
                printf ("Fila vazia.\n");
                break;
            }
            printf ("Caractere removido: %c\n", remover (fila));
            break;
        case 3:
            printf ("Tamanho da fila: %d\n", size(fila));
            break;
        case 4:
            clear(fila);
            printf ("Fila Limpa.\n");
            break;
        case 5:
            printf ("Fila: ");
            mostrar(fila);
            break;
        case 6:
            printf ("Tamanho da fila: %d", size(fila));
            break;
        case 7:
            printf ("Fila inversa: ");
            inverter (fila, 0);
            printf ("\n");
            break;
        case 8:
            printf ("Fila inversa: ");
            inverter (fila, 1);
            mostrar (fila);
            break;
        case 9:
            printf ("Digite uma palavra: ");
            scanf ("%19s", palavra);
            for (int i = 0; palavra[i] != '\0'; i++) {
                inserir(fila, palavra[i]);
            }
            break;
        case 10:
            printf ("Encerrando\n");
            break;
        
        default:
            printf ("Opcao invalida");
            break;
        }
    } while (op != 10);

    return 0;
}
int isFullPilha (Pilha *p) {
    return p->topo == p->tam-1;
}
int isEmptyPilha (Pilha *p) {
    return p->topo == -1;
}
void push (Pilha *p, char c) {
    if (isFullPilha(p)) return;
    p->vtr[++p->topo] = c;

}
char pop (Pilha *p) {
    if (isEmptyPilha(p)) return '\0';
    return p->vtr[p->topo--];
}
Pilha *criarPilha (int tam) {
    Pilha *p = malloc (sizeof(Pilha));
    p->vtr = malloc (sizeof(char) * tam);
    p->tam = tam;
    p->topo = -1;
    return p;
}
