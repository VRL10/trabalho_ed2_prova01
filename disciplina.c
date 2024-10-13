#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"

int verifica_codigo_disciplina_existente(ArvoreDisciplinas *raiz, int codigo) {
    while (raiz != NULL) {
        if (raiz->disciplina->codigo == codigo) {
            return 1; // Código de disciplina já existe
        }
        if (codigo < raiz->disciplina->codigo) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return 0; // Código de disciplina não existe
}

void inicializa_arvore_disciplinas(ArvoreDisciplinas ** raiz) {
    *raiz = NULL;
}

void cadastra_disciplina(ArvoreDisciplinas **raiz, int codigo, char nome[], int periodo, int carga_horaria, int max_periodos) {
    if (periodo < 1 || periodo > max_periodos) {
        printf("Período inválido!\n");
        return;
    }
    if (carga_horaria % 15 != 0 || carga_horaria < 30 || carga_horaria > 90) {
        printf("Carga horária inválida!\n");
        return;
    }

    if (verifica_codigo_disciplina_existente(*raiz, codigo)) {
        printf("Erro: Código de disciplina já existe!\n");
        return;
    }

    ArvoreDisciplinas *novo = (ArvoreDisciplinas *)malloc(sizeof(ArvoreDisciplinas));
    if (novo != NULL) {
        novo->disciplina = (Disciplina *)malloc(sizeof(Disciplina));
        if (novo->disciplina != NULL) {
            novo->disciplina->codigo = codigo;
            strcpy(novo->disciplina->nome, nome);
            novo->disciplina->periodo = periodo;
            novo->disciplina->carga_horaria = carga_horaria;
            novo->esq = novo->dir = NULL;

            if (*raiz == NULL) {
                *raiz = novo;
            } else {
                ArvoreDisciplinas *atual = *raiz, *anterior = NULL;
                while (atual != NULL) {
                    anterior = atual;
                    if (codigo < atual->disciplina->codigo) {
                        atual = atual->esq;
                    } else {
                        atual = atual->dir;
                    }
                }

                if (codigo < anterior->disciplina->codigo) {
                    anterior->esq = novo;
                } else {
                    anterior->dir = novo;
                }
            }
        } else {
            free(novo);
        }
    }
}

Disciplina* busca_disciplina(ArvoreDisciplinas *raiz, int codigo) {
    while (raiz != NULL) {
        if (raiz->disciplina->codigo == codigo) {
            return raiz->disciplina;
        } else if (codigo < raiz->disciplina->codigo) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return NULL;
}

void exibe_disciplinas(ArvoreDisciplinas *raiz) {
    if (raiz != NULL) {
        exibe_disciplinas(raiz->esq);
        printf("Codigo: %d, Nome: %s, Periodo: %d, Carga Horaria: %d\n",
               raiz->disciplina->codigo, raiz->disciplina->nome, raiz->disciplina->periodo, raiz->disciplina->carga_horaria);
        exibe_disciplinas(raiz->dir);
    }
}

void exibe_disciplinas_por_periodo(ArvoreDisciplinas *raiz, int periodo) {
    if (raiz == NULL) {
        return;
    }

    exibe_disciplinas_por_periodo(raiz->esq, periodo); // Percorre a subárvore esquerda

    if (raiz->disciplina->periodo == periodo) {
        printf("Codigo: %d, Nome: %s, Periodo: %d, Carga Horaria: %d\n",
               raiz->disciplina->codigo, raiz->disciplina->nome, raiz->disciplina->periodo, raiz->disciplina->carga_horaria);
    }

    exibe_disciplinas_por_periodo(raiz->dir, periodo); // Percorre a subárvore direita
}