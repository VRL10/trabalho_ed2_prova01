#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

void inicializa_arvore_cursos(ArvoreCursos **raiz) {
    *raiz = NULL;
}

void cadastra_curso(ArvoreCursos **raiz, int codigo, char nome[], int quantidade_periodos) {
    if (*raiz == NULL) {
        *raiz = (ArvoreCursos*)malloc(sizeof(ArvoreCursos));
        (*raiz)->curso = (Curso*)malloc(sizeof(Curso));
        (*raiz)->curso->codigo = codigo;
        strcpy((*raiz)->curso->nome, nome);
        (*raiz)->curso->quantidade_periodos = quantidade_periodos;
        (*raiz)->curso->arvore_disciplinas = NULL;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else if (codigo < (*raiz)->curso->codigo) {
        cadastra_curso(&(*raiz)->esq, codigo, nome, quantidade_periodos);
    } else {
        cadastra_curso(&(*raiz)->dir, codigo, nome, quantidade_periodos);
    }
}

Curso* busca_curso(ArvoreCursos *raiz, int codigo) {
    while (raiz != NULL) {
        if (codigo == raiz->curso->codigo) {
            return raiz->curso;
        } else if (codigo < raiz->curso->codigo) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return NULL;
}

void exibe_cursos(ArvoreCursos *raiz) {
    if (raiz != NULL) {
        exibe_cursos(raiz->esq);
        printf("Codigo: %d, Nome: %s, Periodos: %d\n", raiz->curso->codigo, raiz->curso->nome, raiz->curso->quantidade_periodos);
        exibe_cursos(raiz->dir);
    }
}