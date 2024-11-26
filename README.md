# Projeto: Fast Literary Indexing Tool (FLIT)

![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)

## 💼 Informações sobre o Trabalho
**Faculdade de Tecnologia de Mogi Mirim**

**Curso:** Análise e Desenvolvimento de Sistemas (Noturno)

**Matérias:**

* 🧑🏻‍💻Estrutura de Dados
* 🖥️Engenharia de Software II
  
**Professores:**

* 👨🏻‍🏫Marcos Roberto Nava (Nava)
* 👩🏻‍🏫Ana Celia Ribeiro Bizigato Portes

**Autores:**

- **Fernando Divino** - [@FernaandoJr](https://github.com/FernaandoJr)
- **Ian Camargo** - [@IanCamargo](https://github.com/IanCamargo)
- **Luis Piasentini** - [@LuisPiasentini](https://github.com/LuisPiasentini)
- **Thaito Batalini** - [@thaitoGB](https://github.com/thaitoGB)

# &#128214; Índice 

* [Visão do Produto](#Visão-do-Produto)
* [Tecnologias Utilizadas](#Tecnologias-Utilizadas)
* [Problemas e Soluções](#Problemas-e-Soluções)
* [Product Backlog](#Product-Backlog)
* [Diagrama de Casos de Uso](#Diagrama-de-Casos-de-Uso)
* [Fluxo de Eventos](#Fluxo-de-Eventos)
     * [Fluxo Básico](#Fluxo-Básico)
     * [Fluxo Alternativo](#Fluxo-Alternativo)
* [Diagrama de Atividades](#Diagrama-de-Atividades)
* [Guia do Usuário](#Guia-do-Usuário)
* [Conclusão](#conclusão)
* [Agradecimentos](#agradecimentos)

# 🌟 Visão do Produto
- **Propósito:** FLIT é projetado para resolver a necessidade de organização e gerenciamento de acervos literários em bibliotecas de pequeno e médio porte, facilitando o cadastro, busca e listagem de livros.
- **Público-Alvo:** Bibliotecas públicas e privadas, escolas e universidades que precisam de uma solução leve e eficiente para gerenciar seus livros.
- **Diferenciais:** O uso de estruturas de dados como árvores binárias e listas duplamente ligadas garante uma busca rápida e eficiente, além de uma ordenação simplificada dos livros.
- **Objetivo Estratégico:** Tornar-se uma ferramenta de referência para gestão de acervos literários em pequenas instituições, com potencial de expansão para uma solução mais robusta.
- **Escopo Geral:** Permitir o cadastro de livros com informações como ISBN, título, autor, e outras características, além de funcionalidades de busca, alteração, exclusão e relatórios.

# 🔗 Tecnologias Utilizadas

 - Linguagem C
 - CLion

# ❓ Problemas e Soluções

## Problema: 
- Interar entre as posições de memória para armazenar ou encontrar dados previamente armazenados.

Solução: Implementar uma lógica de loop que percorra os endereços por ponteiro até encontrar um endereço NULL.

# 📋 Product Backlog
![image](https://github.com/user-attachments/assets/db2d0e14-1bdb-4d0f-858c-19a52745b5b5)

# 📊 Diagrama de Casos de Uso
![image](https://github.com/user-attachments/assets/9ef3624e-0c33-46e2-b118-fbbe1bdf5ade)

# 🔄 Fluxo de Eventos

## 🔀 Fluxo Básico
1.  O sistema abre o menu de opções.
2.  O ator solicita o cadastro de um novo livro.
3.  O sistema solicita os detalhes do livro (ISBN, nome, autor, etc.).
4.  O ator insere os detalhes.
5.  O sistema verifica se o ISBN já está cadastrado.
6.  O sistema informa que o ISBN é único e cadastra o livro.
7.  O ator recebe a confirmação de que o livro foi cadastrado com sucesso.

## ⚠️ Fluxo Alternativo
- 5.1.  O sistema informa que o ISBN já existe no cadastro.
- 5.2.  O sistema aborta o cadastro e exibe mensagem de erro.


# 🛠️ Diagrama de Atividades
![diagrama de atividade](https://github.com/user-attachments/assets/13aa120d-1dac-4d80-a3dc-d0dd09f7902f)


# 📝 Guia do Usuário


# ✅ Conclusão
O projeto desenvolvido representa uma solução eficiente e organizada para a gestão de livros em bibliotecas, atendendo às principais demandas de controle e automação de processos. Por meio de suas funcionalidades bem definidas, o sistema permite a realização de tarefas como cadastro, busca, alteração, exclusão de registros e geração de relatórios de forma prática e intuitiva, otimizando o trabalho do bibliotecário.
Os diagramas criados, como os casos de uso e o diagrama de atividades, foram fundamentais para mapear e estruturar as interações entre o ator principal e o sistema, garantindo clareza no fluxo das operações. Essas representações visuais destacam a lógica e os passos necessários para cada funcionalidade, promovendo uma melhor compreensão do funcionamento do sistema. Com isso, o projeto se destaca por sua organização, clareza e capacidade de atender às necessidades de gerenciamento de forma simples e eficiente, representando um modelo robusto para aplicações semelhantes.

# 🙏 Agradecimentos
❤️ Obrigado por visitar meu repositório! Esperamos que você ache nosso projeto útil e interessante.

