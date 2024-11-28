#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <stdbool.h>
#include <string.h>

/**
 * @file ArvoreBinaria.h
 * @brief Declarações das funções e estruturas para manipulação de uma árvore binária.
 */

/**
 * @brief Estrutura que representa um nó na árvore binária.
 *
 * Cada nó representa um livro, usando o ISBN como chave.
 */
typedef struct PK
{
    char ISBN[20];       /**< ISBN do livro (chave primária). */
    int registro;        /**< Índice do livro na lista ligada. */
    struct PK *esquerda; /**< Ponteiro para o filho esquerdo. */
    struct PK *direita;  /**< Ponteiro para o filho direito. */
} PK;

/**
 * @brief Declaração da variável global que aponta para a raiz da árvore binária.
 */
extern PK *raizArvore;

/**
 * @brief Cria um novo nó na árvore binária.
 *
 * @param ISBN ISBN do livro.
 * @param registro Índice do livro na lista ligada.
 * @return Ponteiro para o novo nó criado.
 */
PK *criarPK(const char *ISBN, int registro);

/**
 * @brief Insere um novo nó na árvore binária.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param ISBN ISBN do livro a ser inserido.
 * @param registro Índice do livro na lista ligada.
 * @return Ponteiro para a raiz da árvore após a inserção.
 */
PK *inserirArvore(PK *raiz, const char *ISBN, int registro);

/**
 * @brief Busca um nó na árvore binária.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param ISBN ISBN do livro a ser buscado.
 * @param registro Ponteiro para armazenar o índice do livro encontrado.
 * @return true se o livro for encontrado, false caso contrário.
 */
bool buscarArvore(PK *raiz, const char *ISBN, int *registro);

/**
 * @brief Exclui um nó da árvore binária.
 *
 * @param raiz Ponteiro para o ponteiro da raiz da árvore.
 * @param ISBN ISBN do livro a ser excluído.
 */
void excluirArvore(PK **raiz, const char *ISBN);

/**
 * @brief Libera a memória alocada para a árvore binária.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 */
void liberarArvore(PK *raiz);

#endif // ARVOREBINARIA_H