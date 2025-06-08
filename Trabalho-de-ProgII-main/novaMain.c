#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

int main (void) {

    setlocale(LC_ALL, "Portuguese");

    system("CLS");

    int opcaoMenu;
    int numVendasCadastro;

    do {
        printf("1. Cadastrar Venda\n2. Pesquisar por venda pelo nome\n3. Consultar Informacoes\n4. Encerrar progama\n");
        printf("Opcao: ");

        scanf("%i", &opcaoMenu);

        system("CLS");

        switch (opcaoMenu)
        {
        case 1:
            
            printf("Quantas vendas serão cadastradas?: ");
            scanf(" %i", &numVendasCadastro);

            system("CLS");

            vd *vendasCadastro = (vd *) malloc(numVendasCadastro * sizeof(vd));

            int i;
            for (i = 0; i < numVendasCadastro; i++) {
                getchar();
                do {
                printf("Nome do cliente: ");
                fgets(vendasCadastro[i].cli.nome, sizeof(vendasCadastro[i].cli.nome), stdin);
                vendasCadastro[i].cli.nome[strcspn(vendasCadastro[i].cli.nome, "\n")] = '\0';

                system("CLS");

                if (strlen(vendasCadastro[i].cli.nome) <= 3) {
                    printf("Nome inválido! preencha um nome com mais de 3 letras\n");
                    printf("Tente novamente\n\n");
                }
                } while (strlen(vendasCadastro[i].cli.nome) <= 3);

                do {
                printf("Sexo (m | f | n): ");
                scanf(" %c", &vendasCadastro[i].cli.sexo);

                system("CLS");

                if (vendasCadastro[i].cli.sexo != 'm' && vendasCadastro[i].cli.sexo != 'f' && vendasCadastro[i].cli.sexo != 'n') {
                    printf("Opção inválida! preencha com uma dass opções disponivéis\n");
                    printf("Tente novamente\n\n");
                }
                } while (vendasCadastro[i].cli.sexo != 'm' && vendasCadastro[i].cli.sexo != 'f' && vendasCadastro[i].cli.sexo != 'n');

                do {
                printf("Idade: ");
                scanf(" %i", &vendasCadastro[i].cli.idade);

                system("CLS");
                
                if (vendasCadastro[i].cli.idade <= 0) {
                    printf("Idade inválida! Preencha um idade maior que 0\n");
                    printf("Tente novamente\n\n");
                }
                } while (vendasCadastro[i].cli.idade <= 0);

                do {
                printf("Quntidade de Itens Vendidos: ");
                scanf(" %i", &vendasCadastro[i].qntdItensVendidos);

                system("CLS");

                if (vendasCadastro[i].qntdItensVendidos <= 0) {
                    printf("Número de itens inválido! Não é possível cadastrar números menores ou igual a 0\n");
                    printf("Tente novamente\n\n");
                }
                } while (vendasCadastro[i].qntdItensVendidos <= 0);

                do {
                printf("Unidade (a | b | c): ");
                scanf(" %c", &vendasCadastro[i].unidade);

                system("CLS");

                if (vendasCadastro[i].unidade != 'a' && vendasCadastro[i].unidade != 'b' && vendasCadastro[i].unidade != 'c') {
                    printf("Opção inválida! preencha com uma dass opções disponivéis\n");
                    printf("Tente novamente\n\n");
                }
                } while (vendasCadastro[i].unidade != 'a' && vendasCadastro[i].unidade != 'b' && vendasCadastro[i].unidade != 'c');

                do {
                printf("Valor total da venda: ");
                scanf(" %f", &vendasCadastro[i].valorTotal);

                system("CLS");

                if (vendasCadastro[i].valorTotal<= 0) {
                    printf("Valor inválido, não é possível cadastar números menores ou igual a 0\n");
                    printf("Tente novamente\n\n");
                }
                } while (vendasCadastro[i].valorTotal <= 0);

                system("CLS");
            }

            FILE *arq = fopen("loja.txt", "a");
            if (arq == NULL) {
                printf("Erro ao tentar abrir o arquivo 'loja.txt'\n");
                return 1;
            }

            for (i = 0; i < numVendasCadastro; i++) {
                system("CLS");
                fprintf(arq, "%s\n%c\n%i\n%i\n%c\n%.2f\n", 
                    vendasCadastro[i].cli.nome, 
                    vendasCadastro[i].cli.sexo, 
                    vendasCadastro[i].cli.idade, 
                    vendasCadastro[i].qntdItensVendidos, 
                    vendasCadastro[i].unidade, 
                    vendasCadastro[i].valorTotal);
                printf("Dados gravados com sucesso!\n\n");
            }

            free(vendasCadastro);
            fclose(arq);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            printf("Encerrando o programa...");
            break;
        default:
            printf("Opção Inválida! Tente novamente.\n\n");
        }
    } while (opcaoMenu != 4);

    return 0;
}

// system("CLS");

//     FILE *arquivo = fopen("loja.txt", "r");
//     if (arquivo == NULL) {
//         printf("Erro: Arquivo não encontrado!");
//         return 3;
//     }

//     int tamanhoAtualVetor = 1;
//     int quantidadeDeVendas = 0;

//     vd *vetor = (vd *) malloc (tamanhoAtualVetor * sizeof(vd));
//     if (vetor == NULL) {
//         printf("Erro: Memoria insuficiente!");
//         system("pause");
//         return 2;
//     }

//     int i = 0;
//     while (fscanf(arquivo, "%49s %c %d %d %c %f", 
//         vetor[i].cli.nome,
//         &vetor[i].cli.sexo,
//         &vetor[i].cli.idade,
//         &vetor[i].qntdItensVendidos,
//         &vetor[i].unidade,
//         &vetor[i].valorTotal  
//     ) == 6) {
//         quantidadeDeVendas++;
//         if (quantidadeDeVendas == tamanhoAtualVetor) {
//             tamanhoAtualVetor++;
//             vetor = realloc(vetor, tamanhoAtualVetor * sizeof(vd));
//             if (vetor == NULL) {
//                 printf("Erro: Memoria insuficiente!");
//                 system("pause");
//                 return 2;
//             }
//         }
//         i++;
//     }

//     for (i = 0; i < quantidadeDeVendas; i++) {
//         printf("Sexo: %c\n", vetor[i].cli.sexo);
//     }

//     free(vetor);
//     fclose(arquivo);