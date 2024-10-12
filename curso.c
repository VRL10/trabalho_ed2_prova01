#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

int verifica_codigo_curso_existente(ArvoreCursos *raiz, int codigo) {
    while (raiz != NULL) {
        if (raiz->curso->codigo == codigo) {
            return 1; // Código de curso já existe
        }
        if (codigo < raiz->curso->codigo) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return 0; // Código de curso não existe
}

void inicializa_arvore_cursos(ArvoreCursos **raiz) {
    *raiz = NULL;
}

void cadastra_curso(ArvoreCursos **raiz, int codigo, char nome[], int quantidade_periodos) {
    if (verifica_codigo_curso_existente(*raiz, codigo)) {
        printf("Erro: Código de curso já existe!\n");
        return;
    }

    ArvoreCursos *novo = (ArvoreCursos *)malloc(sizeof(ArvoreCursos));
    if (novo != NULL) {
        novo->curso = (Curso *)malloc(sizeof(Curso));
        if (novo->curso != NULL) {
            novo->curso->codigo = codigo;
            strcpy(novo->curso->nome, nome);
            novo->curso->quantidade_periodos = quantidade_periodos;
            novo->curso->arvore_disciplinas = NULL;
            novo->esq = novo->dir = NULL;

            if (*raiz == NULL) {
                *raiz = novo;
            } else {
                ArvoreCursos *atual = *raiz, *anterior = NULL;
                while (atual != NULL) {
                    anterior = atual;
                    if (codigo < atual->curso->codigo) {
                        atual = atual->esq;
                    } else {
                        atual = atual->dir;
                    }
                }

                if (codigo < anterior->curso->codigo) {
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

Curso* busca_curso(ArvoreCursos *raiz, int codigo) {
    while (raiz != NULL) {
        if (raiz->curso->codigo == codigo) {
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