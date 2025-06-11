#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct cliente
{
    char nome[50];
    char sexo;
    int idade;
};

struct venda
{
    struct cliente cli;
    int qntdItensVendidos;
    char unidade;
    float valorTotal;
};

typedef struct venda vd;

int compradoresM( vd *venda, int totalvendas);

void imprimirVendas(vd *vetor, int index, int qntd);

int quantidadeVenda(vd *vetor, int totalV); 

int compradoresM(vd *venda, int totalvendas);

void procurarVendasAbaixoValor(vd *vetor, int totalVendas, float valor);

int vendasNaUnidadeB (vd *vetor, int totalVendas);

void procurarClienteMaiorNome (vd *vetor, int totalVendas);

void imprimriDadosVendaMaisNovo(vd *vetor, int totalVendas);

int qtdTotalItensVendidos(vd *vetor, int totalvendas);

float ValorTotalDasVendas(vd *vetor, int totalvendas);

float mediaTotalDaVenda(vd *vetor, int totalvendas);

void imprimirMenorCompraMulher(vd *vetor, int totalvendas);

float valorVendasPorN(vd *vetor, int totalvendas);

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    system("CLS");

    int opcaoMenu;
    int numVendasCadastro;
    int opcaoPesquisa;
    int opcaoMenuPesquisa;

    FILE *arq = NULL;
    vd *listaDeVendas = NULL;

    int tamanhoAtualVetor;
    int quantidadeDeVendas;

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
    do
    {
        system("CLS");
        printf("1. Cadastrar Venda\n2. Pesquisar por venda pelo nome\n3. Consultar Informacoes\n4. Encerrar progama\n");
        printf("Opcao: ");

        scanf("%i", &opcaoMenu);
        getchar();

        system("CLS");

        switch (opcaoMenu)
        {
        case 1:
            do
            {
                printf("Quantas vendas serão cadastradas?: ");
                scanf(" %i", &numVendasCadastro);
                if (numVendasCadastro <= 0)
                {
                    printf("Numero invalido, tente novamente!\n\n");
                }
            } while (numVendasCadastro <= 0);

            system("CLS");

            vd *vendasCadastro = (vd *)malloc(numVendasCadastro * sizeof(vd));

            for (i = 0; i < numVendasCadastro; i++)
            {
                getchar();
                do
                {
                    printf("Nome do cliente: ");
                    fgets(vendasCadastro[i].cli.nome, sizeof(vendasCadastro[i].cli.nome), stdin);
                    vendasCadastro[i].cli.nome[strcspn(vendasCadastro[i].cli.nome, "\n")] = '\0';

                    system("CLS");

                    if (strlen(vendasCadastro[i].cli.nome) <= 3)
                    {
                        printf("Nome inválido! preencha um nome com mais de 3 letras\n");
                        printf("Tente novamente\n\n");
                    }
                } while (strlen(vendasCadastro[i].cli.nome) <= 3);

                do
                {
                    printf("Sexo (m | f | n): ");
                    scanf(" %c", &vendasCadastro[i].cli.sexo);

                    system("CLS");

                    if (vendasCadastro[i].cli.sexo != 'm' && vendasCadastro[i].cli.sexo != 'f' && vendasCadastro[i].cli.sexo != 'n')
                    {
                        printf("Opcao invalida! preencha com uma dass opções disponivéis\n");
                        printf("Tente novamente\n\n");
                    }
                } while (vendasCadastro[i].cli.sexo != 'm' && vendasCadastro[i].cli.sexo != 'f' && vendasCadastro[i].cli.sexo != 'n');

                do
                {
                    printf("Idade: ");
                    scanf(" %i", &vendasCadastro[i].cli.idade);

                    system("CLS");

                    if (vendasCadastro[i].cli.idade <= 0)
                    {
                        printf("Idade invalida! Preencha um idade maior que 0\n");
                        printf("Tente novamente\n\n");
                    }
                } while (vendasCadastro[i].cli.idade <= 0);

                do
                {
                    printf("Quntidade de Itens Vendidos: ");
                    scanf(" %i", &vendasCadastro[i].qntdItensVendidos);

                    system("CLS");

                    if (vendasCadastro[i].qntdItensVendidos <= 0)
                    {
                        printf("Número de itens inválido! Não é possível cadastrar números menores ou igual a 0\n");
                        printf("Tente novamente\n\n");
                    }
                } while (vendasCadastro[i].qntdItensVendidos <= 0);

                do
                {
                    printf("Unidade (a | b | c): ");
                    scanf(" %c", &vendasCadastro[i].unidade);

                    system("CLS");

                    if (vendasCadastro[i].unidade != 'a' && vendasCadastro[i].unidade != 'b' && vendasCadastro[i].unidade != 'c')
                    {
                        printf("Opcao invalida! preencha com uma dass opções disponivéis\n");
                        printf("Tente novamente\n\n");
                    }
                } while (vendasCadastro[i].unidade != 'a' && vendasCadastro[i].unidade != 'b' && vendasCadastro[i].unidade != 'c');

                do
                {
                    printf("Valor total da venda: ");
                    scanf(" %f", &vendasCadastro[i].valorTotal);

                    system("CLS");

                    if (vendasCadastro[i].valorTotal <= 0)
                    {
                        printf("Valor inválido, não é possível cadastar números menores ou igual a 0\n");
                        printf("Tente novamente\n\n");
                    }
                } while (vendasCadastro[i].valorTotal <= 0);

                system("CLS");
            }

            arq = fopen("loja.txt", "a");
            if (arq == NULL)
            {
                printf("Erro ao tentar abrir o arquivo 'loja.txt'\n");
                return 1;
            }

            for (i = 0; i < numVendasCadastro; i++)
            {
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
            arq = fopen("loja.txt", "r");

            tamanhoAtualVetor = 1;
            quantidadeDeVendas = 0;

            listaDeVendas = (vd *)malloc(tamanhoAtualVetor * sizeof(vd));
            if (listaDeVendas == NULL)
            {
                printf("Erro: Memoria Insuficiente\n");
                system("pause");
                exit(1);
            }

            i = 0;
            while (fscanf(arq, " %49[^\n] %c %d %d %c %f",
                          listaDeVendas[i].cli.nome,
                          &listaDeVendas[i].cli.sexo,
                          &listaDeVendas[i].cli.idade,
                          &listaDeVendas[i].qntdItensVendidos,
                          &listaDeVendas[i].unidade,
                          &listaDeVendas[i].valorTotal) == 6)
            {
                quantidadeDeVendas++;
                if (quantidadeDeVendas == tamanhoAtualVetor)
                {
                    tamanhoAtualVetor++;
                    listaDeVendas = realloc(listaDeVendas, tamanhoAtualVetor * sizeof(vd));
                    if (listaDeVendas == NULL)
                    {
                        printf("Erro: Memoria insuficiente!");
                        system("pause");
                        return 2;
                    }
                }
                i++;
            }
            fclose(arq);

            do
            {
                qntVendasEncontradasPorNome = 0;
                printf("Procuras pelas vendas realizadas para o(a): ");
                fgets(nomeProcura, sizeof(nomeProcura), stdin);
                nomeProcura[strcspn(nomeProcura, "\n")] = '\0';

                for (i = 0; i < quantidadeDeVendas; i++)
                {
                    if (strcmp(nomeProcura, listaDeVendas[i].cli.nome) == 0)
                    {
                        qntVendasEncontradasPorNome++;
                        printf("\nVenda[%i]\n", qntVendasEncontradasPorNome);
                        printf("Quantidade de itens: %i\n", listaDeVendas[i].qntdItensVendidos);
                        printf("Unidade: %c\n", listaDeVendas[i].unidade);
                        printf("Valor total da venda: %.2f\n\n", listaDeVendas[i].valorTotal);
                    }
                }

                if (qntVendasEncontradasPorNome == 0)
                {
                    printf("Nenhuma venda foi encontrada no nome do(a): %s\n", nomeProcura);
                }

                printf("1. Pesquisar novamente\n2. Voltar para o menu\nOpcao: ");
                scanf("%i", &opcaoPesquisaNome);
                getchar();
                system("CLS");
            } while (opcaoPesquisaNome == 1);

            free(listaDeVendas);
            break;

        case 3:
            arq = fopen("loja.txt", "r");

            tamanhoAtualVetor = 1;
            quantidadeDeVendas = 0;

            listaDeVendas = (vd *)malloc(tamanhoAtualVetor * sizeof(vd));
            if (listaDeVendas == NULL)
            {
                printf("Erro: Memoria Insuficiente\n");
                system("pause");
                exit(1);
            }

            i = 0;
            while (fscanf(arq, " %49[^\n] %c %d %d %c %f",
                          listaDeVendas[i].cli.nome,
                          &listaDeVendas[i].cli.sexo,
                          &listaDeVendas[i].cli.idade,
                          &listaDeVendas[i].qntdItensVendidos,
                          &listaDeVendas[i].unidade,
                          &listaDeVendas[i].valorTotal) == 6)
            {
                quantidadeDeVendas++;
                if (quantidadeDeVendas == tamanhoAtualVetor)
                {
                    tamanhoAtualVetor++;
                    listaDeVendas = realloc(listaDeVendas, tamanhoAtualVetor * sizeof(vd));
                    if (listaDeVendas == NULL)
                    {
                        printf("Erro: Memoria insuficiente!");
                        system("pause");
                        return 2;
                    }
                }
                i++;
            }
            fclose(arq);

            do
            {
                do
                {
                    printf("Selecione uma das opcoes de pesquisa\n\n");
                    printf("| 1. Vendas abaixo de um valor\n| 2. Vendas com 3 itens vendidos\n| 3. Vendas realizadas na unidade 'B'\n");
                    printf("| 4. Quantidade de compradores homens\n| 5. Valor total comprado por compradores nao identificados\n| 6. Quantidade total de itens vendidos\n");
                    printf("| 7. Valor total das vendas\n| 8. Valor medio de uma venda\n| 9. Compra mais barata feito por uma mulher\n");
                    printf("| 10. Dados da venda do cliente com o maior nome\n| 11. Dados da venda do cliente mais novo\n\n");

                    printf("Opcao: ");
                    scanf("%i", &opcaoMenuPesquisa);

                    system("CLS");

                    switch (opcaoMenuPesquisa)
                    {
                    case 1:
                        printf("Informe o valor: ");
                        scanf(" %f", &valorBusca);
                        system("CLS");
                        getchar();
                        procurarVendasAbaixoValor(listaDeVendas, quantidadeDeVendas, valorBusca);
                        break;

                    case 2:
                        TotalVendas = 0;
                        TotalVendas = quantidadeVenda(listaDeVendas, quantidadeDeVendas);
                        printf("A quantidade de venda que teve exatamente 3 itens vendido sao: %d!\n\n", TotalVendas);
                        break;

                    case 3:
                        numVendasEncontradas = vendasNaUnidadeB (listaDeVendas, quantidadeDeVendas);
                        printf("Quntidade de vendas na unidade B: %i\n\n", numVendasEncontradas);
                        break;

                    case 4:
                        totalM = compradoresM(listaDeVendas, quantidadeDeVendas);
                        printf("Total de Homens compradores e: %d!\n",totalM);
                        break;

                    case 5:
                        valorComprasPorN = valorVendasPorN(listaDeVendas, quantidadeDeVendas);
                        printf("Valor total das compras realizadas por clientes não identificados: R$%.2f\n", valorComprasPorN);
                        break;

                    case 6:
                        total = qtdTotalItensVendidos(listaDeVendas,  quantidadeDeVendas);
                        printf("O total dde intens vendido e %d\n", total);
                        break;

                    case 7:
                        totalV = ValorTotalDasVendas(listaDeVendas, quantidadeDeVendas);
                        printf("O valor total das vendas: R$%.2f\n", totalV);
                        break;

                    case 8:
                        mediaTotal = mediaTotalDaVenda(listaDeVendas, quantidadeDeVendas);
                        printf("O valor media das comrpas: R$%.2f\n",mediaTotal);
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

                system("CLS");

                if (opcaoPesquisa == 2)
                {
                    free(listaDeVendas);
                    printf("Encerrando programa...");
                    return 1;
                }
            } while (opcaoPesquisa == 1);
            break;
        case 4:
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
    for (i = 0; i < totalV; i++)
    {
        if (vetor[i].qntdItensVendidos == 3)
        {
            totalQ++;
        }
    }
    return totalQ;
}

int compradoresM( vd *venda, int totalvendas) { // Função 4
    int total = 0;
    int i = 0;
    for(i = 0; i < totalvendas; i++) {
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

int vendasNaUnidadeB (vd *vetor, int totalVendas) {
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

void procurarClienteMaiorNome (vd *vetor, int totalVendas) {
    int *ListaIndexMaiorNome = (int *) malloc(sizeof(int));

    int tamMaiorNome = 0;

    int i;
    int tamLista = 0;

    for (i = 0; i < totalVendas; i++) { // Primeiro define o tamanho do maior nome
        if (strlen(vetor[i].cli.nome) > tamMaiorNome) {
            tamMaiorNome = strlen(vetor[i].cli.nome);
        }
    }

    for (i = 0; i < totalVendas; i++) { // Depois aloca em um vetor o index dos nomes que possuem esse tamanho
        if(strlen(vetor[i].cli.nome) == tamMaiorNome){
            ListaIndexMaiorNome[tamLista] = i;
            tamLista++;
            ListaIndexMaiorNome = realloc(ListaIndexMaiorNome, (tamLista + 1) * sizeof(int));
        }
    }

    for (i = 0; i < tamLista; i++) { // Imprime a venda do maior nome
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

int qtdTotalItensVendidos(vd *vetor, int totalvendas){
int i = 0;
int total = 0;
for( i = 0; i < totalvendas; i++){
    total += vetor[i].qntdItensVendidos;
}
return total;
}

float ValorTotalDasVendas(vd *vetor, int totalvendas){
int i = 0;
float totalV = 0;
for(i = 0; i < totalvendas; i++){
            totalV += vetor[i].valorTotal;
}
return totalV;
}

float mediaTotalDaVenda(vd *vetor, int totalvendas){
int i = 0;
float soma = 0;
int qtd = 0;
float media;
for(i = 0; i < totalvendas; i++){
        soma+= vetor[i].valorTotal;
        qtd++;
}
media = soma / qtd;
return media; 
}

void imprimirMenorCompraMulher(vd *vetor, int totalvendas) {
    int *listaIndexMulheres = (int *) malloc (sizeof(int));

    float menorCompra = 0;


    int i;
    for(i = 0; i < totalvendas; i++) {
        if (vetor[i].cli.sexo == 'f' && (menorCompra == 0 || vetor[i].valorTotal < menorCompra)) {
            menorCompra = vetor[i].valorTotal;
        }
    }

    int tamLista = 0;

    for(i = 0; i < totalvendas; i++) {
        if (vetor[i].valorTotal == menorCompra) {
            listaIndexMulheres[tamLista] = i;
            tamLista++;
            listaIndexMulheres = realloc(listaIndexMulheres, (tamLista + 1) * sizeof(int));
        }
    }

    for (i = 0; i < tamLista; i++) {
        imprimirVendas(vetor, listaIndexMulheres[i], i + 1);
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