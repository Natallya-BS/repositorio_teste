#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definindo a estrutura para armazenar os dados do produto
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Funções declaradas
void adicionarProduto(Produto estoque[], int *quantidadeProdutos);
void consultarEstoque(Produto estoque[], int quantidadeProdutos);
void venderProduto(Produto estoque[], int *quantidadeProdutos);

int main() {
    Produto estoque[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
    int opcao;

    while (1) {
        printf("\nMenu de Gerenciamento de Estoque\n");
        printf("1. Adicionar produto\n");
        printf("2. Consultar estoque\n");
        printf("3. Vender produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &quantidadeProdutos);
                break;
            case 2:
                consultarEstoque(estoque, quantidadeProdutos);
                break;
            case 3:
                venderProduto(estoque, &quantidadeProdutos);
                break;
            case 4:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}
