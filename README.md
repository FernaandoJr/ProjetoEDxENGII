# Projeto: Fast Literary Indexing Tool (FLIT)

![Badge](http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge)

## 💼 Informações sobre o Trabalho

**Faculdade de Tecnologia de Mogi Mirim**

**Curso:** Análise e Desenvolvimento de Sistemas (Noturno)

**Matérias:**

-   🧑🏻‍💻 Estrutura de Dados
-   🖥️ Engenharia de Software II

**Professores:**

-   👨🏻‍🏫 Marcos Roberto Nava (Nava)
-   👩🏻‍🏫 Ana Celia Ribeiro Bizigato Portes

**Autores:**

-   **Fernando Divino** - [@FernaandoJr](https://github.com/FernaandoJr)
-   **Ian Camargo** - [@IanCamargo](https://github.com/IanCamargo)
-   **Luis Piasentini** - [@LuisPiasentini](https://github.com/LuisPiasentini)
-   **Thaito Batalini** - [@thaitoGB](https://github.com/thaitoGB)

# &#128214; Índice

-   [Como Executar o Código](#Visão-do-Produto)
-   [Visão do Produto](#Visão-do-Produto)
-   [Tecnologias Utilizadas](#Tecnologias-Utilizadas)
-   [Problemas e Soluções](#Problemas-e-Soluções)
-   [Product Backlog](#Product-Backlog)
-   [Diagrama de Casos de Uso](#Diagrama-de-Casos-de-Uso)
-   [Fluxo de Eventos](#Fluxo-de-Eventos)
    -   [Fluxo Básico](#Fluxo-Básico)
    -   [Fluxo Alternativo](#Fluxo-Alternativo)
-   [Diagrama de Atividades](#Diagrama-de-Atividades)
-   [Guia do Usuário](#Guia-do-Usuário)
-   [Conclusão](#conclusão)
-   [Agradecimentos](#agradecimentos)

-   # 🚀 Como Executar o Código

## Pré-requisitos

Antes de começar, certifique-se de ter as seguintes ferramentas instaladas:

-   [GCC](https://gcc.gnu.org/) ou outro compilador C

## Passos para Compilar e Executar

1. Clone o repositório:

    ```sh
    git clone https://github.com/FernaandoJr/projeto-flit.git
    cd projeto-flit
    ```

2. Compile o código:

    ```sh
    gcc -o flit main.c ./lib/ListaDinamica.c ./lib/Extra.c ./lib/ListaDuplamenteLigada.c ./lib/ArvoreBinaria.c
    ```

3. Execute o programa:

    ```sh
    ./flit
    ```

    Pronto! Agora você deve conseguir compilar e executar o código do FLIT.

# 🌟 Visão do Produto

-   **Propósito:** FLIT é projetado para resolver a necessidade de organização e gerenciamento de acervos literários em bibliotecas de pequeno e médio porte, facilitando o cadastro, busca e listagem de livros.
-   **Público-Alvo:** Bibliotecas públicas e privadas, escolas e universidades que precisam de uma solução leve e eficiente para gerenciar seus livros.
-   **Diferenciais:** O uso de estruturas de dados como árvores binárias e listas duplamente ligadas garante uma busca rápida e eficiente, além de uma ordenação simplificada dos livros.
-   **Objetivo Estratégico:** Tornar-se uma ferramenta de referência para gestão de acervos literários em pequenas instituições, com potencial de expansão para uma solução mais robusta.
-   **Escopo Geral:** Permitir o cadastro de livros com informações como ISBN, título, autor, e outras características, além de funcionalidades de busca, alteração, exclusão e relatórios.

# 🔗 Tecnologias Utilizadas

-   Linguagem C
-   CLion

# ❓ Problemas e Soluções

## Problema:

-   Interar entre as posições de memória para armazenar ou encontrar dados previamente armazenados.

## Solução:

-   Implementar uma lógica de loop que percorra os endereços por ponteiro até encontrar um endereço NULL.

# 📋 Product Backlog

| Prioridade |           Título            |                               Descrição                                |                                                                                                         Detalhamento                                                                                                         | Estimimativa |                                                                                                                                                                                              Critério de Aceite                                                                                                                                                                                              |
| :--------: | :-------------------------: | :--------------------------------------------------------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :----------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|    100     |      Cadastro de Livro      |            Permitir o cadastro de um novo livro no sistema             |      O sistema solicita o ISBN, título, autor quantidade de páginas, país de origem e gênero. Após a verificação da unicidade do ISBN, os dados são salvos na lista dinâminca, árvore binária e lista duplamente ligada      |      5       |                                                           1- Todos os campos obrigatórios devem ser preenchidos. 2- O ISBN deve ser único e validado antes do cadastro. 3- Os dados devem ser salvos nas estruturas (lista dinâmica, árvore binária e lista duplamente ligada). 4- Exibir mensagem de sucesso ou erro apropriada após o processo.                                                            |
|     95     | Alteração de Dados de Livro |  Permitir a alteração dos dados de um livro existente, exceto o ISBN   |        O sistema solicita ISBN para localizar o livro. Caso encontrado, o usuário pode atualizar os dados do livro, como título, autor, quantidade de páginas, país de origem e gênero. O ISBN não pode ser alterado         |      8       |                              1- O sistema deve permitir a busca do livro pelo ISBN. 2- Apenas livros existentes podem ser alterados. 3- O sistema deve permitir a modificação de qualquer campo, exceto o ISBN. 4- As alterações devem ser refletidas em todas as estruturas de dados. 5- Exibir mensagem de confirmação após a alteração ou mensagem de erro em caso de falha.                              |
|     90     |      Exclusão de Livro      |               Permitir a exclusão de um livro pelo ISBN                | O sistema solicita o ISBN para localizar o livro. Se o livreo for encontrado, ele será removido da lista dinâmica, árvore binária e lista duplamente ligada. Se o ISBN não for encontrado, uma mensagem de erro será exibida |      5       |                           1- O sistema deve permitir a busca do livro pelo ISBN antes da exclusão. 2- Apenas livros existentes podem ser excluídos. 3- A exclusão deve remover o livro de todas as estruturas de dados (lista dinâmica, árvore binária e lista duplamente ligada). 4- Exibir mensagem de confirmação após a exclusão ou de erro caso o livro não seja encontrado.                            |
|     85     |       Busca de Livro        |                  Permitir a busca de livros pelo ISBN                  |                       O sistema solicita o ISBN para buscar o livro. Se o livro for encontrado, suas informações detalhadas serão exibidas. Se não encontrado, o sistema exibirá uma mensagem de erro                        |      13      | 1- O sistema deve permitir a busca de um livro pelo ISBN, título ou autor. 2- O resultado deve exibir todos os dados do livro encontrado. 3- Caso nenhum livro seja encontrado, o sistema deve exibir uma mensagem informando que não há resultados para a busca. 4- A busca deve ser eficiente, consultando as estruturas de dados apropriadas (lista dinâmica, árvore binária ou lista duplamente ligada). |
|     80     |    Geração de Relatório     | Gerar relatório com a listagem de todos os livros, ordenados pelo nome |                        O sistema deve gerar um relatório completo dos livros registrados, ordenados por nome (ou outro critério). O relatório pode ser impresso ou exportado para um arquivo de texto                        |      13      |                                      1- O sistema deve permitir a geração de relatórios com todos os livros cadastrados, exibindo ISBN, título, autor, quantidade de páginas, país de origem e gênero. 2- O relatório deve ser organizado e paginado, se necessário. 3- Em caso de ausência de dados para o relatório, o sistema deve exibir uma mensagem informativa.                                       |

# 📊 Diagrama de Casos de Uso

![image](https://github.com/user-attachments/assets/9ef3624e-0c33-46e2-b118-fbbe1bdf5ade)

# 📊 Descrição do Diagrama de Casos de Uso

## 🔀 Fluxo Básico

### 1. Caso de Uso: Cadastrar Livro

-   Ator: Bibliotecário

1.  O Bibliotecário solicita o cadastro de um novo livro.
2.  O Sistema solicita os detalhes do livro (ISBN, nome, autor etc.).
3.  O Bibliotecário insere os detalhes.
4.  O Sistema verifica se o ISBN já está cadastrado.
5.  O Sistema informa que o ISBN é único e cadastra o livro.
6.  O Bibliotecário recebe a confirmação de que o livro foi cadastrado com sucesso.

### 2. Caso de Uso: Alterar Cadastro de Livros

-   Ator: Bibliotecário

1. O Bibliotecário solicita a alteração dos dados de um livro específico.
2. O sistema solicita o ISBN do livro a ser alterado.
3. O Bibliotecário insere o ISBN.
4. O sistema verifica se o ISBN está registrado.
5. O sistema informa que o livro foi encontrado e exibe os dados atuais.
6. O Bibliotecário modifica os dados desejados (exceto o ISBN).
7. O sistema atualiza o cadastro com as novas informações.
8. O Bibliotecário recebe a confirmação de que as alterações foram realizadas com sucesso.

### 3. Caso de Uso: Excluir Livro

-   Ator: Bibliotecário

1. O Bibliotecário solicita a exclusão de um livro.
2. O sistema solicita o ISBN do livro a ser excluído.
3. O Bibliotecário insere o ISBN.
4. O sistema verifica se o livro está cadastrado.
5. O sistema informa que o livro foi encontrado.
6. O Bibliotecário confirma a exclusão do livro.
7. O sistema remove o livro do cadastro e atualiza as estruturas de indexação.
8. O Bibliotecário recebe a confirmação de que o livro foi excluído.

### 4. Caso de Uso: Buscar Livro

-   Ator: Bibliotecário

1. O Bibliotecário solicita a busca de um livro pelo ISBN.
2. O sistema solicita o ISBN do livro.
3. O Bibliotecário insere o ISBN.
4. O sistema verifica se o ISBN está cadastrado.
5. O sistema exibe os dados completos do livro, caso encontrado.
6. O Bibliotecário visualiza as informações do livro.

### 5. Caso de Uso: Gerar Relatório

-   Ator: Bibliotecário

1. O Bibliotecário solicita a geração de um relatório de todos os livros cadastrados.
2. O sistema processa os dados e organiza os livros de forma ordenada.
3. O sistema gera o relatório.
4. O Bibliotecário visualiza o relatório detalhado dos livros cadastrados.

### 6. Caso de Uso: Checar se já cadastrado (uso incluído em outros casos)

-   Ator: Bibliotecário

1. O sistema automaticamente verifica se o ISBN informado está cadastrado em operações de cadastro e alteração.
2. O Bibliotecário é informado caso o ISBN já esteja registrado, impedindo a duplicidade.
3. O Bibliotecário recebe a instrução de corrigir a entrada caso seja necessário.

## ⚠️ Fluxo Alternativo

### 1.1 Fluxo Alternativo: ISBN já cadastrado

5. 1 - O Sistema informa que o ISBN já existe no cadastro.
6. 2 - O Sistema aborta o cadastro e exibe mensagem de erro.

### 2.1 Fluxo Alternativo: ISBN inexistente

5. 1 - O sistema informa que o ISBN não está cadastrado.
6. 2 - O Bibliotecário pode tentar novamente com outro ISBN ou cancelar a operação.

### 3.1 Fluxo Alternativo: ISBN inexistente

4. 1 - O sistema informa que o ISBN não está cadastrado.
5. 2 - O Bibliotecário pode tentar novamente com outro ISBN ou cancelar a operação.

### 4.1 Fluxo Alternativo: ISBN inexistente

5. 1 - O sistema informa que o ISBN não está cadastrado.
6. 2 - O Bibliotecário pode tentar novamente com outro ISBN ou encerrar a operação.

### 5.1 Fluxo Alternativo: Nenhum livro cadastrado

2. 1 - O sistema tenta acessar os dados de livros cadastrados.
3. 2 - O sistema informa que não há livros cadastrados.
4. 3 - O Bibliotecário encerra a operação ou aguarda novos cadastros.

### 6.1 Fluxo Alternativo: Problema de verificação

1. 1 - O sistema encontra um erro de validação ou conexão.
1. 2 - O sistema informa que a verificação falhou temporariamente.
1. 1 - O ator pode tentar novamente ou encerrar a operação.

# 🔄 Fluxo de Eventos  

## 🔀 Fluxo Básico  
1. 🖥️ **O Sistema inicia** e mostra o Menu de Opções.  
2. 📚 **O Bibliotecário seleciona** o cadastro de um novo livro.  
3. 📝 **O Sistema solicita** os detalhes do livro (ISBN, nome, autor, etc.).  
4. 🖊️ **O Bibliotecário insere** os detalhes.  
5. 🔍 **O Sistema verifica** se o ISBN já está cadastrado.  
6. ✅ **O Sistema informa** que o ISBN é único e cadastra o livro.  
7. 🎉 **O Bibliotecário recebe** a confirmação de que o livro foi cadastrado com sucesso.  
8. 🔄 **O Sistema retorna** para o Menu de Opções.  
9. 🛠️ **O Bibliotecário seleciona** a alteração dos dados de um livro específico.  
10. 🏷️ **O Sistema solicita** o ISBN do livro a ser alterado.  
11. 🖊️ **O Bibliotecário insere** o ISBN.  
12. 🔍 **O Sistema verifica** se o ISBN está registrado.  
13. 📑 **O Sistema informa** que o livro foi encontrado e exibe os dados atuais.  
14. 🖊️ **O Bibliotecário modifica** os dados desejados (exceto o ISBN).  
15. 🖥️ **O Sistema atualiza** o cadastro com as novas informações.  
16. 🎉 **O Bibliotecário recebe** a confirmação de que as alterações foram realizadas com sucesso.  
17. 🔄 **O Sistema retorna** para o Menu de Opções.  
18. 🗑️ **O Bibliotecário seleciona** a exclusão de um livro.  
19. 🏷️ **O Sistema solicita** o ISBN do livro a ser excluído.  
20. 🖊️ **O Bibliotecário insere** o ISBN.  
21. 🔍 **O Sistema verifica** se o livro está cadastrado.  
22. ✅ **O Sistema informa** que o livro foi encontrado.  
23. 🗑️ **O Bibliotecário confirma** a exclusão do livro.  
24. ❌ **O Sistema remove** o livro do cadastro e atualiza as estruturas de indexação.  
25. 🎉 **O Bibliotecário recebe** a confirmação de que o livro foi excluído.  
26. 🔄 **O Sistema retorna** para o Menu de Opções.  
27. 🔍 **O Bibliotecário solicita** a busca de um livro pelo ISBN.  
28. 🏷️ **O Sistema solicita** o ISBN do livro.  
29. 🖊️ **O Bibliotecário insere** o ISBN.  
30. 🔍 **O Sistema verifica** se o ISBN está cadastrado.  
31. 📑 **O Sistema exibe** os dados completos do livro, caso encontrado.  
32. 👓 **O Bibliotecário visualiza** as informações do livro.  
33. 🔄 **O Sistema retorna** para o Menu de Opções.  
34. 📄 **O Bibliotecário seleciona** a geração de um relatório de todos os livros cadastrados.  
35. 🖥️ **O Sistema processa** os dados e organiza os livros de forma ordenada.  
36. 📄 **O Sistema gera** o relatório.  
37. 👓 **O Bibliotecário visualiza** o relatório detalhado dos livros cadastrados.  

---

## ⚠️ Fluxo Alternativo  

### Durante o Cadastro de Livro  
5.1 🚨 **O Sistema informa** que o ISBN já existe no cadastro.  
5.2 ❌ **O Sistema aborta** o cadastro e exibe mensagem de erro.  

### Durante a Alteração de Livro  
12.1 🚨 **O Sistema informa** que o ISBN não está cadastrado.  
12.2 🔄 **O Bibliotecário pode tentar** novamente com outro ISBN ou cancelar a operação.  

### Durante a Exclusão de Livro  
21.1 🚨 **O Sistema informa** que o ISBN não está cadastrado.  
21.2 🔄 **O Bibliotecário pode tentar** novamente com outro ISBN ou cancelar a operação.  

### Durante a Busca de Livro  
30.1 🚨 **O Sistema informa** que o ISBN não está cadastrado.  
30.2 🔄 **O Bibliotecário pode tentar** novamente com outro ISBN ou encerrar a operação.  

### Durante a Geração de Relatório  
34.1 📄 **O Sistema tenta acessar** os dados de livros cadastrados.  
34.2 🚨 **O Sistema informa** que não há livros cadastrados.  
34.3 🔄 **O Bibliotecário encerra** a operação ou aguarda novos cadastros.  


# 🛠️ Diagrama de Atividades

![diagrama de atividade](https://github.com/user-attachments/assets/13aa120d-1dac-4d80-a3dc-d0dd09f7902f)

# Modelagem de Classe

![class3 drawio](https://github.com/user-attachments/assets/f7f192b4-5c67-4868-8f14-88fb42e4f61f)

# 📝 Guia do Usuário  

O **FLIT** foi projetado para ser simples e direto. Ao executar o programa, você terá acesso ao menu principal com as opções:  

**Adicionar**, **Alterar**, **Excluir**, **Buscar**, **Gerar Relatório** e **Sair**.  

Cada funcionalidade está detalhada a seguir:  

---

### 🟢 **Adicionar**  
![ADICIONAR](https://github.com/user-attachments/assets/1101fce8-77e3-4c6d-a765-4e495292141e)  
1. Selecione **"Adicionar"** no menu.  
2. Preencha os campos obrigatórios: **ISBN**, **Título**, **Autor**, **Ano**, **Editora** e **Gênero**.  
   - O **ISBN** deve ser único; duplicatas geram uma mensagem de erro:  
     ![ADICIONAR_ERRO](https://github.com/user-attachments/assets/d3357853-0125-4282-a079-1dfdfe39f273).  
3. Após o preenchimento, o sistema confirma o cadastro com uma mensagem de sucesso:  
   ![ADICIONAR_SUCESSO](https://github.com/user-attachments/assets/cbab849e-c89c-459b-88e1-ce54a723445e).  

---

### 🟡 **Alterar**  
![ALTERAR_SUCESSO](https://github.com/user-attachments/assets/b8d29ade-017e-4b53-ab55-3d3cb00f54ea)  
1. Selecione **"Alterar"** no menu.  
2. Digite o **ISBN** do livro que deseja modificar.  
   - Se o ISBN não existir, será exibida uma mensagem de erro.  
3. Caso o ISBN seja encontrado, os dados atuais serão exibidos para edição.  
4. Após confirmar as alterações, o sistema salva os novos dados e exibe uma mensagem de sucesso.  

---

### 🔴 **Excluir**  
![EXCLUIR_SUCESSO](https://github.com/user-attachments/assets/7bf64ddd-7239-4e3c-94e9-7e9c71ccb331)  
1. Selecione **"Excluir"** no menu.  
2. Digite o **ISBN** do livro que deseja remover.  
   - Se o ISBN não existir, será exibida uma mensagem de erro:  
     ![EXCLUIR_ERRO](https://github.com/user-attachments/assets/9c8f04b0-7cca-418b-a419-907eb5ec7b63).  
3. Caso o ISBN seja encontrado, o sistema confirma a exclusão e exibe uma mensagem de sucesso.  

---

### 🔍 **Buscar**  
![BUSCAR_SUCESSO](https://github.com/user-attachments/assets/657cb707-fe60-4254-aa16-70efc5d92686)  
1. Selecione **"Buscar"** no menu.  
2. Digite o **ISBN** do livro que deseja localizar.  
   - Se o ISBN não existir, será exibida uma mensagem de erro:  
     ![BUSCAR_ERRO](https://github.com/user-attachments/assets/64625a64-6b39-4f7f-81da-659f1b36f6a6).  
3. Caso o ISBN seja encontrado, as informações completas do livro serão exibidas.  

---

### 📄 **Gerar Relatório**  
![RELATORIO](https://github.com/user-attachments/assets/5ff9d259-282a-41f5-9f6a-a98d3bbdd0c5)  
1. Selecione **"Gerar Relatório"** no menu.  
2. O sistema exibirá uma listagem ordenada alfabeticamente pelos títulos dos livros cadastrados.  
   - Se não houver livros cadastrados, será exibida uma mensagem indicando o fim do relatório.  

---

### 🚪 **Sair**  
![SAIR](https://github.com/user-attachments/assets/d83bda03-1453-4116-bbdf-ccc43efa6fe4)  
1. Selecione **"Sair"** no menu.  
2. O sistema encerrará a execução, retornando ao ambiente de linha de comando.


# ✅ Conclusão

O projeto desenvolvido representa uma solução eficiente e organizada para a gestão de livros em bibliotecas, atendendo às principais demandas de controle e automação de processos. Por meio de suas funcionalidades bem definidas, o sistema permite a realização de tarefas como cadastro, busca, alteração, exclusão de registros e geração de relatórios de forma prática e intuitiva, otimizando o trabalho do bibliotecário.
Os diagramas criados, como os casos de uso e o diagrama de atividades, foram fundamentais para mapear e estruturar as interações entre o ator principal e o sistema, garantindo clareza no fluxo das operações. Essas representações visuais destacam a lógica e os passos necessários para cada funcionalidade, promovendo uma melhor compreensão do funcionamento do sistema. Com isso, o projeto se destaca por sua organização, clareza e capacidade de atender às necessidades de gerenciamento de forma simples e eficiente, representando um modelo robusto para aplicações semelhantes.

# 🙏 Agradecimentos

❤️ Obrigado por visitar meu repositório! Esperamos que você ache nosso projeto útil e interessante.
