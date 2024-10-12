#ifndef NOTA_H
#define NOTA_H

typedef struct Nota {
    int codigo_disciplina;
    int semestre;
    float nota_final;
    struct Nota *esq, *dir;
} Nota;

void inicializa_arvore_notas(Nota **raiz);
void cadastra_nota(Nota **raiz, int codigo_disciplina, int semestre, float nota_final);

#endif