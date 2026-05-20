#include <stdio.h>
#include <string.h>
#define TAM_ALUNOS 3
#define TAM_PROFESSORES 3
#define TAM_MATRICULA 12
#define TAM_NOME 255
#define TAM_CPF 13

typedef struct pessoa{
    char matricula_[TAM_MATRICULA];
    char sexo;
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    char nascimento[3][5];
    int ativo_AL;

}Pessoa;
Pessoa lista_alunos[TAM_ALUNOS];
int cadastro = 0;

int main(){
    printf("Dia:\n-->");
    fgets(lista_alunos[cadastro].nascimento[0], 5, stdin);
    lista_alunos[cadastro].nascimento[strcspn(lista_alunos[cadastro].nascimento[0], "\n") == '\0']; 
    printf("Mês\n-->");
    fgets(lista_alunos[cadastro].nascimento[1], 5, stdin);
    lista_alunos[cadastro].nascimento[1][strcspn(lista_alunos[cadastro].nascimento[1], "\n") == '\0'];
    printf("Ano:\n-->");
    fgets(lista_alunos[cadastro].nascimento[2], 5, stdin);
    lista_alunos[cadastro].nascimento[2][strcspn(lista_alunos[cadastro].nascimento[2], "\n") == '\0'];
    printf("Dia: %s\nMes: %s\nAno: %s", lista_alunos[cadastro].nascimento[0], lista_alunos[cadastro].nascimento[1], lista_alunos[cadastro].nascimento[2]);
}