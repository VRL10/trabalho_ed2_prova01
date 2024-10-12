#ifndef MATRICULA_H
#define MATRICULA_H

typedef struct Matricula {
    int codigo_disciplina;
    struct Matricula *esq, *dir;
} Matricula;

void inicializa_arvore_matricula(Matricula **raiz);
void cadastra_matricula(Matricula **raiz, int codigo_disciplina);
void cadastrar_aluno_disciplina(Matricula **raiz, int codigo_disciplina);
int remove_matricula(Matricula **raiz, int codigo_disciplina);
Matricula* encontra_minimo(Matricula *raiz);

#endif