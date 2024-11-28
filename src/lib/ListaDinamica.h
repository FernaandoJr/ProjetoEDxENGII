#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @file ListaDinamica.h
 * @brief Declarações das funções e estruturas para manipulação de uma lista ligada dinâmica.
 */

/**
 * @brief Estrutura que representa um livro na lista ligada.
 */
typedef struct livroDB
{
    char autor[100];         /**< Nome do autor (string, max 100 caracteres). */
    char nome_livro[200];    /**< Título do livro (string, max 200 caracteres). */
    char editora[50];        /**< Nome da editora (string, max 50 caracteres). */
    char ISBN[20];           /**< Número ISBN (string, max 20 caracteres). */
    char ano[6];             /**< Ano de publicação (string, max 6 caracteres). */
    char genero[50];         /**< Gênero do livro (string, max 50 caracteres). */
    struct livroDB *proximo; /**< Ponteiro para o próximo livro na lista ligada. */
} livroDB;

/**
 * @brief Inicializa a lista ligada dinâmica.
 */
void inicializarLista();
/**
 * @brief Insere um novo livro na lista ligada dinâmica.
 *
 * @param ISBN Número ISBN do livro.
 * @param autor Nome do autor do livro.
 * @param nome_livro Título do livro.
 * @param editora Nome da editora do livro.
 * @param ano Ano de publicação do livro.
 * @param genero Gênero do livro.
 */
void inserirLivro(const char *ISBN, const char *autor, const char *nome_livro, const char *editora, const char *ano, const char *genero);

/**
 * @brief Remove um livro da lista ligada dinâmica.
 *
 * @param ISBN Número ISBN do livro a ser removido.
 */
void removerLivro(const char *ISBN);

/**
 * @brief Busca um livro na lista ligada dinâmica.
 */
void buscar_livro();

/**
 * @brief Adiciona um novo livro na lista ligada dinâmica.
 */
void adicionar_livro();

/**
 * @brief Altera os dados de um livro na lista ligada dinâmica.
 */
void alterar_livro();

/**
 * @brief Exclui um livro da lista ligada dinâmica.
 */
void excluir_livro();

/**
 * @brief Adiciona um índice para facilitar a busca de livros.
 */
void adicionarIndice();

/**
 * @brief Busca um livro na lista ligada dinâmica.
 *
 * @param ISBN Número ISBN do livro a ser buscado.
 * @return Ponteiro para o livro encontrado ou NULL se não encontrado.
 */
livroDB *buscarLivro(const char *ISBN);

/**
 * @brief Imprime os dados de todos os livros na lista ligada dinâmica.
 */
void imprimirLivros();

/**
 * @brief Libera a memória alocada para a lista ligada dinâmica.
 */
void liberarLista();

#endif // LISTALIGADA_H