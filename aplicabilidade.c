#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define TAMANHO 10

#include "Include.h"

struct produto {
    char nomeProduto[21];
    char codigoProduto[11];
    char descricaoProduto[55];
    float vCompraProduto;
    float vVendaProduto;
    int quantidadeProduto;
};


typedef struct produto Produto;

void CadastraProduto(Produto *produtos,Produto p,int posicao);
int BuscaPorCodigo(Produto *produtos,int codigoBarras,int posicao);
void ListarProdutos(Produto *produtos,int posicao);
void ImprimirProduto(Produto *produtos,int posicaoProduto);
void AtualizaQuantidade(Produto *produtos, int posicaoProduto, int novaQuantidade);
int ComprarProduto(Produto *produtos,float *caixa,int quantidade,int posicaoProduto);
int VenderProduto(Produto *produtos,float *caixa,int quantidade,int posicaoProduto);


#include "Produto.h"

int main()
{

    Produto produtos[TAMANHO];
    Produto aux;
    char codigoBarras[11];
    int posicao = 0;
    int posicaoEncontrada,menuop,quant;
    float caixa = 100;
    printf("\tMENU PRINCIPAL\n\n");
    printf("\t1 - Cadastro de novo produto;\n");
    printf("\t2 - Busca de produto\n");
    printf("\t3 - Listagem de produtos\n");
    printf("\t4 - Controle de caixa\n");
    printf("\t5 - Sair\n");
    fflush(stdin);
    scanf("%d", &menuop);
    while(menuop != 5){
        switch(menuop) {
            case 1:{
                system("cls");
                if(posicao < TAMANHO){
                    printf("Entre com o [Nome]:\n");
                    fflush(stdin);
                    gets(aux.nomeProduto);
                    printf("Entre com o [Codigo de Barras]:\n");
                    fflush(stdin);
                    gets(aux.codigoProduto);
                    printf("Entre com a [Descricao]:\n");
                    fflush(stdin);
                    gets(aux.descricaoProduto);
                    printf("Entre com o [Valor de Compra]:\n");
                    fflush(stdin);
                    scanf("%f",&aux.vCompraProduto);
                    printf("Entre com o [Valor de Venda]:\n");
                    fflush(stdin);
                    scanf("%f",&aux.vVendaProduto);
                    printf("Entre com a [Quantidade]:\n");
                    fflush(stdin);
                    scanf("%d",&aux.quantidadeProduto);
                    CadastraProduto(produtos,aux,posicao);
                    posicao++;
                }
                else{
                    printf("Numero maximo de produtos cadastrados: %d produtos",TAMANHO);
                }
                system("PAUSE");
                break;
            }
            case 2:{
                system("cls");
                printf("Entre com o [Codigo de Barras]:\n");
                fflush(stdin);
                gets(codigoBarras);
                posicaoEncontrada = BuscaPorCodigo(produtos,codigoBarras,posicao);
                if(posicaoEncontrada == -1){
                    printf("Produto nao encontrado");
                }
                else{
                    ImprimirProduto(produtos,posicaoEncontrada);
                }

                system("PAUSE");
                break;
            }
            case 3:{
                ListarProdutos(produtos,posicao);
                system("PAUSE");
                break;
            }
            case 4:{
                system("cls");
                printf("\tCONTROLE DE CAIXA\n\n");
                printf("\t1 - Comprar produto;\n");
                printf("\t2 - Vender produto\n");
                printf("\t3 - Voltar\n");
                fflush(stdin);
                scanf("%d", &menuop);
                printf("Entre com o [Codigo de Barras]:\n");
                fflush(stdin);
                gets(codigoBarras);
                printf("Entre com a [Quantidade]:\n");
                fflush(stdin);
                scanf("%d",&quant);
                switch(menuop){
                    case 1:{
                        posicaoEncontrada = BuscaPorCodigo(produtos,codigoBarras,posicao);
                        if(posicaoEncontrada == -1){
                            printf("Produto Nao Encontrado\n");
                        }
                        else{
                            printf("Caixa antes da compra: %f\n",caixa);
                            printf("PRODUTO ANTES DA COMPRA:\n");
                            ImprimirProduto(produtos,posicaoEncontrada);
                            if(ComprarProduto(produtos,&caixa,quant,posicaoEncontrada) == 1){
                                printf("\nPRODUTO DEPOIS DA COMPRA:\n");
                                ImprimirProduto(produtos,posicaoEncontrada);
                                printf("Caixa depois da compra: %f\n",caixa);

                            }
                        }
                        system("PAUSE");
                        break;
                    }
                    case 2:{
                        posicaoEncontrada = BuscaPorCodigo(produtos,codigoBarras,posicao);
                        if(posicaoEncontrada == -1){
                            printf("Produto Nao Encontrado\n");
                        }
                        else{
                            printf("Caixa antes da venda: %f\n",caixa);
                            printf("PRODUTO ANTES DA VENDA:\n");
                            ImprimirProduto(produtos,posicaoEncontrada);
                            if(VenderProduto(produtos,&caixa,quant,posicaoEncontrada) == 1){
                                printf("\nPRODUTO DEPOIS DA VENDA:\n");
                                ImprimirProduto(produtos,posicaoEncontrada);
                                printf("Caixa depois da venda: %f\n",caixa);
                            }
                        }
                        system("PAUSE");
                        break;
                    }
                }
            }

          }
        system("cls");
        printf("\tMENU PRINCIPAL\n\n");
        printf("\t1 - Cadastro de novo produto;\n");
        printf("\t2 - Busca de produto\n");
        printf("\t3 - Listagem de produtos\n");
        printf("\t4 - Controle de caixa\n");
        printf("\t5 - Sair\n");
        scanf("%d", &menuop);
    }
    return 0;
}

#include "Produto.h"


void CadastraProduto(Produto *produtos,Produto p,int posicao){
    produtos[posicao] = p;
}

int BuscaPorCodigo(Produto *produtos,int codigoBarras,int posicao){
    int i;
    int posicaoBuscado = -1;
    for(i=0;i<posicao;i++){
        if(strcmp(produtos[i].codigoProduto,codigoBarras) == 0 ){
            posicaoBuscado = i;
            return posicaoBuscado;
        }
    }
    return posicaoBuscado;
}

void ListarProdutos(Produto *produtos,int posicao){
    int i;
    for(i=0;i<posicao;i++){
        printf("==========================================\n");
        printf("Produto: %s \n",produtos[i].nomeProduto);
        printf("[Codigo de Barras]: %s \n",produtos[i].codigoProduto);
        printf("[Descricao]: %s \n",produtos[i].descricaoProduto);
        printf("[Valor de Compra]: %f \n",produtos[i].vCompraProduto);
        printf("[Valor de Venda]: %f \n",produtos[i].vVendaProduto);
        printf("[Quantidade]: %d \n",produtos[i].quantidadeProduto);
        printf("==========================================\n");
    }
}

void ImprimirProduto(Produto *produtos,int posicaoProduto){
    printf("==========================================\n");
    printf("Produto: %s \n",produtos[posicaoProduto].nomeProduto);
    printf("[Codigo de Barras]: %s \n",produtos[posicaoProduto].codigoProduto);
    printf("[Descricao]: %s \n",produtos[posicaoProduto].descricaoProduto);
    printf("[Valor de Compra]: %f \n",produtos[posicaoProduto].vCompraProduto);
    printf("[Valor de Venda]: %f \n",produtos[posicaoProduto].vVendaProduto);
    printf("[Quantidade]: %d \n",produtos[posicaoProduto].quantidadeProduto);
    printf("==========================================\n");
}

void AtualizaQuantidade(Produto *produtos, int posicaoProduto, int novaQuantidade){
    produtos[posicaoProduto].quantidadeProduto = novaQuantidade;
}

int ComprarProduto(Produto *produtos,float *caixa,int quantidade,int posicaoProduto){
    float valor = produtos[posicaoProduto].vCompraProduto * quantidade;
    if(valor > *caixa){
        printf("Nao ha dinheiro suficiente\n");
        return 0;
    }
    else{
        AtualizaQuantidade(produtos,posicaoProduto,produtos[posicaoProduto].quantidadeProduto+quantidade);
        *caixa = *caixa - valor;
        return 1;
    }
}

int VenderProduto(Produto *produtos,float *caixa,int quantidade,int posicaoProduto){
    float valor = produtos[posicaoProduto].vVendaProduto * quantidade;
    if(produtos[posicaoProduto].quantidadeProduto < quantidade){
        printf("Quantidade não suficiente\n");
        return 0;
    }

    else{
        AtualizaQuantidade(produtos,posicaoProduto,produtos[posicaoProduto].quantidadeProduto - quantidade);
        *caixa = *caixa + valor;
        return 1;
    }
}
