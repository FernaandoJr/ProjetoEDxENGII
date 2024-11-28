#include "ListaDuplamenteLigada.h"
#include "ArvoreBinaria.h"
#include <stdlib.h>
#include "Extra.h"
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Inicializa a lista duplamente ligada como vazia.
IndiceOrdenacao *inicioIndice = NULL;

/**
 * @brief Função auxiliar para criar um novo nó na lista duplamente ligada.
 *
 * @param nomeLivro Nome do livro a ser inserido.
 * @param registro Número do registro do livro.
 * @return Ponteiro para o novo nó criado.
 */
IndiceOrdenacao *criarNoIndice(const char *nomeLivro, int registro)
{
    // Aloca memória para um novo nó.
    IndiceOrdenacao *novoNo = (IndiceOrdenacao *)malloc(sizeof(IndiceOrdenacao));
    if (novoNo == NULL)
    {
        perror("Erro ao alocar memoria para no do indice");
        exit(EXIT_FAILURE);
    }
    // Copia o nome do livro para o novo nó.
    strcpy(novoNo->nomeLivro, nomeLivro);
    // Define o número do registro no novo nó.
    novoNo->registro = registro;
    // Inicializa os ponteiros anterior e próximo como NULL (novo nó).
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

/**
 * @brief Adiciona um novo nó à lista duplamente ligada, mantendo a ordenação pelo nome do livro.
 *
 * @param nomeLivro Nome do livro a ser inserido.
 * @param registro Número do registro do livro.
 */
void adicionarIndice(const char *nomeLivro, int registro)
{
    // Cria um novo nó com o nome do livro e o número do registro.
    IndiceOrdenacao *novoNo = criarNoIndice(nomeLivro, registro);
    // Ponteiros auxiliares para iterar na lista.
    IndiceOrdenacao *atual = inicioIndice;
    IndiceOrdenacao *anterior = NULL;

    // Itera pela lista até encontrar a posição correta para inserir o novo nó (ordenado).
    while (atual != NULL && strcmp(nomeLivro, atual->nomeLivro) > 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    // Liga o novo nó na lista.
    novoNo->proximo = atual;
    if (anterior == NULL)
    {
        inicioIndice = novoNo; // Novo nó se torna o início da lista.
    }
    else
    {
        anterior->proximo = novoNo;
    }
    if (atual != NULL)
    {
        atual->anterior = novoNo;
    }
    novoNo->anterior = anterior;
}

/**
 * @brief Atualiza o nome do livro em um nó específico da lista duplamente ligada, dado o registro.
 *
 * @param nomeAntigo Nome antigo do livro (não utilizado na função).
 * @param nomeNovo Novo nome do livro.
 * @param registro Número do registro do livro a ser atualizado.
 */
void atualizarIndice(const char *nomeAntigo, const char *nomeNovo, int registro)
{
    IndiceOrdenacao *atual = inicioIndice;

    // Itera pela lista procurando pelo nó com o registro especificado.
    while (atual != NULL)
    {
        if (atual->registro == registro)
        {
            // Atualiza o nome do livro no nó encontrado.
            strcpy(atual->nomeLivro, nomeNovo);
            return;
        }
        atual = atual->proximo;
    }
}

/**
 * @brief Imprime os dados da lista duplamente ligada formatados.
 */
void imprimirIndice()
{
    IndiceOrdenacao *atual = inicioIndice;

    // Verifica se a lista está vazia
    if (atual == NULL)
    {
        mensagemErro("Nenhum livro cadastrado.");
        return;
    }

    printf(BLUE "\n+=~-==========================================-~=+\n" RESET);
    printf(BLUE "|" WHITE "               LIVROS CADASTRADOS               " BLUE "|\n" RESET);
    printf(BLUE "+=~-==========================================-~=+\n" RESET);
    printf("\n");
    printf(YELLOW "|================================================|\n" RESET);
    printf(YELLOW "| " GREEN "%-30s" YELLOW " | " GREEN "%-13s" YELLOW " |\n" RESET, "Nome do Livro", "Registro");
    printf(YELLOW "|================================|===============|\n" RESET);

    // Itera pela lista imprimindo os dados de cada nó.
    while (atual != NULL)
    {
        printf(YELLOW "|" WHITE " %-30s " YELLOW "|" WHITE " %-13d " YELLOW "|\n" RESET, atual->nomeLivro, atual->registro);
        printf(YELLOW "|================================================|\n" RESET);
        atual = atual->proximo;
    }
}

/**
 * @brief Libera a memória alocada para a lista duplamente ligada.
 */
void liberarIndice()
{
    IndiceOrdenacao *atual = inicioIndice;
    IndiceOrdenacao *proximo;
    // Itera pela lista liberando a memória de cada nó.
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    inicioIndice = NULL;
}