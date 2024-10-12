#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct Disciplina {
    int codigo;
    char nome[50];
    int periodo;
    int carga_horaria;
} Disciplina;

typedef struct ArvoreDisciplinas {
    Disciplina *disciplina;
    struct ArvoreDisciplinas *esq, *dir;
} ArvoreDisciplinas;

void inicializa_arvore_disciplinas(ArvoreDisciplinas **raiz);
void cadastra_disciplina(ArvoreDisciplinas **raiz, int codigo, char nome[], int periodo, int carga_horaria, int max_periodos);
Disciplina* busca_disciplina(ArvoreDisciplinas *raiz, int codigo);
void exibe_disciplinas(ArvoreDisciplinas *raiz);
void exibe_disciplinas_por_periodo(ArvoreDisciplinas *raiz, int periodo);
int remove_disciplina(ArvoreDisciplinas **raiz, int codigo_disciplina);

#endif