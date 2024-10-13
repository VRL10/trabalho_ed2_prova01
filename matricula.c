#include <stdio.h>
#include <stdlib.h>
#include "matricula.h"

void inicializa_arvore_matricula(Matricula **raiz) {
    *raiz = NULL;
}

void cadastrar_aluno_disciplina(Matricula **raiz, int codigo_disciplina) {
    if (*raiz == NULL) {
        *raiz = (Matricula *)malloc(sizeof(Matricula));
        (*raiz)->codigo_disciplina = codigo_disciplina;
        (*raiz)->esq = (*raiz)->dir = NULL;
    } else if (codigo_disciplina < (*raiz)->codigo_disciplina) {
        cadastrar_aluno_disciplina(&(*raiz)->esq, codigo_disciplina);
    } else {
        cadastrar_aluno_disciplina(&(*raiz)->dir, codigo_disciplina);
    }
}

Matricula* encontra_minimo(Matricula *raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

int remove_matricula(Matricula **raiz, int codigo_disciplina) {
    if (*raiz == NULL) {
        return 1; // Matrícula não encontrada
    }

    if (codigo_disciplina < (*raiz)->codigo_disciplina) {
        return remove_matricula(&(*raiz)->esq, codigo_disciplina);
    } else if (codigo_disciplina > (*raiz)->codigo_disciplina) {
        return remove_matricula(&(*raiz)->dir, codigo_disciplina);
    } else {
        Matricula *temp = *raiz;
        if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
        } else if ((*raiz)->dir == NULL) {
            *raiz = (*raiz)->esq;
        } else {
            Matricula *min = encontra_minimo((*raiz)->dir);
            (*raiz)->codigo_disciplina = min->codigo_disciplina;
            remove_matricula(&(*raiz)->dir, min->codigo_disciplina);
        }
        free(temp);
        return 0; // Sucesso
    }
}