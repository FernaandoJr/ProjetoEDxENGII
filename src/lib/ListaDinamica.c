#include "ListaDinamica.h"
#include "ArvoreBinaria.h"
#include "ListaDuplamenteLigada.h"
#include "Extra.h"
#include <stdlib.h>
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

// Variável global que aponta para o início da lista ligada. Inicializada como NULL (lista vazia).
livroDB *inicioLista = NULL;
// Variável global para controlar o número do próximo registro.
static int ultimoRegistro = 0;

/**
 * @brief Cria um novo nó (livro) na lista ligada.
 *
 * @param ISBN O ISBN do livro.
 * @param autor O autor do livro.
 * @param nome_livro O nome do livro.
 * @param editora A editora do livro.
 * @param ano O ano de publicação do livro.
 * @param genero O gênero do livro.
 * @return livroDB* Ponteiro para o novo nó criado.
 */
livroDB *criarLivro(const char *ISBN, const char *autor, const char *nome_livro, const char *editora, const char *ano, const char *genero)
{
    // Alocação de memória para um novo livro.
    livroDB *novoLivro = (livroDB *)malloc(sizeof(livroDB));
    if (novoLivro == NULL)
    {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    // Copia as informações do livro para o novo nó.
    strcpy(novoLivro->ISBN, ISBN);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->nome_livro, nome_livro);
    strcpy(novoLivro->editora, editora);
    strcpy(novoLivro->ano, ano);
    strcpy(novoLivro->genero, genero);
    novoLivro->proximo = NULL; // O próximo livro é NULL (fim da lista).
    return novoLivro;
}

/**
 * @brief Insere um novo livro na lista ligada, mantendo a ordem por ISBN.
 *
 * @param novo Ponteiro para o novo livro a ser inserido.
 */
void inserirOrdenado(livroDB *novo)
{
    livroDB *anterior = NULL;
    livroDB *atual = inicioLista;

    // Itera pela lista até encontrar a posição correta para inserir o novo livro (ordenado por ISBN).
    while (atual != NULL && strcmp(novo->ISBN, atual->ISBN) > 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    // Liga o novo livro na lista.
    novo->proximo = atual;
    if (anterior == NULL)
    {
        inicioLista = novo; // Novo livro se torna o início da lista.
    }
    else
    {
        anterior->proximo = novo;
    }
}

/**
 * @brief Adiciona um novo livro ao sistema.
 */
void adicionar_livro()
{
    char ISBN[20], autor[100], nome_livro[200], editora[50], ano[6], genero[50];
    // Lê as informações do livro do usuário.
    printf(BLUE "Digite o ISBN do livro: " RESET);
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = 0;

    int registro;
    // Busca o ISBN na árvore para verificar se já existe.
    if (buscarArvore(raizArvore, ISBN, &registro))
    {
        mensagemErro("ISBN já cadastrado.");
        return;
    }
    printf(BLUE "Digite o autor do livro: " RESET);
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = 0;

    printf(BLUE "Digite o nome do livro: " RESET);
    fgets(nome_livro, sizeof(nome_livro), stdin);
    nome_livro[strcspn(nome_livro, "\n")] = 0;

    printf(BLUE "Digite a editora do livro: " RESET);
    fgets(editora, sizeof(editora), stdin);
    editora[strcspn(editora, "\n")] = 0;

    printf(BLUE "Digite o ano de publicacao do livro: " RESET);
    fgets(ano, sizeof(ano), stdin);
    ano[strcspn(ano, "\n")] = 0;

    printf(BLUE "Digite o genero do livro: " RESET);
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = 0;

    // Cria um novo livro usando a função auxiliar.
    livroDB *novoLivro = criarLivro(ISBN, autor, nome_livro, editora, ano, genero);
    // Insere o novo livro na lista ligada.
    inserirOrdenado(novoLivro);
    // Incrementa o contador de registros.
    ultimoRegistro++;
    // Adiciona o livro ao índice de ordenação.
    adicionarIndice(nome_livro, ultimoRegistro);
    // Adiciona o livro à árvore binária.
    raizArvore = inserirArvore(raizArvore, ISBN, ultimoRegistro);
    system("cls");
    mensagemSucesso("\nLivro cadastrado com sucesso!");
}

/**
 * @brief Exclui um livro do sistema dado o ISBN.
 *
 * @param ISBN O ISBN do livro a ser excluído.
 */
void excluir_livro(const char *ISBN)
{
    int registro;
    // Verifica se o livro existe na árvore binária antes de tentar excluí-lo.
    if (!buscarArvore(raizArvore, ISBN, &registro))
    {
        system("cls");
        mensagemErro("Livro nao encontrado.");
        return;
    }
    livroDB *anterior = NULL;
    livroDB *atual = inicioLista;

    // Procura pelo livro na lista ligada.
    while (atual != NULL && strcmp(atual->ISBN, ISBN) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        system("cls");
        mensagemErro("Livro nao encontrado.");
        return;
    }

    // Remove o livro da lista ligada.
    if (anterior == NULL)
    {
        inicioLista = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    // Remove o livro da árvore binária.
    excluirArvore(&raizArvore, ISBN);

    free(atual);
    system("cls");
    mensagemSucesso("Livro excluído com sucesso!");
}

/**
 * @brief Libera toda a memória alocada para a lista ligada.
 */
void liberarLista()
{
    livroDB *atual = inicioLista;
    livroDB *proximo;
    // Itera pela lista liberando a memória de cada nó.
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    inicioLista = NULL;
}

/**
 * @brief Imprime os dados de todos os livros na lista ligada em formato vertical.
 */
void imprimirLista()
{
    livroDB *atual = inicioLista;
    printf("\nRelatório de Livros:\n");

    if (atual == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Itera pela lista imprimindo as informações de cada livro.
    while (atual != NULL)
    {
        printf("---------------------\n");
        printf("ISBN:       %s\n", atual->ISBN);
        printf("Nome:       %s\n", atual->nome_livro);
        printf("Autor:      %s\n", atual->autor);
        printf("Editora:    %s\n", atual->editora);
        printf("Ano:        %s\n", atual->ano);
        printf("Genero:     %s\n", atual->genero);
        printf("---------------------\n");
        atual = atual->proximo;
        printf("\n");
    }
}

/**
 * @brief Altera as informações de um livro existente.
 */
void alterar_livro()
{
    char ISBN[20];
    printf(YELLOW "Digite o ISBN do livro a alterar: " RESET);
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = 0;

    int registro;
    // Verifica se o livro existe na árvore binária antes de tentar alterá-lo.
    if (!buscarArvore(raizArvore, ISBN, &registro))
    {
        limparTela();
        mensagemErro("Livro nao encontrado.");
        return;
    }

    livroDB *atual = inicioLista;
    // Procura pelo livro na lista ligada.
    while (atual != NULL && strcmp(atual->ISBN, ISBN) != 0)
    {
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        limparTela();
        mensagemErro("Livro nao encontrado.");
        return;
    }

    char buffer[100];

    printf(YELLOW "Digite o novo nome do livro " RED "(ou pressione Enter para manter o atual)" YELLOW ": " RESET);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0)
    {
        strcpy(atual->nome_livro, buffer);
    }

    printf(YELLOW "Digite o novo autor do livro " RED "(ou pressione Enter para manter o atual)" YELLOW ": " RESET);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0)
    {
        strcpy(atual->autor, buffer);
    }

    printf(YELLOW "Digite a nova editora do livro " RED "(ou pressione Enter para manter a atual)" YELLOW ": " RESET);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0)
    {
        strcpy(atual->editora, buffer);
    }

    printf(YELLOW "Digite o novo ano do livro " RED "(ou pressione Enter para manter o atual)" YELLOW ": " RESET);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0)
    {
        strcpy(atual->ano, buffer);
    }

    printf(YELLOW "Digite o novo genero do livro " RED "(ou pressione Enter para manter o atual)" YELLOW ": " RESET);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0)
    {
        strcpy(atual->genero, buffer);
    }

    printf(GREEN "Livro alterado com sucesso!\n" RESET);
}

/**
 * @brief Busca um livro na lista ligada dado o ISBN.
 */
void buscar_livro()
{
    char ISBN[20];
    printf("Digite o ISBN do livro a buscar: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = 0;

    int registro;
    // Verifica se o livro existe na árvore binária antes de tentar buscá-lo.
    if (!buscarArvore(raizArvore, ISBN, &registro))
    {
        system("cls");
        mensagemErro("Livro nao encontrado.");
        return;
    }
    livroDB *atual = inicioLista;
    // Procura pelo livro na lista ligada.
    while (atual != NULL && strcmp(atual->ISBN, ISBN) != 0)
    {
        atual = atual->proximo;
    }
    limparTela();
    printf(YELLOW "+===================+================================+\n" RESET);
    printf(YELLOW "| " GREEN "Campo" YELLOW "             | " GREEN "Detalhe " YELLOW "                       |\n" RESET);
    printf(YELLOW "+===================+================================+\n" RESET);
    printf(YELLOW "| " WHITE "ISBN" YELLOW "              | " CYAN "%-30s" YELLOW " |\n" RESET, atual->ISBN);
    printf(YELLOW "| " WHITE "Autor" YELLOW "             | " CYAN "%-30s" YELLOW " |\n" RESET, atual->autor);
    printf(YELLOW "| " WHITE "Nome do livro" YELLOW "     | " CYAN "%-30s" YELLOW " |\n" RESET, atual->nome_livro);
    printf(YELLOW "| " WHITE "Editora" YELLOW "           | " CYAN "%-30s" YELLOW " |\n" RESET, atual->editora);
    printf(YELLOW "| " WHITE "Ano" YELLOW "               | " CYAN "%-30s" YELLOW " |\n" RESET, atual->ano);
    printf(YELLOW "| " WHITE "Genero" YELLOW "            | " CYAN "%-30s" YELLOW " |\n" RESET, atual->genero);
    printf(YELLOW "+====================+===============================+\n" RESET);
}