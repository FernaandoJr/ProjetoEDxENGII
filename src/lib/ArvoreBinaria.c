#include "ArvoreBinaria.h"
#include "Extra.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Inicializa a raiz da árvore binária como NULL (árvore vazia).
PK *raizArvore = NULL;

/**
 * @brief Função auxiliar para criar um novo nó (PK) na árvore binária.
 *
 * @param ISBN ISBN do livro.
 * @param registro Índice do livro na lista ligada.
 * @return Ponteiro para o novo nó criado.
 */
PK *criarPK(const char *ISBN, int registro)
{
    // Aloca memória para um novo nó.
    PK *novoNo = (PK *)malloc(sizeof(PK));
    if (novoNo == NULL)
    {
        perror("Erro ao alocar memoria para no da arvore");
        exit(EXIT_FAILURE);
    }
    // Copia o ISBN para o novo nó.
    strcpy(novoNo->ISBN, ISBN);
    // Define o número do registro no novo nó.
    novoNo->registro = registro;
    // Inicializa os ponteiros para os filhos como NULL (nó folha).
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

/**
 * @brief Insere um novo nó na árvore binária, mantendo a propriedade de árvore de busca binária.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param ISBN ISBN do livro a ser inserido.
 * @param registro Índice do livro na lista ligada.
 * @return Ponteiro para a raiz da árvore após a inserção.
 */
PK *inserirArvore(PK *raiz, const char *ISBN, int registro)
{
    // Se a árvore estiver vazia, cria um novo nó e o define como raiz.
    if (raiz == NULL)
    {
        return criarPK(ISBN, registro);
    }
    // Compara o ISBN a ser inserido com o ISBN do nó atual.
    int compara = strcmp(ISBN, raiz->ISBN);
    // Se o ISBN for menor, insere na subárvore esquerda.
    if (compara < 0)
    {
        raiz->esquerda = inserirArvore(raiz->esquerda, ISBN, registro);
    }
    // Se o ISBN for maior, insere na subárvore direita.
    else if (compara > 0)
    {
        raiz->direita = inserirArvore(raiz->direita, ISBN, registro);
    }
    return raiz; // Retorna a raiz (que pode ter sido modificada).
}

/**
 * @brief Busca um nó na árvore binária dado o ISBN.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param ISBN ISBN do livro a ser buscado.
 * @param registro Ponteiro para armazenar o índice do livro encontrado.
 * @return true se o livro for encontrado, false caso contrário.
 */
bool buscarArvore(PK *raiz, const char *ISBN, int *registro)
{
    // Se a árvore estiver vazia, o ISBN não foi encontrado.
    if (raiz == NULL)
    {
        return false;
    }
    // Compara o ISBN a ser buscado com o ISBN do nó atual.
    int compara = strcmp(ISBN, raiz->ISBN);
    // Se o ISBN for igual, o nó foi encontrado.
    if (compara == 0)
    {
        *registro = raiz->registro; // Define o registro encontrado.
        return true;                // Retorna true indicando que o nó foi encontrado.
    }
    // Se o ISBN for menor, busca na subárvore esquerda.
    else if (compara < 0)
    {
        return buscarArvore(raiz->esquerda, ISBN, registro);
    }
    // Se o ISBN for maior, busca na subárvore direita.
    else
    {
        return buscarArvore(raiz->direita, ISBN, registro);
    }
}

/**
 * @brief Remove um nó da árvore binária dado o ISBN.
 *
 * @param raiz Ponteiro para o ponteiro da raiz da árvore.
 * @param ISBN ISBN do livro a ser excluído.
 */
void excluirArvore(PK **raiz, const char *ISBN)
{
    // Se a árvore estiver vazia, não há nada para remover.
    if (*raiz == NULL)
        return;

    // Compara o ISBN a ser removido com o ISBN do nó atual.
    int compara = strcmp(ISBN, (*raiz)->ISBN);
    // Se o ISBN for menor, remove da subárvore esquerda.
    if (compara < 0)
    {
        excluirArvore(&(*raiz)->esquerda, ISBN);
    }
    // Se o ISBN for maior, remove da subárvore direita.
    else if (compara > 0)
    {
        excluirArvore(&(*raiz)->direita, ISBN);
    }
    // Se o ISBN for igual, o nó a ser removido foi encontrado.
    else
    {
        PK *noParaRemover = *raiz;
        // Se o nó for uma folha (sem filhos), remove diretamente.
        if (noParaRemover->esquerda == NULL)
        {
            *raiz = noParaRemover->direita;
        }
        // Se o nó tem apenas um filho à esquerda, o filho esquerdo se torna o novo nó.
        else if (noParaRemover->direita == NULL)
        {
            *raiz = noParaRemover->esquerda;
        }
        // Se o nó tem dois filhos, encontra o sucessor in-order (menor nó da subárvore direita).
        else
        {
            PK *sucessor = noParaRemover->direita;
            PK *paiSucessor = noParaRemover;
            // Procura pelo menor nó na subárvore direita (sucessor in-order).
            while (sucessor->esquerda != NULL)
            {
                paiSucessor = sucessor;
                sucessor = sucessor->esquerda;
            }
            // Copia os dados do sucessor para o nó a ser removido.
            strcpy(noParaRemover->ISBN, sucessor->ISBN);
            noParaRemover->registro = sucessor->registro;
            // Remove o sucessor (que agora é um nó folha ou com um filho).
            if (paiSucessor->esquerda == sucessor)
            {
                paiSucessor->esquerda = sucessor->direita;
            }
            else
            {
                paiSucessor->direita = sucessor->direita;
            }
            free(sucessor);
        }
        free(noParaRemover);
    }
}

/**
 * @brief Libera toda a memória alocada para a árvore binária.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 */
void liberarArvore(PK *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}