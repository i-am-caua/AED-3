#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    float valor;
    struct NO *proximo;
} NO;

typedef struct {
    NO *inicio;
} Lista;

Lista *criarLista () {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int estaVazia (Lista *l) {
    return l->inicio == NULL;
}

void inserir (Lista *l, float valor) {
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    if (estaVazia(l)) {
        novo->proximo = novo;
        l->inicio = novo;
        return;
    }
    NO *aux = l->inicio;
    while (aux->proximo != l->inicio) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    novo->proximo = l->inicio;
}

void inserirPosicao (Lista *l, float valor, int pos) {
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    if (estaVazia(l)) {
        novo->proximo = novo;
        l->inicio = novo;
        return;
    }
    if (pos == 0) {
        NO *ultimo = l->inicio;
        while (ultimo->proximo != l->inicio) {
            ultimo = ultimo->proximo;
        }
        novo->proximo = l->inicio;
        ultimo->proximo = novo;
        l->inicio = novo;
        return;
    }
    NO *aux = l->inicio;
    int i;
    for (i = 0; i < pos - 1 && aux->proximo != l->inicio; i++) {
        aux = aux->proximo;
    }
    novo->proximo = aux->proximo;
    aux->proximo = novo;
}

float remover (Lista *l, int pos) {
    if (estaVazia(l)) return -1;
    NO *aux = l->inicio;
    NO *anterior = NULL;
    int i;
    if (pos == 0) {
        float valor = aux->valor;
        if (aux->proximo == l->inicio) {
            l->inicio = NULL;
        } else {
            NO *ultimo = l->inicio;
            while (ultimo->proximo != l->inicio) {
                ultimo = ultimo->proximo;
            }
            l->inicio = aux->proximo;
            ultimo->proximo = l->inicio;
        }
        free(aux);
        return valor;
    }
    for (i = 0; i < pos && aux->proximo != l->inicio; i++) {
        anterior = aux;
        aux = aux->proximo;
    }
    if (i < pos) return -1;
    float valor = aux->valor;
    anterior->proximo = aux->proximo;
    free(aux);
    return valor;
}

float consultar (Lista *l, int pos) {
    if (estaVazia(l)) return -1;
    NO *aux = l->inicio;
    int i;
    for (i = 0; i < pos && aux->proximo != l->inicio; i++) {
        aux = aux->proximo;
    }
    if (i < pos && pos != 0) return -1;
    return aux->valor;
}

int size (Lista *l) {
    if (estaVazia(l)) return 0;
    int cont = 1;
    NO *aux = l->inicio->proximo;
    while (aux != l->inicio) {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

void clear (Lista *l) {
    while (!estaVazia(l)) {
        remover(l, 0);
    }
}

void mostrar (Lista *l) {
    if (estaVazia(l)) {
        printf("Lista Vazia.\n");
        return;
    }
    NO *aux = l->inicio;
    do {
        printf("%.2f ", aux->valor);
        aux = aux->proximo;
    } while (aux != l->inicio);
    printf("\n");
}

void ordenar (Lista *l) {
    if (estaVazia(l) || l->inicio->proximo == l->inicio) return;
    int trocou;
    do {
        trocou = 0;
        NO *aux = l->inicio;
        do {
            if (aux->valor > aux->proximo->valor && aux->proximo != l->inicio) {
                float temp = aux->valor;
                aux->valor = aux->proximo->valor;
                aux->proximo->valor = temp;
                trocou = 1;
            }
            aux = aux->proximo;
        } while (aux != l->inicio);
    } while (trocou);
}

int main () {
    Lista *l = criarLista();
    int op, pos;
    float valor;

    do {
        printf("1. Inserir\n2. Inserir Posicao\n3. Remover\n4. Esta Vazia\n5. Consultar\n6. Size\n7. Clear\n8. Mostrar\n9. Ordenar\n10. Encerrar\n> ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Valor: ");
                scanf("%f", &valor);
                inserir(l, valor);
                break;
            case 2:
                printf("Valor e Posicao: ");
                scanf("%f %d", &valor, &pos);
                inserirPosicao(l, valor, pos);
                break;
            case 3:
                printf("Posicao: ");
                scanf("%d", &pos);
                printf("Removido: %.2f\n", remover(l, pos));
                break;
            case 4:
                printf("%s\n", estaVazia(l) ? "Sim" : "Nao");
                break;
            case 5:
                printf("Posicao: ");
                scanf("%d", &pos);
                printf("Valor: %.2f\n", consultar(l, pos));
                break;
            case 6:
                printf("Tamanho: %d\n", size(l));
                break;
            case 7:
                clear(l);
                printf("Lista Limpa.\n");
                break;
            case 8:
                mostrar(l);
                break;
            case 9:
                ordenar(l);
                printf("Lista Ordenada.\n");
                break;
            case 10:
                printf("Encerrando\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (op != 10);

    clear(l);
    free(l);
    return 0;
}
