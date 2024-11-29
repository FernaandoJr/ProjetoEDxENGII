#include "lib/ListaDinamica.h"
#include "lib/ListaDuplamenteLigada.h"
#include "lib/ArvoreBinaria.h"
#include "lib/Extra.h"
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

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

/*
    PROJETO DE ESTRUTURA DE DADOS - CADASTRO DE LIVROS EM UMA BIBLIOTECA
    CURSO: 3º ADS NOITE

    INTEGRANTES DO GRUPO:
    - Fernando Divino
    - Luis Felipe Piasentini
    - Ian Camargo
    - Thaito Batalini

    INSTRUÇÕES PARA COMPILAR E EXECUTAR O PROJETO:

    Para compilar o projeto, utilize o seguinte comando no terminal:
    gcc -o FLIT main.c ./lib/ListaDinamica.c ./lib/Extra.c ./lib/ListaDuplamenteLigada.c ./lib/ArvoreBinaria.c

    Para executar o projeto, utilize o comando:
    ./FLIT (no Linux/Unix)
    FLIT (no Windows)
*/
int main()
{
    limparTela();
    int opcao = OP_NAO_SELECIONADA;

    while (opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao)
        {
        case OP_ADICIONAR:
            limparTela();
            adicionar_livro();
            break;
        case OP_ALTERAR:
            limparTela();
            alterar_livro();
            break;
        case OP_EXCLUIR:
            limparTela();
            char ISBN[20];
            printf(BLUE "Digite o ISBN do livro a excluir: " RESET);
            fgets(ISBN, sizeof(ISBN), stdin);
            ISBN[strcspn(ISBN, "\n")] = 0;
            excluir_livro(ISBN);
            break;
        case OP_BUSCAR:
            limparTela();
            buscar_livro();
            break;
        case OP_RELATORIO:
            limparTela();
            imprimirIndice();
            break;
        case OP_SAIR:
            printf("Saindo do programa...\n");
            liberarLista();
            liberarArvore(raizArvore);
            liberarIndice();
            break;
        default:
            limparTela();
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
