#include <stdio.h>
#include <stdlib.h>
#include "nota.h"

void inicializa_arvore_notas(Nota **raiz) {
    *raiz = NULL;
}

void cadastra_nota(Nota **raiz, int codigo_disciplina, int semestre, float nota_final) {
    Nota *novo = (Nota *)malloc(sizeof(Nota));
    novo->codigo_disciplina = codigo_disciplina;
    novo->semestre = semestre;
    novo->nota_final = nota_final;
    novo->esq = novo->dir = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        Nota *atual = *raiz, *anterior = NULL;
        while (atual != NULL) {
            anterior = atual;
            if (codigo_disciplina < atual->codigo_disciplina) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }
        if (codigo_disciplina < anterior->codigo_disciplina) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    }
} //teste