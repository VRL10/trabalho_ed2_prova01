#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "curso.h"
#include "disciplina.h"
#include "matricula.h"
#include "nota.h"

int menu() {
    int opcao;
    printf("\n------ Menu Principal ------\n");
    printf("1. Cadastrar Curso\n");
    printf("2. Cadastrar Disciplina\n");
    printf("3. Cadastrar Aluno\n");
    printf("4. Exibir Cursos\n");
    printf("5. Exibir Alunos\n");
    printf("6. Exibir Disciplinas de um Curso\n");
    printf("7. Exibir Disciplinas por Periodo de um Curso\n");
    printf("8. Exibir Disciplinas de um Aluno\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função auxiliar para cadastro de cursos
void cadastrar_curso(ArvoreCursos **arvore_cursos) {
    int codigo, qtd_periodos;
    char nome[50];

    printf("Digite o codigo do curso: ");
    scanf("%d", &codigo);
    printf("Digite o nome do curso: ");
    scanf("%s", nome);
    printf("Digite a quantidade de períodos do curso: ");
    scanf("%d", &qtd_periodos);

    cadastra_curso(arvore_cursos, codigo, nome, qtd_periodos);
}

// Função auxiliar para cadastro de disciplinas
void cadastrar_disciplina(ArvoreCursos *arvore_cursos) {
    int codigo_curso, codigo_disciplina, periodo, carga_horaria;
    char nome_disciplina[50];
    Curso *curso;

    printf("Digite o código do curso ao qual a disciplina pertence: ");
    scanf("%d", &codigo_curso);

    curso = busca_curso(arvore_cursos, codigo_curso);
    if (curso == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    printf("Digite o código da disciplina: ");
    scanf("%d", &codigo_disciplina);
    printf("Digite o nome da disciplina: ");
    scanf("%s", nome_disciplina);
    printf("Digite o período da disciplina: ");
    scanf("%d", &periodo);
    printf("Digite a carga horária da disciplina (múltiplo de 15 entre 30 e 90): ");
    scanf("%d", &carga_horaria);

    cadastra_disciplina(&curso->arvore_disciplinas, codigo_disciplina, nome_disciplina, periodo, carga_horaria, curso->quantidade_periodos);
}

// Função auxiliar para cadastro de alunos
void cadastrar_aluno(ListaAlunos **lista_alunos, ArvoreCursos *arvore_cursos) {
    int matricula, codigo_curso;
    char nome[50];

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite o código do curso do aluno: ");
    scanf("%d", &codigo_curso);

    cadastra_aluno(lista_alunos, arvore_cursos, matricula, nome, codigo_curso);
}

// Função auxiliar para exibir disciplinas de um período de um curso
void exibir_disciplinas_por_periodo(ArvoreCursos *arvore_cursos) {
    int codigo_curso, periodo;
    Curso *curso;

    printf("Digite o código do curso: ");
    scanf("%d", &codigo_curso);
    printf("Digite o período desejado: ");
    scanf("%d", &periodo);

    curso = busca_curso(arvore_cursos, codigo_curso);
    if (curso == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    printf("\nDisciplinas do curso %s no período %d:\n", curso->nome, periodo);
    exibe_disciplinas_por_periodo(curso->arvore_disciplinas, periodo);
}

// Função auxiliar para exibir disciplinas nas quais um aluno está matriculado
void exibir_disciplinas_aluno(ListaAlunos *lista_alunos) {
    int matricula;
    Aluno *aluno;

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);

    aluno = busca_aluno(lista_alunos, matricula);
    if (aluno == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }

    printf("\nDisciplinas em que o aluno %s está matriculado:\n", aluno->nome);
    exibe_disciplinas_aluno(aluno->arvore_matricula);
}

int main() {
    ArvoreCursos *arvore_cursos;
    ListaAlunos *lista_alunos;
    int opcao;

    inicializa_arvore_cursos(&arvore_cursos);
    inicializa_lista_alunos(&lista_alunos);

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                cadastrar_curso(&arvore_cursos);
                break;
            case 2:
                cadastrar_disciplina(arvore_cursos);
                break;
            case 3:
                cadastrar_aluno(& lista_alunos, arvore_cursos);
                break;
            case 4:
                exibe_cursos(arvore_cursos);
                break;
            case 5:
                exibe_alunos(lista_alunos);
                break;
            case 6:
                printf("Digite o código do curso para exibir as disciplinas:\n");
                int codigo_curso;
                scanf("%d", &codigo_curso);
                Curso *curso = busca_curso(arvore_cursos, codigo_curso);
                if (curso != NULL) {
                    exibe_disciplinas(curso->arvore_disciplinas);
                } else {
                    printf("Curso não encontrado!\n");
                }
                break;
            case 7:
                exibir_disciplinas_por_periodo(arvore_cursos);
                break;
            case 8:
                exibir_disciplinas_aluno(lista_alunos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}