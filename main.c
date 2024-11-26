#include <stdio.h>
#include <string.h>

// Definindo a estrutura para os produtos
struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

// Função para adicionar produto
void adicionarProduto(struct Produto produtos[], int *contador) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", produtos[*contador].nome);  // Lê o nome do produto com espaços
    printf("Digite a quantidade do produto: ");
    scanf("%d", &produtos[*contador].quantidade);
    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[*contador].preco);

    (*contador)++;  // Incrementa o contador de produtos
    printf("Produto adicionado com sucesso!\n\n");
}

// Função para consultar o estoque
void consultarEstoque(struct Produto produtos[], int contador) {
    if (contador == 0) {
        printf("Estoque vazio!\n\n");
        return;
    }

    printf("\nEstoque de produtos:\n");
    for (int i = 0; i < contador; i++) {
        printf("Produto: %s | Quantidade: %d | Preço: %.2f\n", 
                produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
    printf("\n");
}

// Função para vender produto
void venderProduto(struct Produto produtos[], int *contador) {
    char nomeProduto[50];
    int quantidade;
    int encontrado = 0;

    printf("Digite o nome do produto a ser vendido: ");
    scanf(" %[^\n]s", nomeProduto);
    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < *contador; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            if (produtos[i].quantidade >= quantidade) {
                produtos[i].quantidade -= quantidade;
                printf("Venda realizada com sucesso! %d unidades de %s vendidas.\n\n", quantidade, nomeProduto);
            } else {
                printf("Erro: Quantidade solicitada maior que a disponível no estoque!\n\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado no estoque!\n\n");
    }
}

int main() {
    struct Produto produtos[100];  // Lista de produtos
    int contador = 0;  // Contador de produtos cadastrados
    int opcao;

    do {
        // Exibe o menu para o usuário
        printf("----- Menu Principal -----\n");
        printf("1. Adicionar produto\n");
        printf("2. Consultar estoque\n");
        printf("3. Vender produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, &contador);
                break;
            case 2:
                consultarEstoque(produtos, contador);
                break;
            case 3:
                venderProduto(produtos, &contador);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n\n");
        }

    } while (opcao != 4);

    return 0;
}
