void getFile(Contato *agenda, int *nCon)
{
    FILE *file = fopen("arquivoAgenda", "rb+");
    if (file == NULL)
    {
        printf("Arquivo de agenda não encontrado. Criando nova agenda...\n");
        file = fopen("arquivoAgenda", "wb+");
         for (int i = 0; i < size; i++) {
          agenda[i] = contatoVazio();
        }
    }
    else
    {
        printf("Carregando agenda...\n");
        fread(nCon, sizeof(int), 1, file);
        fread(agenda, sizeof(Contato), *nCon, file);
        printf("Agenda carregada.\nNúmero de contatos: %d\n", *nCon);
    }
    fclose(file);
    sleep(2);
    system("clear");
}

void setFile(Contato *agenda, int *nCon)
{
    system("clear");
    FILE *file = fopen("arquivoAgenda", "wb+");
    if (file == NULL)
    {
        printf("Erro ao acessar arquivo de agenda\n");
    }
    else
    {
        printf("Salvando alterações...");
        fwrite(nCon, sizeof(int), 1, file);
        fwrite(agenda, sizeof(Contato), *nCon, file);
        printf("Agenda salva.\nNúmero de contatos: %d\n", *nCon);
    }
    fclose(file);
    sleep(1.5);
}

void menu(int *opt)
{
    printf("::::::::::::::::::Agenda de contatos::::::::::::::::::\n");
    printf("1 - Inserir contato\n");
    printf("2 - Remover contato\n");
    printf("3 - Mostrar nome, telefone e email de todos os contatos\n");
    printf("4 - Mostrar todos os dados de todos os contatos\n");
    printf("5 - Buscar contato por primeiro nome\n");
    printf("6 - Buscar contato por dia do aniversário\n");
    printf("7 - Buscar contato por dia e mês do aniversário\n");
    printf("8 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}

void insereContato(Contato *agenda, int *nCon)
{
    system("clear");
    if (*nCon + 1 < size)
    {
        printf("::::::Dados básicos::::::\n");
        printf("Nome: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].nome, 100, stdin);

        printf("Sobrenome: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].sobrenome, 100, stdin);

        printf("Email: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].email, 100, stdin);

        printf("::::::::Telefone::::::::\n");
        printf("Código internacional: ");
        scanf("%d", &agenda[*nCon].telefone.cod_pais);

        printf("DDD: ");
        scanf("%d", &agenda[*nCon].telefone.ddd);

        printf("Telefone: ");
        scanf("%d", &agenda[*nCon].telefone.numero);

        printf("::::::::Endereco:::::::\n");
        printf("Rua: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.rua, 100, stdin);

        printf("Numero: ");
        scanf("%d", &agenda[*nCon].endereco.numero);

        printf("Complemento: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.complemento, 100, stdin);

        printf("Bairro: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.bairro, 100, stdin);

        printf("CEP: ");
        scanf("%d", &agenda[*nCon].endereco.cep);

        printf("Cidade: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.cidade, 100, stdin);

        printf("Estado: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.estado, 100, stdin);

        printf("Pais: ");
        __fpurge(stdin);
        fgets(agenda[*nCon].endereco.pais, 100, stdin);

        printf(":::::::Data de nascimento:::::::\n");
        printf("Dia: ");
        scanf("%d", &agenda[*nCon].data.dia);

        printf("Mes: ");
        scanf("%d", &agenda[*nCon].data.mes);

        printf("Ano: ");
        scanf("%d", &agenda[*nCon].data.ano);

        printf("::::::Observações::::::\n");
        __fpurge(stdin);
        fgets(agenda[*nCon].obs, 100, stdin);

        system("clear");
        printf("Contato Registrado!\n");

        *nCon = *nCon + 1;

        char resp[2];
        organizaAgenda(agenda, nCon);
        while (1)
        {
            printf("Deseja regitrar um novo contato?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            __fpurge(stdin);
            fgets(resp, 2, stdin);
            if ((strcmp(resp, "1\0") == 0) || (strcmp(resp, "2\0") == 0))
                break;
        }

        if (strcmp(resp, "1\0") == 0)
        {
            insereContato(agenda, nCon);
        }
    }
    else
    {
        printf("A agenda está lotada!\nExclua contatos!\n");
        removeContato(agenda, nCon);
        sleep(3);
    }
}

void removeContato(Contato *agenda, int *nCon)
{
  system("clear");
  char nome[100], sobrenome[100];
  printf("Entre com o nome do contato a ser removido: \n");
  __fpurge(stdin);
  fgets(nome, sizeof(nome), stdin);
  printf("Sobrenome:\n");
  __fpurge(stdin);
  fgets(sobrenome, sizeof(sobrenome), stdin);
  int i = 0;
  while (i < *nCon)
  {
    if (strcmp(agenda[i].nome, nome)==0 && strcmp(agenda[i].sobrenome, sobrenome) == 0) {
      agenda[i] = agenda[*nCon-1];
      agenda[*nCon-1] = contatoVazio();
      *nCon = *nCon - 1;
      organizaAgenda(agenda, nCon);
      printf("Contato excluido!\n");
      sleep(1.5);
    }
    i++;
  }

}

void mostrarContatos(Contato *agenda, int opt, int nCon)
{
    if (nCon == 0)
    {
        printf("Nenhum contato encontrado...\n");
        sleep(3);
    }
    else
    {
        for (size_t i = 0; i < nCon; i++)
        {
            printf(":::Dados básicos do contato:::\n");
            printf("Nome: %s", agenda[i].nome);
            printf("Sobrenome: %s", agenda[i].sobrenome);
            printf("Email: %s", agenda[i].email);
            printf("Número: +%d (%d) %d\n",
                   agenda[i].telefone.cod_pais,
                   agenda[i].telefone.ddd,
                   agenda[i].telefone.numero);
            if (opt == 1)
            {
                printf("\n");
            }
            if (opt == 2)
            {
                printf("::::::::Endereço:::::::\n");
                printf("Rua: %s", agenda[i].endereco.rua);
                printf("Numero: %d\n", agenda[i].endereco.numero);
                printf("Bairro: %s", agenda[i].endereco.bairro);
                printf("CEP: %d\n", agenda[i].endereco.cep);
                printf("Cidade: %s", agenda[i].endereco.cidade);
                printf("Estado: %s", agenda[i].endereco.estado);
                printf("Pais: %s", agenda[i].endereco.pais);

                printf("::::::Nascimento::::::\n");
                printf("Data: %d/%d/%d\n",
                       agenda[i].data.dia,
                       agenda[i].data.mes,
                       agenda[i].data.ano);

                printf("::::::Observações::::::\n");
                printf("%s\n", agenda[i].obs);
            }
        }
    }
}

void pauseExec()
{
    printf("Aperte qualquer tecla para voltar ao menu...\n");
    char oof[10];
    __fpurge(stdin);
    fgets(oof, 10, stdin);
}

void buscaPorAniversario(Contato *agenda, int comMes, int *nCon)
{
    int dia, mes;
    if (comMes) {
      printf("Entre com o dia e mês do aniversário: ");
      scanf("%d", &dia);
      scanf("%d", &mes);
    } else {
      printf("Entre com o dia do aniversário: ");
      scanf("%d", &dia);
      mes = -1;
    }
    system("clear");
    int opt;
    char resp[2];
    while (1)
    {
        printf("Deseja mostrar todos os dados dos contatos encontrados?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        __fpurge(stdin);
        fgets(resp, 2, stdin);
        if (strcmp(resp, "1\0") == 0)
        {
            opt = 2;
            break;
        }
        else if (strcmp(resp, "2\0") == 0)
        {
            opt = 1;
            break;
        }
    }

    for (size_t i = 0; i < *nCon; i++)
    {
        if (mes == -1)
        {
            if (agenda[i].data.dia == dia)
            {
                mostrarContatos(&agenda[i], opt, 1);
            }
        }
        else
        {
            if (agenda[i].data.dia == dia && agenda[i].data.mes == mes)
            {
                mostrarContatos(&agenda[i], opt, 1);
            }
        }
    }
}

void buscaPorPrimeiroNome(Contato *agenda, int *nCon)
{
    system("clear");
    printf("Entre com o o primeiro nome do contato: ");
    int opt;
    char resp[2], nome[100];
    __fpurge(stdin);
    fgets(nome, sizeof(nome), stdin);
    while (1)
    {
        printf("Deseja mostrar todos os dados dos contatos encontrados?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        __fpurge(stdin);
        fgets(resp, 2, stdin);
        if (strcmp(resp, "1\0") == 0)
        {
            opt = 2;
            break;
        }
        else if (strcmp(resp, "2\0") == 0)
        {
            opt = 1;
            break;
        }
    }
    system("clear");
    for (size_t i = 0; i < *nCon; i++)
    {
        if (strcmp(nome, agenda[i].nome) == 0)
        {
          mostrarContatos(&agenda[i], opt, 1);
        }
    }
    pauseExec();
}

Contato contatoVazio() {
  Contato cttv;
  strcpy(cttv.nome, "\0");
  strcpy(cttv.sobrenome, "\0");
  strcpy(cttv.email, "\0");
  strcpy(cttv.obs, "\0");
  strcpy(cttv.endereco.rua, "\0");
  strcpy(cttv.endereco.complemento, "\0");
  strcpy(cttv.endereco.bairro, "\0");
  strcpy(cttv.endereco.cidade, "\0");
  strcpy(cttv.endereco.estado, "\0");
  strcpy(cttv.endereco.pais, "\0");
  cttv.telefone.cod_pais = 0;
  cttv.telefone.ddd = 0;
  cttv.telefone.numero = 0;
  cttv.data.dia = 0;
  cttv.data.mes = 0;
  cttv.data.ano = 0;

  return cttv;
}

// FUNCIONANDO MUITO BEM NOTA 0
void organizaAgenda(Contato *agenda, int *nCon) {

  Contato aux = contatoVazio();
  for(int i = 0; i < *nCon; ++i) {
      for(int j = i+1; j < *nCon ; ++j) {
          if(strcmp(agenda[i].nome,agenda[j].nome)>0){
                aux = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = aux;
          }
      }
  }
}
