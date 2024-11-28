#ifndef LISTADUPLAMENTELIGADA_H
#define LISTADUPLAMENTELIGADA_H

/**
 * @file ListaDuplamenteLigada.h
 * @brief Declarações das funções e estruturas para manipulação de uma lista duplamente ligada.
 */

/**
 * @brief Estrutura que representa um nó da lista duplamente ligada.
 */
typedef struct IndiceOrdenacao
{
    char nomeLivro[100];              /**< Nome do livro. */
    int registro;                     /**< Número do registro do livro. */
    struct IndiceOrdenacao *proximo;  /**< Ponteiro para o próximo nó da lista. */
    struct IndiceOrdenacao *anterior; /**< Ponteiro para o nó anterior da lista. */
} IndiceOrdenacao;

/**
 * @brief Inicializa a lista duplamente ligada.
 */
void inicializarLista();

/**
 * @brief Insere um novo nó na lista duplamente ligada.
 *
 * @param nomeLivro Nome do livro a ser inserido.
 * @param registro Número do registro do livro a ser inserido.
 */
void inserirNo(const char *nomeLivro, int registro);

/**
 * @brief Remove um nó da lista duplamente ligada.
 *
 * @param registro Número do registro do livro a ser removido.
 */
void removerNo(int registro);

/**
 * @brief Busca um nó na lista duplamente ligada.
 *
 * @param registro Número do registro do livro a ser buscado.
 * @return Ponteiro para o nó encontrado ou NULL se não encontrado.
 */
IndiceOrdenacao *buscarNo(int registro);

/**
 * @brief Imprime os dados da lista duplamente ligada.
 */
void imprimirIndice();

/**
 * @brief Libera a memória alocada para a lista duplamente ligada.
 */
void liberarIndice();

#endif // LISTADUPLAMENTELIGADA_H