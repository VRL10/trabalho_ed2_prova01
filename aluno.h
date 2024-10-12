#ifndef ALUNO_H
#define ALUNO_H

#include "matricula.h"
#include "nota.h"
#include "curso.h"

typedef struct Aluno {
    int matricula;
    char nome[50];
    int codigo_curso;
    Matricula *arvore_matricula;
    Nota *arvore_notas;
} Aluno;

typedef struct ListaAlunos {
    Aluno *aluno;
    struct ListaAlunos *prox;
} ListaAlunos;

void inicializa_lista_alunos(ListaAlunos **lista);
void cadastra_aluno(ListaAlunos **lista, ArvoreCursos *arvore_cursos, int matricula, char nome[], int codigo_curso);
Aluno* busca_aluno(ListaAlunos *lista, int matricula);
void exibe_alunos(ListaAlunos *lista);
void exibe_disciplinas_aluno(Matricula *raiz);  // Exibe disciplinas de um aluno
void cadastrar_aluno_disciplina(Aluno *aluno, int codigo_disciplina);

#endif