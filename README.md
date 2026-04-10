# AED-3 — Algoritmos e Estruturas de Dados 3

Repositório com implementações e exercícios da disciplina AED-3 em C.

---

## 03 — Pilha Estática

Implementação e exercícios com pilha estática (stack) usando vetores em C.

### Parte 1 — Fundamentos (Prof. Substituta)
| Arquivo | Descrição |
|---|---|
| `ex01.c` | Implementação básica de pilha — push, pop, isEmpty, isFull |
| `ex02.c` | Exercício com operações de pilha |
| `ex03.c` | Exercício avançado de pilha |
| `ex04.c` | Exercício adicional de pilha |

### Parte 2 — Exercícios Avançados (Prof. Substituta)
| Arquivo | Descrição |
|---|---|
| `ex01.c` | Exercício avançado 1 |
| `ex02.c` | Exercício avançado 2 |
| `ex03.c` | Exercício avançado 3 |

### pilhaProfThermer — Exercícios do Prof. Thermer
Exercícios passados pelo novo professor titular da disciplina.

| Arquivo | Descrição |
|---|---|
| `exc1.c` | Exercício 1 |
| `exc2.c` | Exercício 2 |
| `exc3.c` | Exercício 3 |

---

## 04 — Fila Estática

Implementação e exercícios com fila estática (queue) usando vetores em C.

### Estrutura base
| Arquivo | Descrição |
|---|---|
| `estruturaFila.c` | Implementação completa de fila — criarFila, inserir, remover, isEmpty, isFull, imprimirFila com menu interativo |

### ListaExcFila — Lista de Exercícios de Fila
| Arquivo | Descrição |
|---|---|
| `exc3.c` | Exercício de fila com operações adicionais — size, clear |

---

## Como compilar

```bash
# Exercícios de Pilha (parte1/parte2)
cd 03-Pilha-Estatica/parte1/
gcc ex01.c -o ex01

# Exercícios de Pilha do Prof. Thermer
cd 03-Pilha-Estatica/pilhaProfThermer/
gcc exc1.c -o exc1

# Estrutura de Fila
cd 04-Filha-Estatica/
gcc estruturaFila.c -o estruturaFila

# Exercícios de Fila
cd 04-Filha-Estatica/ListaExcFila/
gcc exc3.c -o exc3
```
