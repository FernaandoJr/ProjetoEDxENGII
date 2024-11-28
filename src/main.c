#include "lib/ListaDinamica.h"
#include "lib/ListaDuplamenteLigada.h"
#include "lib/ArvoreBinaria.h"
#include "lib/Extra.h"
#include <stdlib.h>
#include <time.h>

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
    gcc -o main main.c ./lib/ListaDinamica.c ./lib/Extra.c ./lib/ListaDuplamenteLigada.c ./lib/ArvoreBinaria.c

    Para executar o projeto, utilize o comando:
    ./main (no Linux/Unix)
    main (no Windows)
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
            printf("Digite o ISBN do livro a excluir: ");
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
