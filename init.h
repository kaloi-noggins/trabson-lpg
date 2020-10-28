#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//para o sleep
#include <unistd.h>

#define size 6

typedef struct
{
    char rua[100];
    int numero;
    char complemento[100];
    char bairro[100];
    int cep;
    char cidade[100];
    char estado[100];
    char pais[100];
} Endereco;

typedef struct
{
    int cod_pais;
    int ddd;
    int numero;
} Telefone;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[100];
    char sobrenome[100];
    char email[100];
    Telefone telefone;
    Endereco endereco;
    Data data;
    char obs[100];
} Contato;

/*
Status:
    getFile - implementado
    setFile - implementado
    menu - implementado
    insereContato - implementado
    buscaPorAniversario - implementado
    buscaPorPrimeiroNome - implementado
    removeContato -  implementado
    organizaAgenda - implementado
    mostraContato - implementado
    pauseExec - implementado
*/

//operações com arquivos

/*
Lẽ o arquivo do disco e o carrega na memória.
Se o arquivo não existir, cria o arquivo
*/
void getFile(Contato *agenda, int *nCon);

/*
Salva o arquivo no disco depois que todas as operações
tiverem sido executadas
*/
void setFile(Contato *agenda, int *nCon);

//operações na memoria

//Printa o menu principal
void menu(int *opt);

/*
Lê os dados de um novo contato e o insere na agenda telefônica.
Logo após, chama a função organizaAgenda para organizar os contato
em ordem alfabética
*/
void insereContato(Contato *agenda, int *nCon);

/*
Busca pelo primeiro nome do contato na agenda
e printa os todos os dados de todasa as correspondências
*/
void buscaPorPrimeiroNome(Contato *agenda, int *nCon);

/*
Busca pela data de aniversário.
Se o parâmetro dia for -1, busca somente por mês.
Printa todas os dados de todas as correspondências
*/
void buscaPorAniversario(Contato *agenda, int comMes, int *nCon);

/*
Recebe o nome e sobrenome do contato a ser removido e
deleta TODAS as ocorrências desse nome e sobrenome.
Logo após, chama a função organizaAgenda para organizar os contato
em ordem alfabética
*/
void removeContato(Contato *agenda, int *nCon);

//Organiza a agenda em ordem alfabética
void organizaAgenda(Contato *agenda, int *nCon);

/*
Mostra os dados dos conatatos.
Se opt for 1, printa somente nome, sobrenome, telefone e email.
Se opt for 2, printa todos os dados
*/
void mostrarContatos(Contato *agenda, int opt, int nCon);

//le um buffer de texto qualquer pra trancar a execução do programa
//até o maluco terminar de ler as informações
void pauseExec();

//Define um contato padrão com todos os dados vazios
Contato contatoVazio();
