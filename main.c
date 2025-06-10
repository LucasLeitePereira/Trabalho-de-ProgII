#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
  char nome[50];
  char sexo;
  int idade;
};

struct venda {
  struct cliente cliente;
  int qntdItensVendidos;
  char unidade;
  float valorTotal;
};

typedef struct venda vd;
typedef char* string;

void cadastrarCliente();

void pesquisaPorNome(FILE *loja);

int quantidadeVenda(string **vetor, int totalV); // Função 2

int compradoresM(string **vetor, int totalvendas); // Função 4

int retornarQntdItens(FILE *loja); // Função 6

void imprimirdadosmaiornome(string *lista);//função 10

void imprimirDadosdoMaisNovo(string **lista, int tamanho); // Função 11
void criarVetor();
  
int main (void) {
  FILE *loja;
  
  int opcaoMenu; 

  do {
    printf("1. Cadastrar Venda\n2. Pesquisar por venda pelo nome\n3. Consultar Informações\n4. Encerrar progama\n");
    printf("Opção: ");

    scanf("%i", &opcaoMenu);

    system("clear");

    if (opcaoMenu == 1) {
      int opcaoCadastro;

      do {
        cadastrarCliente();
        
        printf("1. Cadastrar novamente\n2. Voltar para o menu\n"); 
        printf("Opção: ");

        scanf("%i", &opcaoCadastro);

        system("clear");
      } while (opcaoCadastro == 1);
    } 
    else if (opcaoMenu == 2 || opcaoMenu == 3) {
      FILE *loja = fopen("loja.txt", "r");
      char linha[50];

      string **vetor = NULL;

      int colunas = 6;
      int tamanho = 0;
      int capacidade = 0;

      int linhasLidas = 0;

      while(fgets(linha, sizeof(linha), loja) != NULL) {
        if (linhasLidas < 1 || linhasLidas % 6 == 0) {
          if (tamanho + 1 > capacidade) {
            int novaCapacidade = capacidade + 1;
            tamanho = novaCapacidade;
            string *temp = realloc(vetor, novaCapacidade * sizeof *vetor);

            if (temp == NULL) {
              free(vetor);
            }
            vetor = temp;
            capacidade = novaCapacidade;

            for (int i = 0; i < capacidade; i++) {
              vetor[i] = (string *) malloc(colunas * sizeof(string));
            }
          }
          tamanho++;
        }
        linhasLidas++;
      }

      fclose(loja);

      loja = fopen("loja.txt", "r");
      
      for (int i = 0; i < capacidade; i++) {
        for (int j = 0; j < colunas; j++) {
          char dadoDaLinha[50];
          fscanf(loja, "%s", dadoDaLinha);
          vetor[i][j] = strdup(dadoDaLinha);
        }
      }
      
      fclose(loja);
      
      if (opcaoMenu == 2) {
        int opcaoPesquisaNome;

        do {
          FILE *loja = fopen("loja.txt", "r"); 

          if (loja == NULL) { 
            printf("Arquivo não encontrado!\n");
            return 1;
          }

          pesquisaPorNome(loja);

          fclose(loja);

          printf("1. Pesquisar novamente\n2. Voltar para o menu\n");
          printf("Opção: ");

          scanf("%i", &opcaoPesquisaNome);

          system("clear");
        } while (opcaoPesquisaNome == 1);
      } 
      else {
        int opcaoPesquisa;

        do {
          int opcaoMenuPesquisa;

          do {
            FILE *loja = fopen("loja.txt", "r"); 

            if (loja == NULL) { 
              printf("Arquivo não encontrado!\n");
              return 1;
            }

            printf("Selecione uma das opções de pesquisa\n\n");
            printf("| 1. Vendas abaixo de um valor\n| 2. Vendas com 3 itens vendidos\n| 3. Vendas realizadas na unidade “B”\n");        
            printf("| 4. Quantidade de compradores homens\n| 5. Valor total comprado por compradores não identificados\n| 6. Quantidade total de itens vendidos\n"); 
            printf("| 7. Valor total das vendas\n| 8. Valor médio de uma venda\n| 9. Compra mais barata feito por uma mulher\n");  
            printf("| 10. Dados da venda do cliente com o maior nome\n| 11. Dados da venda do cliente mais novo\n| 12. Voltar ao menu\n\n");

            printf("Opção: ");
            scanf("%i", &opcaoMenuPesquisa);

            system("clear");

            if (opcaoMenuPesquisa == 1) {
              printf("Informe o valor: ");
              scanf("%i", )
            }
            else if (opcaoMenuPesquisa == 2) { // FOI
              printf("Função chamada!\n");
              int TotalVendas = quantidadeVenda(vetor, capacidade);
              printf("---------------------------------\n");
              printf("A quantidade de venda que teve exatamente 3 itens vendido são: %d!\n", TotalVendas);
              printf("---------------------------------\n\n");
            }
            else if (opcaoMenuPesquisa == 3) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 4) { // FOI
              printf("Função chamada!\n");
              int TotalM =  compradoresM(vetor, capacidade);
              printf("---------------------------------\n");
              printf("O total de itens comprados Masculinos são: %d!\n", TotalM);
              printf("---------------------------------\n\n");
            }
            else if (opcaoMenuPesquisa == 5) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 6) {
              int qntdItens;
              qntdItens = retornarQntdItens(loja);
              printf("---------------------------------\n");
              printf("Foram vendidos %i itens no total!\n", qntdItens);
              printf("---------------------------------\n\n");
            }
            else if (opcaoMenuPesquisa == 7) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 8) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 9) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 10) {
              printf("Função chamada!\n");
            }
            else if (opcaoMenuPesquisa == 11) {
              imprimirDadosdoMaisNovo(vetor, capacidade);
            }
            else if (opcaoMenuPesquisa == 12) {
              // Volta para o menu
            }
            else {
              printf("Opção inválida! Tente novamente\n");
            }

            fclose(loja);
          } while (opcaoMenuPesquisa < 0 && opcaoMenuPesquisa > 12);

          printf("1. Pesquisar novamente | 2. Encerrar programa\n\n");
          printf("Opção: ");

          scanf("%i", &opcaoPesquisa);

          system("clear");

          if (opcaoPesquisa == 2) {
            printf("Encerrando programa...");
            return 1;
          }

        } while (opcaoPesquisa == 1);
      } 

      for (int i = 0; i < capacidade; i ++) {
        free(vetor[i]);
      }
      free(vetor);
    }
    else if (opcaoMenu == 4) {
      system("clear");
      printf("Encerrando programa...");
    } 
    else {
      system("clear");
      printf("Opção Inválida!\n\n");
      printf("Encerrando programa...");
    }
  } while (opcaoMenu >= 1 && opcaoMenu <= 3);


  return 0;
}

void cadastrarCliente() {
  system("clear");

  int numVendasCadastro;
  printf("Quantas vendas serão cadastradas?: ");
  scanf(" %i", &numVendasCadastro);

  vd vendaAtual;

  for (int i = 0; i < numVendasCadastro; i++) {
    FILE *loja = fopen("loja.txt", "a");
    system("clear");

    getchar();

    do {
      printf("Nome do cliente: ");
      fgets(vendaAtual.cliente.nome, sizeof(vendaAtual.cliente.nome), stdin);
      vendaAtual.cliente.nome[strcspn(vendaAtual.cliente.nome, "\n")] = '\0';

      system("clear");

      if (strlen(vendaAtual.cliente.nome) <= 3) {
        printf("Nome inválido! preencha um nome com mais de 3 letras\n");
        printf("Tente novamente\n\n");
      }
    } while (strlen(vendaAtual.cliente.nome) <= 3);

    do {
      printf("Sexo (m | f | n): ");
      scanf(" %c", &vendaAtual.cliente.sexo);

      system("clear");

      if (vendaAtual.cliente.sexo != 'm' && vendaAtual.cliente.sexo != 'f' && vendaAtual.cliente.sexo != 'n') {
        printf("Opção inválida! preencha com uma dass opções disponivéis\n");
        printf("Tente novamente\n\n");
      }
    } while (vendaAtual.cliente.sexo != 'm' && vendaAtual.cliente.sexo != 'f' && vendaAtual.cliente.sexo != 'n');

    do {
      printf("Idade: ");
      scanf(" %i", &vendaAtual.cliente.idade);

      system("clear");
      
      if (vendaAtual.cliente.idade <= 0) {
        printf("Idade inválida! Preencha um idade maior que 0\n");
        printf("Tente novamente\n\n");
      }
    } while (vendaAtual.cliente.idade <= 0);

    do {
      printf("Quntidade de Itens Vendidos: ");
      scanf(" %i", &vendaAtual.qntdItensVendidos);

      system("clear");

      if (vendaAtual.qntdItensVendidos <= 0) {
        printf("Número de itens inválido! Não é possível cadastrar números menores ou igual a 0\n");
        printf("Tente novamente\n\n");
      }
    } while (vendaAtual.qntdItensVendidos <= 0);

    do {
      printf("Unidade (a | b | c): ");
      scanf(" %c", &vendaAtual.unidade);

      system("clear");

      if (vendaAtual.unidade != 'a' && vendaAtual.unidade != 'b' && vendaAtual.unidade != 'c') {
        printf("Opção inválida! preencha com uma dass opções disponivéis\n");
        printf("Tente novamente\n\n");
      }
    } while (vendaAtual.unidade != 'a' && vendaAtual.unidade != 'b' && vendaAtual.unidade != 'c');

    do {
      printf("Valor total da venda: ");
      scanf(" %f", &vendaAtual.valorTotal);

      system("clear");

      if (vendaAtual.valorTotal<= 0) {
        printf("Valor inválido, não é possível cadastar números menores ou igual a 0\n");
        printf("Tente novamente\n\n");
      }
    } while (vendaAtual.valorTotal <= 0);

    system("clear");

    fprintf(loja, "%s\n%c\n%i\n%i\n%c\n%.2f\n", vendaAtual.cliente.nome, vendaAtual.cliente.sexo, vendaAtual.cliente.idade, vendaAtual.qntdItensVendidos, vendaAtual.unidade, vendaAtual.valorTotal);
    printf("Dados gravados com sucesso!\n\n");
    
    fclose(loja);
  }
  
}

void pesquisaPorNome(FILE *loja) {
  // system("clear");

  char pesquisaNome[50];

  getchar();

  printf("Nome do cliente: ");
  fgets(pesquisaNome, sizeof(pesquisaNome), stdin);
  system("clear");

  char linha[50];

  int qntdNomesEncontrados = 0;

  float valorGastoNoTotal = 0;

  while(fgets(linha, sizeof(linha), loja) != NULL) {
    if (strcmp(linha, pesquisaNome) == 0) {
      qntdNomesEncontrados++;

      for (int i = 0; i < 5; i++) {
        fgets(linha, sizeof(linha), loja);
        linha[strcspn(linha, "\n")] = '\0';
        if (i == 2) {
          printf("%s Itens Vendidos\n", linha);
        } else if (i == 3) {
          printf("Unidade: %s\n", linha);
        } else if (i == 4) {
          printf("R$%s Reais\n", linha);
          valorGastoNoTotal += (float) atoll(linha);
        }
      }
      printf("-----------------\n");
    }
  }
  if (qntdNomesEncontrados == 0) {
    printf("Nome não encontrado!\n\n");
  } else {
    printf("Valor total gasto: R$%.2f\n\n", valorGastoNoTotal);
  }
}

int retornarQntdItens(FILE *loja) {
  int qntItens = 0;

  char linha[100];

  char nome[50];
  int idade, qntd;
  char sexo, uni;
  float valor;
  
  while (fgets(linha, sizeof(linha), loja) != NULL) {
    fscanf(loja, "%s\n%c\n%i\n%i\n%c\n%f", nome, &sexo, &idade, &qntd, &uni, &valor);
    qntItens += (int) qntd;
    qntd = 0; // Isso aqui é gambiarra, pq o fgets le uma linha e fscanf tambem, ent a qntItens recebe duas vezes o mesmo valor
  }
  return qntItens;
}

void imprimirDadosdoMaisNovo(string **lista, int tamanho) {
  int idadeMaisNova = atoi(lista[0][2]);
  int indexIdadeMaisNova = 0;

  for (int i = 1; i < tamanho; i++) {
    int idadeAtual = atoi(lista[i][2]);
    if (idadeAtual < idadeMaisNova) {
      idadeMaisNova = idadeAtual;
      indexIdadeMaisNova = i;
    }
  }
  printf("-------------------\n");
  printf("Idade mais nova: %i\n", idadeMaisNova);
  printf("-------------------\n\n");

  for (int i = 0; i <  tamanho; i++) {
    int idadePesquisa = atoi(lista[i][2]);
    if (idadePesquisa == idadeMaisNova) {
      for (int j = 0; j < 6; j++) {
        printf("Nome: %s\n", lista[i][j]);
        printf("Sexo: %s\n", lista[i][j]);
        printf("Idade: %i\n", atoi(lista[i][j]));
        printf("Quantidade: %i\n", atoi(lista[i][j]));
        printf("Unidade: %s\n", lista[i][j]);
        printf("Valor: %.2f\n\n", atof(lista[i][j]));
      }
    }
  }
}


int compradoresM(string **vetor, int totalvendas) { // Função 4
    int total = 0;
    for (int i = 0; i < totalvendas; i++) {
        if (vetor[i][1][0] == 'm') {
              total++;
        }
    }
    return total;
}

int quantidadeVenda(string **vetor, int totalV){ // Função 2
int  totalQ = 0;
int i= 0;
  for(i= 0; i < totalV; i++){
    if (strcmp(vetor[i][2], "3") == 0) {  //o strcmp sserve para comparar duas strings 
        totalQ++;
    }
  }
  return totalQ;
}
