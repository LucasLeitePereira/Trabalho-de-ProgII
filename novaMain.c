#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
  char nome[50];
  char sexo;
  int idade;
};

struct venda {
  struct cliente cli;
  int qntdItensVendidos;
  char unidade;
  float valorTotal;
};

typedef struct venda vd;

int compradoresM(vd *venda, int totalvendas);

void imprimirVendas(vd *vetor, int index, int qntd);

int quantidadeVenda(vd *vetor, int totalV);

int compradoresM(vd *venda, int totalvendas);

void procurarVendasAbaixoValor(vd *vetor, int totalVendas, float valor);

int vendasNaUnidadeB(vd *vetor, int totalVendas);

void procurarClienteMaiorNome(vd *vetor, int totalVendas);

void imprimriDadosVendaMaisNovo(vd *vetor, int totalVendas);

int qtdTotalItensVendidos(vd *vetor, int totalvendas);

float ValorTotalDasVendas(vd *vetor, int totalvendas);

float mediaTotalDaVenda(vd *vetor, int totalvendas);

void imprimirMenorCompraMulher(vd *vetor, int totalvendas);

float valorVendasPorN(vd *vetor, int totalvendas);

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  system("clear");

  int opcaoMenu;
  int numlistaDeVendas;
  int opcaoPesquisa;
  int opcaoMenuPesquisa;

  FILE *arq = NULL;
  vd *listaDeVendas = NULL;

  int tamanhoAtualVetor;

  char nomeProcura[50];
  int opcaoPesquisaNome;
  int qntVendasEncontradasPorNome;

  int TotalVendas;
  int TotalM;

  float valorBusca;

  int numVendasEncontradas;

  int totalM;
  int total;
  float totalV;
  float mediaTotal;

  float valorComprasPorN;
  int i;

  arq = fopen("loja.txt", "r");
  int numeroVendasCadastradas = 0;

  if (arq != NULL) {
    char linha[50];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
      numeroVendasCadastradas++;
    }

    numeroVendasCadastradas = numeroVendasCadastradas / 6;

    fclose(arq);

    listaDeVendas = (vd *)malloc(numeroVendasCadastradas * sizeof(vd));
    if (listaDeVendas == NULL) {
      return 1;
    }

    arq = fopen("loja.txt", "r");
    for (i = 0; i < numeroVendasCadastradas; i++) {
      fscanf(arq, " %49[^\n] %c %d %d %c %f", listaDeVendas[i].cli.nome,
             &listaDeVendas[i].cli.sexo, &listaDeVendas[i].cli.idade,
             &listaDeVendas[i].qntdItensVendidos, &listaDeVendas[i].unidade,
             &listaDeVendas[i].valorTotal);
    }
    fclose(arq);
  }

  int quantidadeDeVendas = numeroVendasCadastradas;
  
  do {
    system("clear");

    printf("1. Cadastrar Venda\n2. Pesquisar por venda pelo nome\n3. Consultar "
           "Informacoes\n4. Encerrar progama\n");
    printf("Opcao: ");

    scanf("%i", &opcaoMenu);
    getchar();

    system("clear");

    switch (opcaoMenu) {
    case 1:
      do {
        printf("Quantas vendas serão cadastradas?: ");
        scanf(" %i", &numlistaDeVendas);
        if (numlistaDeVendas <= 0) {
          printf("Numero invalido, tente novamente!\n\n");
        }
      } while (numlistaDeVendas <= 0);

      system("clear");

      vd *vetorTemporario = realloc(listaDeVendas, (numlistaDeVendas + numeroVendasCadastradas) *sizeof(vd));
      
      if (vetorTemporario == NULL) {
        printf("Erro: Memoria Insuficiente\n");
        system("pause");
        exit(1);
      }

      listaDeVendas = vetorTemporario;
      
      for (i = 0; i < numlistaDeVendas; i++) {
        int index = 
        getchar();
        do {
          printf("Nome do cliente: ");
          fgets(listaDeVendas[numeroVendasCadastradas + i].cli.nome, sizeof(listaDeVendas[numeroVendasCadastradas + i].cli.nome),
                stdin);
          listaDeVendas[numeroVendasCadastradas + i]
              .cli.nome[strcspn(listaDeVendas[numeroVendasCadastradas + i].cli.nome, "\n")] = '\0';

          system("clear");

          if (strlen(listaDeVendas[numeroVendasCadastradas + i].cli.nome) <= 3) {
            printf("Nome inválido! preencha um nome com mais de 3 letras\n");
            printf("Tente novamente\n\n");
          }
        } while (strlen(listaDeVendas[numeroVendasCadastradas + i].cli.nome) <= 3);

        do {
          printf("Sexo (m | f | n): ");
          scanf(" %c", &listaDeVendas[numeroVendasCadastradas + i].cli.sexo);

          system("clear");

          if (listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'm' &&
              listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'f' &&
              listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'n') {
            printf(
                "Opcao invalida! preencha com uma dass opções disponivéis\n");
            printf("Tente novamente\n\n");
          }
        } while (listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'm' &&
                 listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'f' &&
                 listaDeVendas[numeroVendasCadastradas + i].cli.sexo != 'n');

        do {
          printf("Idade: ");
          scanf(" %i", &listaDeVendas[numeroVendasCadastradas + i].cli.idade);

          system("clear");

          if (listaDeVendas[numeroVendasCadastradas + i].cli.idade <= 0) {
            printf("Idade invalida! Preencha um idade maior que 0\n");
            printf("Tente novamente\n\n");
          }
        } while (listaDeVendas[numeroVendasCadastradas + i].cli.idade <= 0);

        do {
          printf("Quntidade de Itens Vendidos: ");
          scanf(" %i", &listaDeVendas[numeroVendasCadastradas + i].qntdItensVendidos);

          system("clear");

          if (listaDeVendas[numeroVendasCadastradas + i].qntdItensVendidos <= 0) {
            printf("Número de itens inválido! Não é possível cadastrar números "
                   "menores ou igual a 0\n");
            printf("Tente novamente\n\n");
          }
        } while (listaDeVendas[numeroVendasCadastradas + i].qntdItensVendidos <= 0);

        do {
          printf("Unidade (a | b | c): ");
          scanf(" %c", &listaDeVendas[numeroVendasCadastradas + i].unidade);

          system("clear");

          if (listaDeVendas[numeroVendasCadastradas + i].unidade != 'a' &&
              listaDeVendas[numeroVendasCadastradas + i].unidade != 'b' &&
              listaDeVendas[numeroVendasCadastradas + i].unidade != 'c') {
            printf(
                "Opcao invalida! preencha com uma dass opções disponivéis\n");
            printf("Tente novamente\n\n");
          }
        } while (listaDeVendas[numeroVendasCadastradas + i].unidade != 'a' &&
                 listaDeVendas[numeroVendasCadastradas + i].unidade != 'b' &&
                 listaDeVendas[numeroVendasCadastradas + i].unidade != 'c');

        do {
          printf("Valor total da venda: ");
          scanf(" %f", &listaDeVendas[numeroVendasCadastradas + i].valorTotal);

          system("clear");

          if (listaDeVendas[numeroVendasCadastradas + i].valorTotal <= 0) {
            printf("Valor inválido, não é possível cadastar números menores ou "
                   "igual a 0\n");
            printf("Tente novamente\n\n");
          }
        } while (listaDeVendas[numeroVendasCadastradas + i].valorTotal <= 0);

        system("clear");
      }

      arq = fopen("loja.txt", "a");
      if (arq == NULL) {
        printf("Erro ao tentar abrir o arquivo 'loja.txt'\n");
        free(listaDeVendas);
        return 1;
      }

      for (i = 0; i < numlistaDeVendas; i++) {
        system("clear");
        fprintf(arq, "%s\n%c\n%i\n%i\n%c\n%.2f\n", listaDeVendas[numeroVendasCadastradas + i].cli.nome,
                listaDeVendas[numeroVendasCadastradas + i].cli.sexo, listaDeVendas[numeroVendasCadastradas + i].cli.idade,
                listaDeVendas[numeroVendasCadastradas + i].qntdItensVendidos, listaDeVendas[numeroVendasCadastradas + i].unidade,
                listaDeVendas[numeroVendasCadastradas + i].valorTotal);
        printf("Dados gravados com sucesso!\n\n");
      }

      fclose(arq);

      numeroVendasCadastradas += numlistaDeVendas;
      quantidadeDeVendas = numeroVendasCadastradas;
      break;

    case 2:
      if (numeroVendasCadastradas == 0) {
        printf("Arquivo não encontrado! Cadastre pelo menos uma venda para poder realizar uma ação de busca.\n\n");
      }
      do {
        qntVendasEncontradasPorNome = 0;
        printf("Procuras pelas vendas realizadas para o(a): ");
        fgets(nomeProcura, sizeof(nomeProcura), stdin);
        nomeProcura[strcspn(nomeProcura, "\n")] = '\0';

        for (i = 0; i < quantidadeDeVendas; i++) {
          if (strcmp(nomeProcura, listaDeVendas[i].cli.nome) == 0) {
            qntVendasEncontradasPorNome++;
            printf("\nVenda[%i]\n", qntVendasEncontradasPorNome);
            printf("Quantidade de itens: %i\n",
                   listaDeVendas[i].qntdItensVendidos);
            printf("Unidade: %c\n", listaDeVendas[i].unidade);
            printf("Valor total da venda: %.2f\n\n",
                   listaDeVendas[i].valorTotal);
          }
        }

        if (qntVendasEncontradasPorNome == 0) {
          printf("Nenhuma venda foi encontrada no nome do(a): %s\n",
                 nomeProcura);
        }

        printf("1. Pesquisar novamente\n2. Voltar para o menu\nOpcao: ");
        scanf("%i", &opcaoPesquisaNome);
        getchar();
        system("clear");
      } while (opcaoPesquisaNome == 1);
      break;

    case 3:
      arq = fopen("loja.txt", "r");
      if (arq == NULL) {
        printf("Erro: arquivo não encontrado!\n");
        return 1;
      }

      tamanhoAtualVetor = 1;
      quantidadeDeVendas = 0;

      listaDeVendas = (vd *)malloc(tamanhoAtualVetor * sizeof(vd));
      if (listaDeVendas == NULL) {
        printf("Erro: Memoria Insuficiente\n");
        system("pause");
        exit(1);
      }

      i = 0;
      while (fscanf(arq, " %49[^\n] %c %d %d %c %f", listaDeVendas[i].cli.nome,
                    &listaDeVendas[i].cli.sexo, &listaDeVendas[i].cli.idade,
                    &listaDeVendas[i].qntdItensVendidos,
                    &listaDeVendas[i].unidade,
                    &listaDeVendas[i].valorTotal) == 6) {
        quantidadeDeVendas++;
        if (quantidadeDeVendas == tamanhoAtualVetor) {
          tamanhoAtualVetor++;
          listaDeVendas =
              realloc(listaDeVendas, tamanhoAtualVetor * sizeof(vd));
          if (listaDeVendas == NULL) {
            printf("Erro: Memoria insuficiente!");
            system("pause");
            return 2;
          }
        }
        i++;
      }
      fclose(arq);

      do {
        do {
          printf("Selecione uma das opcoes de pesquisa\n\n");
          printf("| 1. Vendas abaixo de um valor\n| 2. Vendas com 3 itens "
                 "vendidos\n| 3. Vendas realizadas na unidade 'B'\n");
          printf("| 4. Quantidade de compradores homens\n| 5. Valor total "
                 "comprado por compradores nao identificados\n| 6. Quantidade "
                 "total de itens vendidos\n");
          printf("| 7. Valor total das vendas\n| 8. Valor medio de uma "
                 "venda\n| 9. Compra mais barata feito por uma mulher\n");
          printf("| 10. Dados da venda do cliente com o maior nome\n| 11. "
                 "Dados da venda do cliente mais novo\n\n");

          printf("Opcao: ");
          scanf("%i", &opcaoMenuPesquisa);

          system("clear");

          switch (opcaoMenuPesquisa) {
          case 1:
            printf("Informe o valor: ");
            scanf(" %f", &valorBusca);
            system("clear");
            getchar();
            procurarVendasAbaixoValor(listaDeVendas, quantidadeDeVendas,
                                      valorBusca);
            break;

          case 2:
            TotalVendas = 0;
            TotalVendas = quantidadeVenda(listaDeVendas, quantidadeDeVendas);
            printf("A quantidade de venda que teve exatamente 3 itens vendido "
                   "sao: %d!\n\n",
                   TotalVendas);
            break;

          case 3:
            numVendasEncontradas =
                vendasNaUnidadeB(listaDeVendas, quantidadeDeVendas);
            printf("Quntidade de vendas na unidade B: %i\n\n",
                   numVendasEncontradas);
            break;

          case 4:
            totalM = compradoresM(listaDeVendas, quantidadeDeVendas);
            printf("Total de Homens compradores e: %d!\n", totalM);
            break;

          case 5:
            valorComprasPorN =
                valorVendasPorN(listaDeVendas, quantidadeDeVendas);
            printf("Valor total das compras realizadas por clientes não "
                   "identificados: R$%.2f\n",
                   valorComprasPorN);
            break;

          case 6:
            total = qtdTotalItensVendidos(listaDeVendas, quantidadeDeVendas);
            printf("O total dde intens vendido e %d\n", total);
            break;

          case 7:
            totalV = ValorTotalDasVendas(listaDeVendas, quantidadeDeVendas);
            printf("O valor total das vendas: R$%.2f\n", totalV);
            break;

          case 8:
            mediaTotal = mediaTotalDaVenda(listaDeVendas, quantidadeDeVendas);
            printf("O valor media das comrpas: R$%.2f\n", mediaTotal);
            break;

          case 9:
            imprimirMenorCompraMulher(listaDeVendas, quantidadeDeVendas);
            break;

          case 10:
            procurarClienteMaiorNome(listaDeVendas, quantidadeDeVendas);
            break;

          case 11:
            imprimriDadosVendaMaisNovo(listaDeVendas, quantidadeDeVendas);
            break;

          default:
            printf("Opcao invalida! Tente novamente\n\n");
          }
        } while (opcaoMenuPesquisa < 0 && opcaoMenuPesquisa > 12);

        printf("1. Pesquisar novamente | 2. Encerrar programa\n\n");
        printf("Opcao: ");

        scanf("%i", &opcaoPesquisa);

        system("clear");

        if (opcaoPesquisa == 2) {
          free(listaDeVendas);
          printf("Encerrando programa...");
          return 0;
        }
      } while (opcaoPesquisa == 1);
      break;

    case 4:
      if (listaDeVendas != NULL) {
        free(listaDeVendas);
      }
      printf("Encerrando o programa...");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n\n");
    }
  } while (opcaoMenu != 4);

  return 0;
}

int quantidadeVenda(vd *vetor, int totalV) // Função 2
{
  int totalQ = 0;

  int i;
  for (i = 0; i < totalV; i++) {
    if (vetor[i].qntdItensVendidos == 3) {
      totalQ++;
    }
  }
  return totalQ;
}

int compradoresM(vd *venda, int totalvendas) { // Função 4
  int total = 0;
  int i = 0;
  for (i = 0; i < totalvendas; i++) {
    if (venda[i].cli.sexo == 'm') {
      total++;
    }
  }
  return total;
}

void procurarVendasAbaixoValor(vd *vetor, int totalVendas, float valor) {
  int i;
  int qntVendasEncontradas = 0;
  for (i = 0; i < totalVendas; i++) {
    if (vetor[i].valorTotal < valor) {
      qntVendasEncontradas++;
      imprimirVendas(vetor, i, qntVendasEncontradas);
    }
  }
  if (qntVendasEncontradas == 0) {
    printf("Nenhuma venda abaixo de R$%.2f\n\n", valor);
  }
}

int vendasNaUnidadeB(vd *vetor, int totalVendas) {
  int qntdVendasUniB = 0;

  int i;
  for (i = 0; i < totalVendas; i++) {
    if (vetor[i].unidade == 'b') {
      qntdVendasUniB++;
    }
  }

  return qntdVendasUniB;
}

void imprimriDadosVendaMaisNovo(vd *vetor, int totalVendas) {
  int idadeMaisNovo = 0;
  int i;
  for (i = 0; i < totalVendas; i++) {
    if (idadeMaisNovo == 0 || idadeMaisNovo > vetor[i].cli.idade) {
      idadeMaisNovo = vetor[i].cli.idade;
    }
  }

  int qntdVendasEncontradas = 0;
  for (i = 0; i < totalVendas; i++) {
    if (idadeMaisNovo == vetor[i].cli.idade) {
      qntdVendasEncontradas++;
      imprimirVendas(vetor, i, qntdVendasEncontradas);
    }
  }
}

void procurarClienteMaiorNome(vd *vetor, int totalVendas) {
  int *ListaIndexMaiorNome = (int *)malloc(sizeof(int));

  int tamMaiorNome = 0;

  int i;
  int tamLista = 0;

  for (i = 0; i < totalVendas; i++) {
    if (strlen(vetor[i].cli.nome) > tamMaiorNome) {
      tamMaiorNome = strlen(vetor[i].cli.nome);
    }
  }

  for (i = 0; i < totalVendas; i++) {

    if (strlen(vetor[i].cli.nome) == tamMaiorNome) {
      ListaIndexMaiorNome[tamLista] = i;
      tamLista++;
      ListaIndexMaiorNome =
          realloc(ListaIndexMaiorNome, (tamLista + 1) * sizeof(int));
    }
  }

  for (i = 0; i < tamLista; i++) {
    imprimirVendas(vetor, ListaIndexMaiorNome[i], i + 1);
  }

  free(ListaIndexMaiorNome);
}

void imprimirVendas(vd *vetor, int index, int qntd) {
  printf("Venda [%i]\n\n", qntd);
  printf("Nome: %s\n", vetor[index].cli.nome);
  printf("Sexo: %c\n", vetor[index].cli.sexo);
  printf("Idade: %i\n", vetor[index].cli.idade);
  printf("Quantidade de vendas: %i\n", vetor[index].qntdItensVendidos);
  printf("Unidade: %c\n", vetor[index].unidade);
  printf("Valor total: %.2f\n\n", vetor[index].valorTotal);
}

int qtdTotalItensVendidos(vd *vetor, int totalvendas) {
  int i = 0;
  int total = 0;
  for (i = 0; i < totalvendas; i++) {
    total += vetor[i].qntdItensVendidos;
  }
  return total;
}

float ValorTotalDasVendas(vd *vetor, int totalvendas) {
  int i = 0;
  float totalV = 0;
  for (i = 0; i < totalvendas; i++) {
    totalV += vetor[i].valorTotal;
  }
  return totalV;
}

float mediaTotalDaVenda(vd *vetor, int totalvendas) {
  int i = 0;
  float soma = 0;
  int qtd = 0;
  float media;
  for (i = 0; i < totalvendas; i++) {
    soma += vetor[i].valorTotal;
    qtd++;
  }
  media = soma / qtd;
  return media;
}

void imprimirMenorCompraMulher(vd *vetor, int totalvendas) {
  int *listaIndexMulheres = (int *)malloc(sizeof(int));

  float menorCompra = 0;

  int i;
  for (i = 0; i < totalvendas; i++) {
    if (vetor[i].cli.sexo == 'f' &&
        (menorCompra == 0 || vetor[i].valorTotal < menorCompra)) {
      menorCompra = vetor[i].valorTotal;
    }
  }

  int tamLista = 0;

  for (i = 0; i < totalvendas; i++) {
    if (vetor[i].valorTotal == menorCompra) {
      listaIndexMulheres[tamLista] = i;
      tamLista++;
      listaIndexMulheres =
          realloc(listaIndexMulheres, (tamLista + 1) * sizeof(int));
    }
  }

  for (i = 0; i < tamLista; i++) {
    imprimirVendas(vetor, listaIndexMulheres[i], i + 1);
  }

  if (tamLista == 0) {
    printf("Não registros de compras realizadas por mulheres.\n\n");
  }

  free(listaIndexMulheres);
}

float valorVendasPorN(vd *vetor, int totalvendas) {
  float valorTotal = 0;

  int i;

  for (i = 0; i < totalvendas; i++) {
    if (vetor[i].cli.sexo == 'n') {
      valorTotal += vetor[i].valorTotal;
    }
  }

  return valorTotal;
}