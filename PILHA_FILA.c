#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct Node {
    char nucleotideo;
    struct Node* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

typedef struct NoPilha {
    char nucleotideo;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila* fila, char nucleotideo) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

void desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    No* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
}

void imprimirFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void empilhar(Pilha* pilha, char nucleotideo) {
    NoPilha* novoNo = (NoPilha*)malloc(sizeof(NoPilha));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

void desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    }

    NoPilha* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

void imprimirPilha(Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int novo = 1;

    while (novo) {
        printf("Digite a sequência de nucleotídeos: ");
        char dna[100];
        scanf("%s", dna);

        int len = strlen(dna);
        dna[len] = '\0';

        Fila* fila = criarFila();

        int i;
        for (i = 0; i < len; i++) {
            char nucleotideo = toupper(dna[i]);

            if (nucleotideo != 'A' && nucleotideo != 'C' && nucleotideo != 'T' && nucleotideo != 'G') {
                printf("\nLetra inválida! Por favor, digite apenas as letras A, C, T ou G.\n\n");
                break;
            }

            enfileirar(fila, nucleotideo);

            if (i == len - 1) {
                novo = 0;
            }
        }

        if (novo) {
            free(fila);
            continue;
        }

        Pilha* pilha = criarPilha();

        printf("Fila: ");
        imprimirFila(fila);

        while (!filaVazia(fila)) {
            char nucleotideo = fila->inicio->nucleotideo;
            desenfileirar(fila);

            switch (nucleotideo) {
                case 'A':
                    nucleotideo = 'T';
                    break;
                case 'T':
                    nucleotideo = 'A';
                    break;
                case 'C':
                    nucleotideo = 'G';
                    break;
                case 'G':
                    nucleotideo = 'C';
                    break;
            }

            empilhar(pilha, nucleotideo);
        }

        printf("Pilha: ");
        imprimirPilha(pilha);

        free(fila);
        free(pilha);
    }

    return 0;
}


