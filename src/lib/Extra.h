#ifndef EXTRA_H
#define EXTRA_H

/**
 * @brief Exibe o menu principal do sistema.
 *
 * @return int A opção escolhida pelo usuário.
 */
int menu();

/**
 * @brief Limpa a tela do console.
 */
void limparTela();
/**
 * @brief Imprime uma mensagem de erro em vermelho.
 *
 * @param mensagem A mensagem de erro a ser impressa.
 */
void mensagemErro(const char *mensagem);

/**
 * @brief Imprime uma mensagem de sucesso em verde.
 *
 * @param mensagem A mensagem de sucesso a ser impressa.
 */
void mensagemSucesso(const char *mensagem);

/**
 * @brief Exibe uma mensagem de boas-vindas colorida e formatada.
 */
void exibirMensagemBoasVindas();

#endif // EXTRA_H