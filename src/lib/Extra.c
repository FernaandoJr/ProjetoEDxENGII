#include "Extra.h"
#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Enumeração para as opções do menu
enum
{
    OP_NAO_SELECIONADA,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_BUSCAR,
    OP_RELATORIO,
    OP_SAIR,
};

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("\n" YELLOW "+=~-          MENU           -~=+\n" RESET);
    printf(YELLOW "|===============================|\n" RESET);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Cadastrar novo livro.\t" YELLOW "|\n" RESET, OP_ADICIONAR);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Alterar livro existente.\t" YELLOW "|\n" RESET, OP_ALTERAR);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Excluir livro cadastrado.\t" YELLOW "|\n" RESET, OP_EXCLUIR);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Buscar livro.\t\t" YELLOW "|\n" RESET, OP_BUSCAR);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Gerar Relatorio de livros.\t" YELLOW "|\n" RESET, OP_RELATORIO);
    printf(YELLOW "| " GREEN "%d" YELLOW ". " WHITE "Sair.\t\t\t" YELLOW "|\n" RESET, OP_SAIR);
    printf(YELLOW "|===============================|\n" RESET);
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    getchar(); // Limpa o buffer do teclado
    return op;
}

void limparTela()
{
#ifdef _WIN32
    system("cls"); // Comando para limpar a tela no Windows
#elif defined(__linux__) || defined(__APPLE__)
    system("clear"); // Comando para limpar a tela no Linux/Unix/MacOS
#else
    printf("Plataforma não suportada para limpar a tela.\n");
#endif
}

void mensagemErro(const char *mensagem)
{
    printf(RED "%s\n" RESET, mensagem);
}

void mensagemSucesso(const char *mensagem)
{
    printf(GREEN "%s\n" RESET, mensagem);
}

void exibirMensagemBoasVindas()
{
    printf("\n");
    printf(BLUE "***************************************************\n" RESET);
    printf(BLUE "* " RESET GREEN "Bem vindo ao " RESET RED "FLIT" RESET GREEN " | " RESET CYAN "Fast Literaly Indexing Tool" RESET BLUE " *\n" RESET);
    printf(BLUE "***************************************************\n" RESET);
}