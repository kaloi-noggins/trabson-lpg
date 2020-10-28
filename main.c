#include "init.h"
#include "functions.c"

int main()
{
  system("clear");

  //o nCon diz qual a última posição do vetor de agenda
  int nCon = 0;

  //declaração de variáveis auxiliares
  int d, m;
  char n[100], s[100];

  //opção do menu
  int opt;
  //declaração da agenda de tamanho size, defindo em init.h
  Contato agenda[size];

  //leitura do arquivo contendo a agenda telefônica
  getFile(agenda, &nCon);

  do
  {
    menu(&opt);
    switch (opt)
    {
    case 1:
      //Insere contatos
      insereContato(agenda, &nCon);
      break;
    case 2:
      //Remove contatos
      removeContato(agenda, &nCon);
      break;
    case 3:
      system("clear");
      //Mostra resumo
      mostrarContatos(agenda, 1, nCon);
      pauseExec();
      break;
    case 4:
      system("clear");
      //Mostra todos os dados
      mostrarContatos(agenda, 2, nCon);
      pauseExec();
      break;
    case 5:
      buscaPorPrimeiroNome(agenda, &nCon);
      pauseExec();
      break;
    case 6:
      //Pesquisa por dia e chama a função de mostrar contato
      buscaPorAniversario(agenda, 0, &nCon);
      pauseExec();
      break;
    case 7:
      //Pesquisa por dia e mes e chama a função de mostrar contato
      buscaPorAniversario(agenda, 1, &nCon);
      pauseExec();
      break;
    case 8:
      setFile(agenda, &nCon);
      break;
    default:
      system("clear");
      printf("Opção inválida\n");
      sleep(2);
      break;
    }
    system("clear");
  } while (opt != 8);
  return 0;
}
