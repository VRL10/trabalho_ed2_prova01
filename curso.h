#ifndef CURSO_H
#define CURSO_H

#include "disciplina.h"

typedef struct Curso {
    int codigo;
    char nome[50];
    int quantidade_periodos;
    ArvoreDisciplinas *arvore_disciplinas;
} Curso;

typedef struct ArvoreCursos {
    Curso *curso;
    struct ArvoreCursos *esq, *dir;
} ArvoreCursos;

void inicializa_arvore_cursos(ArvoreCursos **raiz);
void cadastra_curso(ArvoreCursos **raiz, int codigo, char nome[], int quantidade_periodos);
Curso* busca_curso(ArvoreCursos *raiz, int codigo);
void exibe_cursos(ArvoreCursos *raiz);

#endif