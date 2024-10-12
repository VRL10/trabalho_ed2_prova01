#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

void inicializa_arvore_disciplinas(ArvoreDisciplinas **raiz) {
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

    if (*raiz == NULL) {
        *raiz = (ArvoreDisciplinas *)malloc(sizeof(ArvoreDisciplinas));
        (*raiz)->disciplina = (Disciplina *)malloc(sizeof(Disciplina));
        (*raiz)->disciplina->codigo = codigo;
        strcpy((*raiz)->disciplina->nome, nome);
        (*raiz)->disciplina->periodo = periodo;
        (*raiz)->disciplina->carga_horaria = carga_horaria;
        (*raiz)->esq = (*raiz)->dir = NULL;
    } else if (codigo < (*raiz)->disciplina->codigo) {
        cadastra_disciplina(&(*raiz)->esq, codigo, nome, periodo, carga_horaria, max_periodos);
    } else {
        cadastra_disciplina(&(*raiz)->dir, codigo, nome, periodo, carga_horaria, max_periodos);
    }
}

Disciplina* busca_disciplina(ArvoreDisciplinas *raiz, int codigo) {
    while (raiz != NULL) {
        if (codigo == raiz->disciplina->codigo) {
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

// Função para exibir todas as disciplinas de um curso
void exibir_disciplinas_curso(ArvoreDisciplinas *raiz) {
    if (raiz == NULL) {
        printf("Nenhuma disciplina cadastrada!\n");
        return;
    }

    exibe_disciplinas(raiz);  // Reutiliza a função já existente para exibir todas as disciplinas
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