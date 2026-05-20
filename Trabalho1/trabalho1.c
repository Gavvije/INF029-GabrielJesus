// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gabriell Vinícius Vasconcelos de Jesus
//  email: 20252160018@edu.ifba.br
//  Matrícula: 20252160018
//  Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

//Função pra separar data
void separardata(char data[], char Dia[], char Mes[], char Ano[]){

    int contador1 = 0;
    int contador2 = 0;
    
    while(data[contador1] != '/'){
            Dia[contador2++] = data[contador1++];
    }
    Dia[contador2] = '\0';
    contador1++; //pula a "/"
    contador2 = 0;

    while(data[contador1] != '/'){
        Mes[contador2++] = data[contador1++];
    }
    Mes[contador2] = '\0';
    contador1++; //pula a "/"
    contador2 = 0;

    while(data[contador1] != '\0'){
        Ano[contador2++] = data[contador1++];
    }
    Ano[contador2] = '\0';
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
    
    int datavalida = 1;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int Dia;
    int Mes;
    int Ano;
    int Bissexto = 0;
    

    //quebrar a string data em strings sDia, sMes, sAno
    separardata(data, sDia, sMes, sAno);
    //printf("%s\n", data);

    Dia = atoi(sDia);
    Mes = atoi(sMes);
    Ano = atoi(sAno);

    
    if(Dia < 1 || Dia > 31)
        datavalida = 0;
    
    if((Mes < 1 || Mes > 12) && datavalida == 1)
        datavalida = 0;
    
    if ((Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) && Dia > 30  && datavalida == 1)
        datavalida = 0;
    
    if(Mes == 2){
        if ((Ano % 4 == 0 && Ano % 100 != 0) || (Ano % 400 == 0)) {
            Bissexto = 1;
        if(Bissexto == 1)
            if(Dia > 29)
                datavalida = 0;
        else
            if(Dia > 28)
                datavalida = 0;
        }
    }

    if(Ano >= 0 && Ano <=26)
        Ano += 2000;
    else 
        if(Ano > 26)
            Ano += 1900;
        else    
            datavalida = 0;

    if (datavalida)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){
    
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    
    char sDiaI[3];
    char sMesI[3];
    char sAnoI[5];
    char sDiaF[3];
    char sMesF[3];
    char sAnoF[5];
    int DiaI;
    int MesI;
    int AnoI;
    int DiaF;
    int MesF;
    int AnoF;
    char datainvertidaI[10];
    char datainvertidaF[10];
    int contador1 = 0;
    int contador2 = 0;
    int IntdatainvertidaI;
    int IntdatainvertidaF;

    separardata(datainicial, sDiaI, sMesI, sAnoI);
    separardata(datafinal, sDiaF, sMesF, sAnoF);

    //Junta a data inicial invertida
    while(sAnoI[contador2] != '\0') {
        datainvertidaI[contador1++] = sAnoI[contador2++];
    }
    contador2 = 0;

    while(sMesI[contador2] != '\0') {
        datainvertidaI[contador1++] = sMesI[contador2++];
    }
    contador2 = 0;

    while(sDiaI[contador2] != '\0') {
        datainvertidaI[contador1++] = sDiaI[contador2++];
    }
    datainvertidaI[contador1] = '\0';
    contador1 = 0;
    contador2 = 0;

    //Junta a data final invertida
    while(sAnoF[contador2] != '\0') {
        datainvertidaF[contador1++] = sAnoF[contador2++];
    }
    contador2 = 0;

    while(sMesF[contador2] != '\0') {
        datainvertidaF[contador1++] = sMesF[contador2++];
    }
    contador2 = 0;

    while(sDiaF[contador2] != '\0') {
        datainvertidaF[contador1++] = sDiaF[contador2++];
    }
    datainvertidaF[contador1] = '\0';

    IntdatainvertidaI  = atoi(datainvertidaI);
    IntdatainvertidaF = atoi(datainvertidaF);
    if (q1(datainicial) == 0){
       dma.retorno = 2;
       return dma;
    }else if (q1(datafinal) == 0){
       dma.retorno = 3;
       return dma;
    }else if(IntdatainvertidaF < IntdatainvertidaI){
        //verifique se a data final não é menor que a data inicial
        dma.retorno = 4;
        return dma;
    }else{  
        //calcule a distancia entre as datas
        DiaI = atoi(sDiaI);
        MesI = atoi(sMesI);
        AnoI = atoi(sAnoI);
        DiaF = atoi(sDiaF);
        MesF = atoi(sMesF);
        AnoF = atoi(sAnoF);
    
        dma.qtdAnos = AnoF - AnoI;
        dma.qtdMeses = MesF - MesI;
        dma.qtdDias = DiaF - DiaI;
        if(dma.qtdDias < 0){
            dma.qtdDias += 30;
            dma.qtdMeses--;
        }
        if(dma.qtdMeses < 0){
            dma.qtdMeses += 12;
            dma.qtdAnos--;
        }
        //se tudo der certo
      dma.retorno = 1;
      return dma;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;
    qtdOcorrencias++;
    if(isCaseSensitive == 1){
        for(int contador = 0; texto[contador] != '\0'; contador++)
            if(texto[contador] == c)
                qtdOcorrencias++;
    }else{
        for(int contador = 0; texto[contador] != '\0'; contador++){
            if(texto[contador] >= 'A' && texto[contador] <= 'Z')
                texto[contador] = texto[contador] - 'A' + 'a';
                c = c - 'A' + 'a';
        }
        for(int contador = 0; texto[contador] != '\0'; contador++)
            if(texto[contador] == c)
                qtdOcorrencias++;
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){

    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int qtdOcorrencias = -1;
    qtdOcorrencias = 0;

    for(contador1 = 0; strTexto[contador1] != '\0'; contador1++){
        if(strTexto[contador1] == strBusca[0]){
            for(contador2 = 0; strBusca[contador2] != '\0' && strTexto[contador1 + contador2] == strBusca[contador2]; contador2++);
            if(strBusca[contador2] == '\0'){
                posicoes[contador3++] = contador1 + 1;
                posicoes[contador3++] = contador1 + contador2;
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

    int numinvertido = 0;
    while(num > 0){
        numinvertido *= 10;
        numinvertido = numinvertido + num % 10;
        num /= 10;
    }
    num = numinvertido;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){

    int contador;
    int numbusca = numerobusca;
    int tamnumbusca = 0;
    int divisor = 1;
    int tempnum;
    int qtdOcorrencias = 0;

    if(numerobusca == 0){
        tamnumbusca = 1;
        divisor = 10;
    }else{
        while(numbusca > 0){
            numbusca /= 10;
            tamnumbusca++;
        }
        contador = tamnumbusca;
        while(contador > 0){
            divisor *= 10;
            contador--;
        }
    }
    while(numerobase > 0){
        tempnum = numerobase % divisor;
        numerobase /= 10;
        if(numerobusca == tempnum){
            qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */


int q7(char matriz[8][10], char palavra[5]){
    int linha;
    int coluna;
    int contador;
    int direcaoLinha;
    int direcaoColuna;
    int novaLinha;
    int novaColuna;
    int achou;

    for(linha = 0; linha < 8; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            for(direcaoLinha = -1; direcaoLinha <= 1; direcaoLinha++){
                for(direcaoColuna = -1; direcaoColuna <= 1; direcaoColuna++){
                    if(direcaoLinha == 0 && direcaoColuna == 0)
                        continue;
                    achou = 1;
                    for(contador = 0; palavra[contador] != '\0'; contador++){
                        novaLinha = linha + direcaoLinha * contador;
                        novaColuna = coluna + direcaoColuna * contador;
                        if(novaLinha < 0 || novaLinha >= 8 ||
                           novaColuna < 0 || novaColuna >= 10 ||
                           matriz[novaLinha][novaColuna] != palavra[contador]){
                            achou = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return achou;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
