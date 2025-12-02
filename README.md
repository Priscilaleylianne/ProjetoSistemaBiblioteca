# Sistema de Biblioteca em C++
![C++](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
![License](https://img.shields.io/badge/Licença-MIT-green)
![POO](https://img.shields.io/badge/Paradigma-POO-orange)
![Status](https://img.shields.io/badge/Status-%20Concluído-red)

Este repositório contém o desenvolvimento completo de um **Sistema de Biblioteca** implementado em **C++**, utilizando os princípios fundamentais
da **Programação Orientada a Objetos (POO)**.

## Sobre o Projeto

Este projeto consiste no desenvolvimento de um **Sistema de Biblioteca** utilizando a linguagem **C++**, baseado em princípios sólidos de **Programação Orientada a Objetos (POO)** e modelagem UML estruturada. O sistema foi criado para demonstrar, de forma prática e educacional, a aplicação de conceitos fundamentais como encapsulamento, herança, polimorfismo e composição.

---

## Estrutura do Sistema

### **Classes Principais**

* `Livro` – Representa os livros disponíveis na biblioteca.
* `Usuario` – Classe base para diferentes tipos de usuários.
* `Aluno` e `Professor` – Especializações de `Usuario` com regras distintas.
* `Biblioteca` – Gerencia o catálogo de livros e cadastro de usuários.
* `Emprestimo` – Controla o processo de empréstimo e devolução.

---

## Conceitos de POO Aplicados

* **Encapsulamento**: Atributos privados com métodos públicos.
* **Herança**: `Aluno` e `Professor` herdam de `Usuario`.
* **Polimorfismo**: Métodos sobrescritos como `limiteEmprestimos()`.
* **Abstração**: Simplificação das entidades e suas responsabilidades.
* **Composição**: Classe `Biblioteca` organiza e controla outras classes.

---

## Tecnologias Utilizadas

* Linguagem: **C++ (C++11 ou superior)**
* Modelagem: **PlantUML**
* Editor sugerido: VSCode, CodeBlocks, CLion ou Dev-C++
* Compilador: g++ ou clang

---

## Como Executar o Projeto

1. Instale um compilador C++ (g++, MinGW ou LLVM).
2. Baixe o projeto ou clone o repositório:

   ```bash
   git clone https://github.com/usuario/sistema-biblioteca.git
   ```
3. Acesse a pasta:

   ```bash
   cd sistema-biblioteca
   ```
4. Compile o projeto:

   ```bash
   g++ -std=c++11 main.cpp -o biblioteca
   ```
5. Execute:

   ```bash
   ./biblioteca
   ```

---

## Estrutura do Projeto

```
📁 sistema-biblioteca
├── 📄 main.cpp
├── 📄 Livro.hpp
├── 📄 Usuario.hpp
├── 📄 Aluno.hpp
├── 📄 Professor.hpp
├── 📄 Biblioteca.hpp
├── 📄 Emprestimo.hpp
├── 📄 README.md
└── 📁 docs
    └── diagramas_uml.png
```

---

## Objetivo do Sistema

O objetivo é oferecer um sistema simples e funcional para controle de livros, usuários e empréstimos, servindo como material didático para ensino de Programação Orientada a Objetos.

---

## Levantamento de Requisitos

### **Requisitos Funcionais (RF)**

* **RF01:** Cadastrar livros no sistema.
* **RF02:** Cadastrar usuários (Aluno ou Professor).
* **RF03:** Realizar empréstimos de livros.
* **RF04:** Registrar devoluções.
* **RF05:** Consultar status de livros.
* **RF06:** Limitar empréstimos conforme tipo de usuário.

### **Requisitos Não Funcionais (RNF)**

* **RNF01:** O sistema deve ser executado em linha de comando.
* **RNF02:** O código deve seguir boas práticas de POO.
* **RNF03:** O desempenho deve permitir execução rápida.
* **RNF04:** A modelagem deve seguir UML estruturada.

---

## Modelagem UML

A modelagem UML inclui:

* Diagrama de Classes
* Diagrama de Relacionamentos
* Componentes do Sistema

(Anexado na pasta `/docs` do projeto)

---

## Componentes do Sistema

* **Módulo de Cadastro**: gerencia livros e usuários.
* **Módulo de Empréstimo**: realiza controle de retirada e devolução.
* **Módulo de Relatórios** (expansão futura): consultas avançadas.

---

## Aplicação dos Conceitos de POO

O sistema utiliza:

* Encapsulamento para proteger dados
* Herança para especializar classes de usuários
* Polimorfismo para comportamento dinâmico
* Composição para organizar dependências internas

---

## Trabalho Colaborativo

O desenvolvimento pode ser realizado com:

* Controle de versão via GitHub
* Criação de issues e pull requests
* Documentação compartilhada

---

## Teste de Integração

Foram realizados testes unindo os módulos:

* Cadastro → Empréstimo → Devolução
* Teste de limites por tipo de usuário
* Verificação de status dos livros

---

## Refatoração

Melhorias aplicadas:

* Separação de classes em arquivos distintos
* Padronização de nomenclaturas
* Otimização da função de busca de livros

---

## Relato Reflexivo

Este projeto permitiu aprofundar habilidades na modelagem orientada a objetos, compreender a importância da modularização e exercitar boas práticas de codificação. A elaboração da UML foi essencial para clareza da estrutura antes da implementação.

---

## Como Executar

Para execução detalhada, veja a seção "Como executar o projeto" acima.

---

## Referências

* Deitel & Deitel – *C++ Como Programar*
* Gamma et al. – *Design Patterns*
* Sommerville – *Engenharia de Software*
* Documentação do PlantUML

---

## Anexos

* Diagramas UML (PNG)
* Exemplos de código
* Histórico de versões do sistema

---
