
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *AlocaVetor (int tamV) {
    char *str = (char *) malloc ((tamV + 1)* sizeof (char));
    return str;
}
int ehVogal (char letra) {
    if (letra == 'a' || letra == 'A' ||
        letra == 'e' || letra == 'E' ||
        letra == 'i' || letra == 'I' ||
        letra == 'o' || letra == 'O' ||
        letra == 'u' || letra == 'U') {
            return 1;
        } else {
            return 0;
        }
}

int main()
{
    
    int tamV;
    
    printf ("DIgite o tamanho do str:\n");
    fflush(stdout);
    scanf ("%d", &tamV);
    char *str = AlocaVetor(tamV);
    getchar();
    printf ("\nDigite a str: ");
    fgets (str, tamV + 1, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf ("\nStr sem vogais: ");

    for (int i = 0; i < tamV; i++) {
        if (ehVogal(str[i]) == 0) {
            printf("%c", str[i]);
        }
    }
    
    return 0;
}
