# CLI bilíngue para correção automatizada de gabaritos

Idiomas disponíveis: Português (Brasil) e Guineense


## 🚀 Instalação

### 💻 Pré-requisitos

- Compilador C++ ou IDE com suporte a esta linguagem
- Recomendamos o compilador g++ do GCC (GNU Compiler Collection)

### Para instalar, siga estas etapas:

- Salve o arquivo `corretor.cpp` em sua máquina
- Compile o arquivo e execute o programa gerado

Linux com g++:

```
g++ corretor.cpp -o corretor.exe
./corretor.exe
```

Windows com g++:

```
g++ corretor.cpp -o corretor.exe
corretor.exe
```

## ☕ Como usar

1. Ao iniciar o programa, você deve escolher entre as duas linguagens disponíveis: Português ou Guineense

2. Você deve escolher entre o modo manual ou randômico.

  - No **modo manual** você irá manualmente inserir o gabarito e as respostas de cada candidato.

  - No **modo randômico** são gerados automaticamente dados mock para teste.

![Menu Inicial](https://github.com/juhachmann/correcao_gabaritos/blob/main/menu_inicial.png) 

3. Ao encerrar a inserção dos dados, o programa irá corrigir os gabaritos dos candidatos e gerará alguns relatórios e o ranking de classificação. Para gabaritos com até 10 questões, o ranking de classificação é exibido em formato de tabela.

 ![Ranking](https://github.com/juhachmann/correcao_gabaritos/blob/main/relatorio.png) 

4. Para corrigir outro gabarito, reinicie a execução do programa. 


## 📫 Disclaimer

Este código não segue nenhuma boa prática, não tem nenhuma preocupação com manutenção ou reusabilidade, não faz ideia do que é gerenciamento de memória e tem apenas uma leve noção de que iterar muitas vezes por uma lista longa pode ser uma má ideia. 

Este pequeno projeto foi desenvolvido como trabalho final na disciplina de Lógica de Programação (2022.2) - Curso Técnico em Desenvolvimento de Sistemas/IFSC. 

O desafio era aplicar os conceitos básicos de programação e produzir um código de arquivo único, utilizando apenas as bibliotecas mais fundamentais da linguagem, tipos primitivos e de forma procedural. Foi uma atividade para exercitar lógica básica de programação, além de tópicos como vetores, ponteiros, sobrecarga de função e Bubble Sort. 


## Equipe: 
Charles Parpineli<br>
Juliana Hachmann<br>
Mamadú Saliu<br>

