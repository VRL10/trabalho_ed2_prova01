#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "curso.h"

int verifica_matricula_existente(ListaAlunos *lista, int matricula) {
    while (lista != NULL) {
        if (lista->aluno->matricula == matricula) {
            return 1; // Matrícula já existe
        }
        lista = lista->prox;
    }
    return 0; // Matrícula não existe
}

void inicializa_lista_alunos(ListaAlunos **lista) {
    *lista = NULL;
}

void cadastra_aluno(ListaAlunos **lista, ArvoreCursos *arvore_cursos, int matricula, char nome[], int codigo_curso) {
    if (verifica_matricula_existente(*lista, matricula)) {
        printf("Erro: Matrícula já existe!\n");
        return;
    }

    if (busca_curso(arvore_cursos, codigo_curso) == NULL) {
        printf("Erro: O curso não está cadastrado!\n");
        return;
    }

    ListaAlunos *novo = (ListaAlunos *)malloc(sizeof(ListaAlunos));
    if (novo != NULL) {
        novo->aluno = (Aluno *)malloc(sizeof(Aluno));
        if (novo->aluno != NULL) {
            novo->aluno->matricula = matricula;
            strcpy(novo->aluno->nome, nome);
            novo->aluno->codigo_curso = codigo_curso;
            novo->aluno->arvore_matricula = NULL;
            novo->aluno->arvore_notas = NULL;

            ListaAlunos *atual = *lista, *anterior = NULL;
            while (atual != NULL && strcmp(atual->aluno->nome, nome) < 0) {
                anterior = atual;
                atual = atual->prox;
            }

            novo->prox = atual;
            if (anterior == NULL) {
                *lista = novo;
            } else {
                anterior->prox = novo;
            }
        } else {
            free(novo);
        }
    }
}

Aluno* busca_aluno(ListaAlunos *lista, int matricula) {
    while (lista != NULL) {
        if (lista->aluno->matricula == matricula) {
            return lista->aluno;
        }
        lista = lista->prox;
    }
    return NULL;
}

void exibe_alunos(ListaAlunos *lista) {
    while (lista != NULL) {
        printf("Matricula: %d, Nome: %s, Codigo do Curso: %d\n",
               lista->aluno->matricula, lista->aluno->nome, lista->aluno->codigo_curso);
        lista = lista->prox;
    }
}

void exibe_disciplinas_aluno(Matricula *raiz) {
    if (raiz == NULL) {
        return;
    }

    exibe_disciplinas_aluno(raiz->esq); // Exibe disciplinas da subárvore esquerda

    // Exibe a disciplina
    printf("Codigo da Disciplina: %d\n", raiz->codigo_disciplina);

    exibe_disciplinas_aluno(raiz->dir); // Exibe disciplinas da subárvore direita
}