
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char Snome[50];
    int anoN;
} alunos;

int main() {
    alunos *n1;
    int qtd;
    printf ("Digite a quantidade de alunos:\n");
    scanf ("%d", &qtd);
    n1 = (alunos *) malloc (qtd * sizeof(int));

    for (int i = 0; i < qtd; i++) {
        printf ("Digite a matricula: ");
        scanf ("%d",&n1[i].matricula);
        printf ("Digite o nome: ");
        scanf ("%s", n1[i].Snome);
        printf ("Digite o ano de nascimento: ");
        scanf ("%d", &n1[i].anoN);
    }
    printf("\n\n");
    for (int i = 0; i < qtd; i++) {
        printf ("Matricula: %d\nSobrenome: %s\nAno de nascimento: %d \n", n1[i].matricula, n1[i].Snome, n1[i].anoN);
        
    }
    free(n1); 
    return 0;
}
