#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int nascimento[3];
    int ativo_AL;

}Pessoa;
Pessoa lista_alunos[TAM_ALUNOS];
//funções

void pegardata(Pessoa lista_alunos[], int cadastro, char nascimento[][5]){
    printf("Dia:\n-->");
    fgets(nascimento[0], 5, stdin);//pegar dia
    nascimento[strcspn(nascimento[0], "\n") == '\0'];//remover quebra de linha(\n) 
    printf("Mês\n-->");
    fgets(nascimento[1], 5, stdin);//pegar mês
    nascimento[1][strcspn(nascimento[1], "\n") == '\0'];//remover quebra de linha(\n)
    printf("Ano:\n-->");
    fgets(nascimento[2], 5, stdin);// pegar ano
    nascimento[2][strcspn(nascimento[2], "\n") == '\0'];//remover quebra de linha(\n)
    lista_alunos[cadastro].nascimento[0] = atoi(nascimento[0]);
    lista_alunos[cadastro].nascimento[1] = atoi(nascimento[1]);
    lista_alunos[cadastro].nascimento[2] = atoi(nascimento[2]);
}

int validardata(int Dia, int Mes, int Ano){

    int datavalida = 1;
    int Bissexto = 0;

    if(Dia < 1 || Dia > 31)
        datavalida = 0;
    
    if((Mes < 1 || Mes > 12) && datavalida == 1)
        datavalida = 0;
    
    if ((Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) && Dia > 30  && datavalida == 1)
        datavalida = 0;
    
    if(Ano >= 0 && Ano <=26)
        Ano += 2000;
    else 
        if(Ano > 26)
            Ano += 1900;
        else    
            datavalida = 0;

    if(Mes == 2){
        if ((Ano % 4 == 0 && Ano % 100 != 0) || (Ano % 400 == 0)) 
            Bissexto = 1;
        if(Bissexto == 1){
            if(Dia > 29){
                datavalida = 0;
            }
        }else{
            if(Dia > 28)
                datavalida = 0;
        }
        
    }
    if (datavalida)
        return 1;
    else
        return 0;

}
int main(){
    char nascimento[3][5];
    int cadastro = 0;
    pegardata(lista_alunos, cadastro, nascimento);

    printf("Dia: %d\nMes: %d\nAno: %d\n", lista_alunos[cadastro].nascimento[0], lista_alunos[cadastro].nascimento[1], lista_alunos[cadastro].nascimento[2]);

    if(validardata(lista_alunos[cadastro].nascimento[0], lista_alunos[cadastro].nascimento[1], lista_alunos[cadastro].nascimento[2]) == 1)
        printf("Data Válida\n");
    else
        printf("Data Inválida\n");
}