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

int main (void) {
    // Criar o menu
    // Cadastro
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