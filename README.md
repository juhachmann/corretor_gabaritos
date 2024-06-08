

<h1 align="center">Corretor de Gabaritos</h1>
<h4 align="center">Um corretor SEMI automático para suas provas</h4>

<p align="center">
  <a href="#Funcionalidades">Funcionalidades</a> •
  <a href="#Instalação">Instalação</a> •
  <a href="#Uso">Uso</a> •
  <a href="#Disclaimer">Disclaimer</a> •
  <a href="#Equipe">Equipe</a> •
</p>



## Funcionalidades ☑️ 

* Corretor SEMI automático de exames de múltipla escolha
  - Você **SÓ** precisa digitar todas as respostas a serem corrigidas 🤡
* Classificação e relatórios globais
  - Veja as notas mais altas e mais baixas, percentuais de acerto por questão e classificação geral
* Clássica Interface de terminal de comando
* Sem instalação de dependências
  - Toda o código está em um único arquivo gigantesco
* Bilíngue
  - Interface em Português (PT-BR) e Guineense(GW)

## Instalação 🚀  

Para instalar esta aplicação, você só precisa de um compilador para C++ instalado em sua máquina. Recomendamos: 
- [GCC/g++](https://gcc.gnu.org/install/)

Agora você pode fazer o download, compilar e executar a aplicação. 

No seu terminal de comando, execute:

```bash
# Clone este repositório
$ git clone https://github.com/juhachmann/exam_corrector

# Entre na pasta local do repositório
$ cd exam_corrector

# Compile o arquivo da aplicação
$ g++ corrector.cpp -o corrector.exe

# Execute
$ ./corrector.exe
```

Ou abra e execute com sua IDE de C++ favorita


## Uso ☕

- **Modo Manual**: você irá inserir todos os dados necessários para as correções, isto é, o gabarito e as respostas de cada estudante/candidato
- 
- **Modo Randômico**: dados "falsos" são gerados para casos de teste 

<div align="center">
  <img src="https://github.com/juhachmann/correcao_gabaritos/blob/main/demo_corretor.gif" width="80%" height="80%" alt="Demo">
</div>


## Disclaimer ‼️

Este pequeno projeto foi desenvolvido como trabalho final na disciplina de Lógica de Programação (2022.2) - Curso Técnico em Desenvolvimento de Sistemas/IFSC. 

🧯 Este código não segue nenhuma boa prática, não faz ideia do que é gerenciamento de memória e tem apenas uma leve noção de que iterar muitas vezes por uma lista longa pode ser uma má ideia. **Não nos responsabilizamos por danos em sua máquina**. 🧯

O desafio foi apenas aplicar os conceitos básicos de programação e produzir um código de arquivo único, utilizando as bibliotecas mais fundamentais da linguagem, tipos primitivos e de estilo procedural. Foi uma atividade para exercitar lógica básica de programação, além de tópicos como vetores, ponteiros, sobrecarga de função e Bubble Sort. 


## Equipe: 

Charles Parpineli<br>
Juliana Hachmann<br>
Mamadú Saliu<br>

