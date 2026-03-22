# 02 — Tipo Abstrato de Dados (TAD) e Pilha

Exercícios sobre Tipos Abstratos de Dados com separação em `.h` (interface) e `.c` (implementação), além de exercícios introdutórios de pilha.

## Exercícios

| Pasta/Arquivo | Descrição |
|---|---|
| `ex02-contador/` | TAD Contador — incrementar, decrementar, obter valor |
| `ex03-data/` | TAD Data — criar, validar, comparar e imprimir datas |
| `ex04-sequencia.c` | Exercício com sequência |
| `ex05-completa.c` | Exercício completo |
| `ex06-estrutura.c` | Definição de estrutura |
| `ex07-main.c` | Exercício com main |
| `ex08-quantidade.c` | Exercício com quantidade |
| `ex09-limpar.c` | Exercício com limpeza |

## Como compilar

```bash
# Exercícios com TAD (múltiplos arquivos)
cd ex02-contador/
gcc main.c contador.c -o contador
./contador

# Exercícios de arquivo único
gcc ex04-sequencia.c -o ex04
./ex04
```
