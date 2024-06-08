#include <climits>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::right;
using std::string;
using std::system;

#include <iomanip>
using std::setfill;
using std::setprecision;
using std::setw;

#include <string>
using std::to_string;

#include <clocale>
#include <cstdlib>
#include <ctime>

// Protótipos das funções (subprogramas) (implementações ao final do código)
char randChar();
string randNamePT();
string randNameGB();
char validaResposta(char, string);
int validaResposta(int, int, int, string);
string validaResposta(string, string);
void imprimeGabarito(char[], int, string, string);
void imprimeTabela(char[], int);
void confirmaGabarito(char[], int, string, string);
string centraliza(const string, const int);
string centraliza(const float, const int);

// Código Principal
int main() {

  string *msg;
  string
      portugues
          [] =
              {
                  "pt-BR",                             // 0
                  "BEM-VINDO/A AO PROGRAMA DE",        // 1
                  "CORRECAO AUTOMATICA DE GABARITOS!", // 2
                  "Vamos seguir os passos abaixo:\n\n- Etapa 1: Dados da "
                  "Prova\n- Etapa 2: Gabarito Geral\n- Etapa 3: Respostas dos "
                  "Candidatos\n- Etapa 4: Relatório da Prova",         // 3
                  "\n( Entrar em modo RANDÔMICO para teste? (S/N) ) ", // 4
                  "\n- Modo randômico ativado.\n\nGabarito Geral, Nomes e "
                  "Respostas de Candidatos serão gerados automaticamente. "
                  "\nVocê ainda poderá confirmar alguns dados e alterá-los se "
                  "necessário.", // 5
                  "\nDigite com atenção todas as informações e confira ao "
                  "final!\nVamos começar!\n",          // 6
                  "Etapa 1: DADOS DA PROVA",           // 7
                  "\nNº de candidatos: ",              // 8
                  "Nº de questões da prova: ",         // 9
                  "\nConfirma os dados acima? (S/N) ", // 10
                  "\n\nATENÇÃO!!!\n\nSem questões ou sem candidatos não é "
                  "possível gerar a classificação.\nTente novamente quando "
                  "possuir as informações necessárias.\n\nOBRIGADO POR "
                  "UTILIZAR!\n\nATÉ MAIS!",  // 11
                  "Etapa 2: GABARITO GERAL", // 12
                  "\nInstruções:\nDigite a resposta correta de cada questão e "
                  "confira ao final!\n",               // 13
                  "Etapa 3: RESPOSTAS DOS CANDIDATOS", // 14
                  "Instruções:\ndigite as respostas de cada candidato e "
                  "confira ao final!\n",                     // 15
                  "\n\n- Nome do candidato (sem acentos): ", // 16
                  "- Dados gerados randomicamente.",         // 17
                  "Etapa 4: RELATORIO DA PROVA",             // 18
                  "A. Notas de cada candidato:",             // 19
                  "B. Média Geral:",                         // 20
                  "C. Classificados:",                       // 21
                  "D. Desclassificados:",                    // 22
                  "E. Candidatos classificados:",            // 23
                  "Nenhum candidato classificado.",          // 24
                  "F. Melhor nota:",                         // 25
                  "\nObtida pelo(s) candidatos(s): ",        // 26
                  "G. Classificação Geral:",                 // 27
                  "\nA visualização em tabela está disponível apenas para "
                  "provas com até ", // 28
                  " questões. \nA classificação será mostrada em formato de "
                  "lista.",                                               // 29
                  "Candidato",                                            // 30
                  "Nota",                                                 // 31
                  "Questão",                                              // 32
                  "% de acertos",                                         // 33
                  "| Questoes",                                           // 34
                  "| GABARITO",                                           // 35
                  "NOTAS",                                                // 36
                  "| % acertos",                                          // 37
                  "FIM DO PROGRAMA\nOBRIGADA POR UTILIZAR!",              // 38
                  "de ",                                                  // 39
                  "\nPor favor, selecione apenas uma opção (S) ou (N) : " // 40
              };

  string
      guineense
          [] =
              {
                  "gn-GB",          // 0
                  "SEDU BEN-VINDU", // 1
                  "A NO PURGRAMA!", // 2
                  "Kumpanha kéku na pediu la bâs, skirbi dritu paka bu "
                  "yara:\n\n- Purméru 1: Dádus di tarbadju\n- Sugundu 2: "
                  "Gabaritu di tudu tarbádju\n- Turséru 3: Resposta di kilis "
                  "ku faci tarbádju\n- Kuartu 4: Relatóriu di tarbadju",    // 3
                  "\n(Bu misti entra na modu aliatóriu pa testa? (S/N) ) ", // 4
                  "\n- Módu randómiku sta ativadu.\n\nGabaritu Geral, Nomis i "
                  "respostas di kandidátus na parsi automátikamenti. \nBuna "
                  "pudi konfirma dádus i muda assin ku bu misti.", // 5
                  "\nSkirbi ku kalma tudu informasons i djubi si sta "
                  "dritu!\nNô pudi kunsa!\n",                  // 6
                  "Purmeru: DADUS DI TARBADJU",                // 7
                  "\nNumeru di kandidátus: ",                  // 8
                  "Numeru di kistons di tarbádju: ",           // 9
                  "\nButa konfirma dádus ku sta ribi? (S/N) ", // 10
                  "\n\nATENSON!!!\n\nSin tarbádju ou sin kandidátu ikana da pa "
                  "mostra náda.\nBu pudi n’tenta assin ku bu tene tudu "
                  "informasons ku pidídu.\n\nOBRIGÁDU PA MANÉRA KU BU UZA NA "
                  "SIRVISSU!\n\nATÉ UTRU BIAS!", // 11
                  "Sugundu 2: GABARITU GERAL",   // 12
                  "\nInstrussons:\nSkirbi resposta certu di kada kiston i "
                  "djubil ora ku bu kaba!\n",          // 13
                  "Turceru 3: RESPOSTA DI KANDIDATUS", // 14
                  "Instrussons:\nSkirbi resposta di kada kiston i djubil ora "
                  "ku bu kaba!\n",                                     // 15
                  "\n\n- Nomi di kandidátu (sin assentu): ",           // 16
                  "- Dádus ku parci randomikamenti.",                  // 17
                  "Kuartu 4: RELATORIU DI PROVA",                      // 18
                  "A. Nota di kada kandidátu:",                        // 19
                  "B. Média Geral:",                                   // 20
                  "C. Kilis ku passa:",                                // 21
                  "D. Kilis ku ntchumba:",                             // 22
                  "E. Kandidatus ku passa:",                           // 23
                  "Nin un kadidátu ka passa.",                         // 24
                  "F. Mindjor nota:",                                  // 25
                  "\nku konsiguidu pa kandidatis: ",                   // 26
                  "G. Classificasson Geral:",                          // 27
                  "\nInformasson di tabela sta dispunível son pa até", // 28
                  " kistons. \nKlassificasson na bá mostradu na formátu di "
                  "lista.",         // 29
                  "Kandidátu",      // 30
                  "Nota",           // 31
                  "Kistons",        // 32
                  "% ku certadu",   // 33
                  "| Kistons",      // 34
                  "| GABARITU",     // 35
                  "NOTAS",          // 36
                  "| % ku certadu", // 37
                  "NÔ PURGURAMA KABA LI. OBRIGADU PA MANERA KU BU UZAL! NÔ STA "
                  "DJUNTU!",                                 // 38
                  "di ",                                     // 39
                  "\nDi fabur, kudji un opson (S) ou (N) : " // 40
              };

  // Valores para configuração da tabela
  const int colunaInicio = 32;
  const int colunaRespostas = 4;
  const int colunaFim = 8;
  const int larguraBorda = 50;
  const int larguraInterna = larguraBorda - 1;
  const int linhaSeparadora = 50;
  const int tabRelatorio = 30;
  const int colMaxTabela = 10;

  // Valores definidos
  const float notaClassificacao = 5.0, notaMaxima = 10.0;

  int i, j, k, m, n;

  float somaNotas = 0.0, maiorNota = -1.0;
  int clas = 0;

  string nomAux;
  float aux;

  char resp;
  bool manual = true;

  setlocale(LC_ALL, "portuguese");

  // Mensagem para selecionar o idioma:
  cout << "\n\n\nEscolha o seu idioma    /   Kudji bu lingua:\n\n(G) Guinensi  "
          "   (P) Português : ";
  cin >> resp;
  resp = tolower(resp);
  while (resp != 'p' && resp != 'g') {
    cout << "\n\nPor favor, digite a letra que corresponde ao seu idioma\n\nDi "
            "fabur, skirbi letra kuta korespondi bu lingua\n\n(G) Guinensi     "
            "(P) Português : ";
    cin >> resp;
    resp = tolower(resp);
  }
  if (resp == 'p') {
    msg = portugues;
  } else {
    msg = guineense;
  }
  cout << endl << endl;

  // Mensagens Iniciais

  cout << "\n\n\n";
  cout << left;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[1], larguraInterna - 1) << "|"
       << endl; // Bem vindo ao programa
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[2], larguraInterna - 1) << "|"
       << endl; // de correção automática de gabaritos
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl << endl;

  cout << msg[3] << endl; // Passos a seguir

  cout << msg[4]; // Entrar em modo randômico?
  cin >> resp;
  resp = tolower(resp);
  while (resp != 's' && resp != 'n') {
    cout << msg[40] << endl;
    cin >> resp;
  }
  if (resp == 's') {
    cout << msg[5] << endl; // Instruções para randômico
    manual = false;
    srand(time(0));
  } else {
    cout << msg[6] << endl; // Instruções para manual
  }

  // ::::::::::::::
  // Início da ENTRADA de dados no programa

  cout << "\n\n\n";
  cout << left;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[7], larguraInterna - 1) << "|"
       << endl; // TABELA ETAPA 1
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl << endl;

  // Entrada do Nº de Candidatos e nº de Questões
  do {
    cout << msg[8]; // Nº de candidatos
    cin >> n;
    n = validaResposta(n, 0, INT_MAX, msg[0]);
    cout << msg[9]; // Nº de questões
    cin >> m;
    m = validaResposta(m, 0, INT_MAX, msg[0]);
    cout << msg[10]; // Confirma?
    cin >> resp;
    resp = tolower(resp);
    while (resp != 's' && resp != 'n') {
      cout << msg[40] << endl;
      cin >> resp;
    }
  } while (resp != 's');

  const int numCands = n;
  const int numQuests = m;

  if (numCands == 0 || numQuests == 0) {
    cout << endl
         << endl
         << setw(linhaSeparadora) << setfill('-') << "-" << endl;
    cout << msg[11]
         << endl; // Mensagem de finalização do programa por falta de dados
    return 0;
  }

  char gab[numQuests];
  string nomes[numCands];
  float notas[numCands], acertos[numQuests];
  char respostas[numCands][numQuests];
  char respAux[numQuests];

  // Entrada do Gabarito Geral da Prova

  cout << "\n\n\n";
  cout << left;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[12], larguraInterna - 1) << "|"
       << endl; /// TABELA ETAPA 2
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl << endl;

  if (manual) {
    cout << msg[13] << endl; // Instruções para entrada de gabarito manual
    for (j = 0; j < numQuests; j++) {
      cout << j + 1 << ": ";
      cin >> gab[j];
      gab[j] = validaResposta(gab[j], msg[0]);
    }
  } else {
    for (j = 0; j < numQuests; j++) {
      gab[j] = randChar();
    }
  }
  confirmaGabarito(gab, numQuests, "Geral", msg[0]);

  // Entrada dos nomes dos candidatos e suas respostas

  cout << "\n\n\n";
  cout << left;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[14], larguraInterna - 1) << "|"
       << endl; // TABELA ETAPA 3
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl << endl;

  if (manual) {
    cout << msg[15]
         << endl; // Instruções para entrada manual de dados de candidatos
    for (i = 0; i < numCands; i++) {
      cout << msg[16]; // Nome do candidato
      cin.ignore(256, '\n');
      getline(cin, nomes[i]);
      nomes[i] = validaResposta(nomes[i], msg[0]);
      cout << endl;
      for (j = 0; j < numQuests; j++) {
        cout << "- " << j + 1 << ": ";
        cin >> respostas[i][j];
        respostas[i][j] = validaResposta(respostas[i][j], msg[0]);
      }
      confirmaGabarito(respostas[i], numQuests, msg[39] + nomes[i], msg[0]);
    }
  } else { // Modo randômico
    if (msg[0] ==
        "pt-BR") { // Nomes em português (Aqui fora faz a checagem só uma vez)
      for (i = 0; i < numCands; i++) {
        nomes[i] = randNamePT();
        for (j = 0; j < numQuests; j++) {
          respostas[i][j] = randChar();
        }
      }
    } else { // Nomes em Guineense
      for (i = 0; i < numCands; i++) {
        nomes[i] = randNameGB();
        for (j = 0; j < numQuests; j++) {
          respostas[i][j] = randChar();
        }
      }
    }
    cout << msg[17] << endl; // Msg de dados gerados randomicamente.
  }

  
  // ::::::::::::::
  // CÁLCULOS AQUI!

  for (i = 0; i < numCands; i++) {
    notas[i] = 0;
    for (j = 0; j < numQuests; j++) {
      if (respostas[i][j] == gab[j]) {
        notas[i]++;
      }
    }
    notas[i] = (notas[i] * notaMaxima) / numQuests; // Nota de cada candidato
    if (notas[i] >= maiorNota) {
      maiorNota = notas[i]; // Maior nota
    }
    if (notas[i] >= notaClassificacao) {
      clas++; // Nº de Classificados
    }
    somaNotas += notas[i]; // Somatório de notas (para calcular média)
  }
  for (j = 0; j < numQuests; j++) {
    acertos[j] = 0;
    for (i = 0; i < numCands; i++) {
      if (respostas[i][j] == gab[j]) {
        acertos[j]++; // Nº de acertos de cada questão
      }
    }
  }

  
  // ::::::::::::::
  // Início da SAÍDA de dados na tela

  cout << "\n\n\n";
  cout << left;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl;
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << "|" << setfill(' ') << setw(larguraInterna - 1)
       << centraliza(msg[18], larguraInterna - 1) << "|"
       << endl; // TABELA ETAPA 4
  cout << setw(larguraInterna) << setfill(' ') << "|"
       << "|" << endl;
  cout << setw(larguraBorda) << setfill('-') << "-" << endl << endl;

  cout << fixed << setprecision(1) << setfill(' ') << endl << endl;

  
  // CLASSIFICA POR NOME:    (acho que será o DESAFIO!)
  // Algoritmo 'Bubble Sort'
  // Classificação Crescente por nome
  for (j = 0; j < numCands - 1; j++) {
    for (i = 0; i < numCands - 1 - j; i++) {
      if (nomes[i] > nomes[i + 1]) {
        nomAux = nomes[i]; // Troca Nome
        nomes[i] = nomes[i + 1];
        nomes[i + 1] = nomAux;
        aux = notas[i]; // Troca Notas
        notas[i] = notas[i + 1];
        notas[i + 1] = aux;
        for (k = 0; k < numQuests; k++) { // Troca Gabarito
          respAux[k] = respostas[i][k];
          respostas[i][k] = respostas[i + 1][k];
          respostas[i + 1][k] = respAux[k];
        }
      } else if ((nomes[i] == nomes[i + 1]) && (notas[i] > notas[i + 1])) {
        aux = notas[i]; // Troca Nota
        notas[i] = notas[i + 1];
        notas[i + 1] = aux;
        for (k = 0; k < numQuests; k++) { // Troca Gabarito
          respAux[k] = respostas[i][k];
          respostas[i][k] = respostas[i + 1][k];
          respostas[i + 1][k] = respAux[k];
        }
      }
    }
  }

  
  cout << msg[19] << endl; // A. Notas de cada candidato
  cout << setw(linhaSeparadora) << setfill('-') << "-" << setfill(' ') << endl;
  for (i = 0; i < numCands; i++) {
    cout << left << setw(tabRelatorio) << nomes[i] << right
         << setw(colunaRespostas) << notas[i] << endl;
  }
  cout << left << setfill(' ') << endl << endl << endl;

  cout << setw(tabRelatorio + 1) << msg[20] << right << setw(colunaRespostas)
       << (somaNotas * 1.0) / numCands << endl; // B. Média Geral
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  cout << setfill(' ') << endl << left << endl << endl;

  cout << setw(tabRelatorio) << msg[21] << right << setw(colunaRespostas)
       << clas << setw(colunaRespostas) << " "
       << "( " << (clas * 100.0) / numCands << " % ) "
       << endl; // C. Classificados
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  cout << setfill(' ') << left << endl << endl << endl;

  cout << setw(tabRelatorio) << msg[22] << right << setw(colunaRespostas)
       << numCands - clas << left << setw(colunaRespostas) << " "
       << "( " << ((numCands - clas) * 100.0) / numCands << " % ) "
       << endl; // D. Desclassificados
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  cout << setfill(' ') << endl << endl << endl;

  cout << msg[23] << endl; // E. Estudantes classificdos
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  if (clas > 0) {
    for (i = 0; i < numCands; i++) {
      if (notas[i] >= notaClassificacao) {
        cout << "- " << nomes[i] << endl;
      }
    }
  } else {
    cout << msg[24] << endl; // Não há classificados
  }
  cout << setfill(' ') << endl << endl << endl;

  cout << setw(tabRelatorio) << msg[25] << right << setw(colunaRespostas)
       << maiorNota << left << endl; // F. Maior Nota
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  cout << msg[26] << endl; // Obtida pelos candidatos
  for (i = 0; i < numCands; i++) {
    if (notas[i] == maiorNota) {
      cout << "- " << nomes[i] << endl;
    }
  }
  cout << setfill(' ') << endl << endl << endl;

  
  // CLASSIFICA POR NOTA (Classificação Bolha - Acho que será o desafio!)
  // Algoritmo 'Bubble Sort'
  // Classificação Descrescente por nota
  for (j = 0; j < numCands - 1; j++) {
    for (i = 0; i < numCands - 1 - j; i++) {
      if (notas[i] < notas[i + 1]) {
        aux = notas[i];
        notas[i] = notas[i + 1];
        notas[i + 1] = aux;
        nomAux = nomes[i];
        nomes[i] = nomes[i + 1];
        nomes[i + 1] = nomAux;
        for (k = 0; k < numQuests; k++) {
          respAux[k] = respostas[i][k];
          respostas[i][k] = respostas[i + 1][k];
          respostas[i + 1][k] = respAux[k];
        }
      }
      if ((nomes[i] > nomes[i + 1]) && (notas[i] == notas[i + 1])) {
        nomAux = nomes[i]; // Altera junto a lista de nomes
        nomes[i] = nomes[i + 1];
        nomes[i + 1] = nomAux;
        for (k = 0; k < numQuests; k++) { // Altera junto o índice do gabarito
          respAux[k] = respostas[i][k];
          respostas[i][k] = respostas[i + 1][k];
          respostas[i + 1][k] = respAux[k];
        }
      }
    }
  }

  cout << msg[27] << endl; // G. Classificação Geral
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;

  if (numQuests > colMaxTabela) { // Se tem muitas questões
    cout << msg[28]
         << colMaxTabela; // Aviso de que saída será feita em formato de lista
                          // (simples) pois tabela seria desconfigurada
    cout << msg[29] << setfill(' ') << endl << endl << endl;

    cout << setw(colunaInicio) << msg[30]; // Candidato / Nota
    cout << msg[31] << endl;
    cout << setw(linhaSeparadora) << setfill('-') << "-" << setfill(' ')
         << endl;

    for (i = 0; i < numCands; i++) {
      cout << left << setw(colunaInicio) << nomes[i] << right
           << setw(colunaRespostas) << notas[i] << endl;
    }
    cout << left << endl << endl;

    cout << setprecision(0) << setw(colunaInicio)
         << msg[32]; // Questão / % de acertos
    cout << msg[33] << endl;
    cout << setw(linhaSeparadora) << setfill('-') << "-" << setfill(' ')
         << endl;

    for (j = 0; j < numQuests; j++) {
      cout << "Q." << left << setw(colunaInicio - 2) << j + 1 << right
           << setw(colunaRespostas) << (acertos[j] * 100.0) / numCands << " % "
           << endl;
    }
    cout << left << endl;

  } else {
    // TABELA GERAL DE CLASSIFICADOS
    int linhaExterna =
        colunaInicio + (numQuests * colunaRespostas * 2) + colunaFim + 2;
    int linhaInterna =
        colunaInicio + (numQuests * colunaRespostas * 2) + colunaFim + 1;

    cout << setprecision(1) << left << endl;
    cout << setw(linhaExterna) << setfill('-') << "-" << endl;
    cout << setfill(' ') << setw(colunaInicio) << msg[34]; // Questões

    for (i = 0; i < numQuests; i++) {
      cout << setw(colunaRespostas) << "|" << setw(colunaRespostas) << i + 1;
    }

    cout << "|" << setw(colunaFim) << " "
         << "|" << endl;
    cout << setw(linhaInterna) << setfill('-') << "|"
         << "|" << endl;
    cout << setw(colunaInicio) << left << setfill(' ') << msg[35]; // Gabarito

    for (j = 0; j < numQuests; j++) {
      cout << setw(colunaRespostas) << "|" << setw(colunaRespostas) << gab[j];
    }

    cout << "|" << setw(colunaFim) << centraliza(msg[36], colunaFim) << "|"
         << endl; // Notas
    cout << setw(linhaInterna) << setfill('-') << "|"
         << "|" << endl;
    cout << setfill(' ');

    for (i = 0; i < numCands; i++) {
      cout << "| " << setw(colunaInicio - 2) << nomes[i];
      for (j = 0; j < numQuests; j++) {
        cout << setw(colunaRespostas) << "|" << setw(colunaRespostas)
             << respostas[i][j];
      }
      cout << "|" << setw(colunaFim) << centraliza(notas[i], colunaFim) << "|"
           << endl;
    }

    cout << setw(linhaInterna) << setfill('-') << "|"
         << "|" << endl;
    cout << setfill(' ');
    cout << setw(colunaInicio) << msg[37]; // % de acertos

    for (j = 0; j < numQuests; j++) {
      cout << "|" << setw(colunaRespostas + 3)
           << centraliza(((acertos[j] * 100.0) / numCands),
                         (colunaRespostas + 3));
    }

    cout << setprecision(1) << "|" << setw(colunaFim)
         << centraliza((somaNotas * 1.0) / numCands, colunaFim) << "|"
         << endl; // Média Geral
    cout << setw(linhaExterna) << setfill('-') << "-" << endl;
  }

  cout << endl << endl;
  cout << msg[38] << endl; // MSG de fim de programa
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;
  cout << setw(linhaSeparadora) << setfill('-') << "-" << endl;

  return 0;

  // Prof, nos passe de fase <3

  // FIM da função main
};


// Implementação das outras funções

// randChar : gera caractere aleatório entre 'a' e 'e':
char randChar() { return (rand() % ('e' - 'a' + 1) + 'a'); };

// randName : escolhe um nome aleatório de uma lista de nomes:
string randNameGB() {
  // Não consegui usar ponteiro por causa da função sizeof. Tive que repetir o
  // código

  int indiceNome, indiceSobrenome1, indiceSobrenome2;

  string nomesGB[] = {"Mamadu", "Alfa", "Braima", "Mariama", "Umo", "Salimatu"};

  string sobrenomesGB[] = {"Djalo", "Balde", "Embalo", "Seidi", "Co", "Nunes"};

  bool sobrenomeSimples = rand() % 2;

  string nome;

  indiceNome = rand() % (sizeof(nomesGB) / sizeof(string));
  indiceSobrenome1 = rand() % (sizeof(sobrenomesGB) / sizeof(string));

  if (sobrenomeSimples) {
    return nomesGB[indiceNome] + " " + sobrenomesGB[indiceSobrenome1];
  }

  indiceSobrenome2 = rand() % (sizeof(sobrenomesGB) / sizeof(string));
  while (indiceSobrenome1 == indiceSobrenome2) {
    indiceSobrenome2 = rand() % (sizeof(sobrenomesGB) / sizeof(string));
  }

  return nomesGB[indiceNome] + " " + sobrenomesGB[indiceSobrenome1] + " " +
         sobrenomesGB[indiceSobrenome2];
};

string randNamePT() {

  int indiceNome, indiceSobrenome1, indiceSobrenome2;

  string nomesPT[] = {"Juliana", "Helena",  "Aurora", "Suellen",  "Monica",
                      "Tatiana", "Bruna",   "Sophia", "Osmarina", "Edula",
                      "Elza",    "Paulo",   "Joao",   "Felipe",   "Lucas",
                      "Antonio", "Gabriel", "Thales", "Thomas",   "Marcelo",
                      "Eduardo", "Bruno",   "Jorge",  "Alice",    "Alana",
                      "Carlos",  "Manoela", "Rayana", "Gabriela", "Lorenzo",
                      "Miria",   "Samuel",  "Salvio", "Sueli",    "Roberto",
                      "Charles", "Andre",   "Andrino"};

  string sobrenomesPT[] = {"de Souza", "Soares",  "da Silva",  "Pinto",
                           "Alves",    "Correa",  "Antunes",   "Carvalho",
                           "Nunes",    "Flores",  "de Castro", "Cardoso",
                           "Vieira",   "da Rosa", "de Matos"};

  bool sobrenomeSimples = rand() % 2;

  string nome;

  indiceNome = rand() % (sizeof(nomesPT) / sizeof(string));
  indiceSobrenome1 = rand() % (sizeof(sobrenomesPT) / sizeof(string));

  if (sobrenomeSimples) {
    return nomesPT[indiceNome] + " " + sobrenomesPT[indiceSobrenome1];
  }

  indiceSobrenome2 = rand() % (sizeof(sobrenomesPT) / sizeof(string));
  while (indiceSobrenome1 == indiceSobrenome2) {
    indiceSobrenome2 = rand() % (sizeof(sobrenomesPT) / sizeof(string));
  }

  return nomesPT[indiceNome] + " " + sobrenomesPT[indiceSobrenome1] + " " +
         sobrenomesPT[indiceSobrenome2];
};

// validaResposta (char) : valida se as respostas do gabarito estão entre 'a' e
// 'e'
char validaResposta(char resp, string idioma) {

  resp = tolower(resp);
  if (idioma == "pt-BR") {
    while (resp < 'a' || resp > 'e') {
      cout << "\nOoops, valor inválido!\nDigite um caractere (A, B, C, D, E) "
              ":\n";
      cin >> resp;
      resp = tolower(resp);
    }
  } else {
    while (resp < 'a' || resp > 'e') {
      cout << "\nOoops, kéku bu skirbi kasta dritu!\n Skirbi es karaters ku "
              "sta diante(A, B, C, D, E) :\n";
      cin >> resp;
      resp = tolower(resp);
    }
  }
  cout << endl;
  return resp;
};

// validaResposta (int) :  Valida se o inteiro está dentro do intervalo
// determinado
int validaResposta(int resp, int min = INT_MIN, int max = INT_MAX,
                   string idioma = "pt-BR") {

  if (idioma == "pt-BR") {
    while (resp < min || resp > max) {
      cout << "Ooops, número inválido!\nDigite um número entre " << min << " e "
           << max << ": ";
      cin >> resp;
    }
  } else {
    while (resp < min || resp > max) {
      cout << "Ooops, numeru kasta dritu!\n Skirbi un numeru entri " << min
           << " e " << max << ": ";
      cin >> resp;
    }
  }
  cout << endl;
  return resp;
};

// validaResposta (string) : Vê se o nome não é muito grande nem tem acento
// (para não bagunçar a tabela)
string validaResposta(string resp, string idioma) {
  int tam_maximo = 30;
  int i;
  bool invalido;

  do {
    invalido = false;

    for (i = 0; resp[i] != '\0'; i++) {
      if (resp[i] < 'A') {
        if (resp[i] != ' ') {
          invalido = true;
          break;
        }
      }
      if (resp[i] > 'Z') {
        if (resp[i] < 'a' || resp[i] > 'z') {
          invalido = true;
          break;
        }
      }
      if (i == tam_maximo) {
        invalido = true;
        break;
      }
    }

    if (i == 0) {
      invalido = true;
    }
    // poderia testar se é vários caracteres em branco tbm!! Mas não dá mais
    // tempo...

    if (invalido) {
      if (idioma == "pt-BR") {
        cout << "\nOps, valor incorreto!"
             << "\nOs nomes devem: "
             << "\n- ter entre 1 e " << tam_maximo << " caracteres"
             << "\n- não possuir acentos ou caracteres especiais"
             << "\n\nTente novamente: ";
        // cin.ignore(256, '\n');
        getline(cin, resp);
      } else {
        cout << "\nOps, Ikasta dritu!"
             << "\nNomis dibidi:"
             << "\n- tene entre 1 ku " << tam_maximo << " karaters"
             << "\n- tambê ika pudi tene assentus nin karaters speciais"
             << "\n\nTenta utru bias: ";
        // cin.ignore(256, '\n');
        getline(cin, resp);
      }
    }
  } while (invalido);
  cout << endl;
  return resp;
};

// confirmaGabarito : dá ao usuário a opção de mudar uma resposta caso tenha
// digitado errado, melhora a experiência do usuário com o programa
void confirmaGabarito(char gabLista[], int n, string nome, string idioma) {

  char confirma;
  int numQ = 0;

  imprimeGabarito(gabLista, n, nome, idioma);

  if (idioma == "pt-BR") {
    cout << "\nConfirma gabarito? (S/N) ";
    cin >> confirma;
    confirma = tolower(confirma);
    while (confirma != 's' && confirma != 'n') {
      cout << "\nPor favor, selecione apenas uma opção (S) ou (N) : ";
      cin >> confirma;
      confirma = tolower(confirma);
    }
  } else {
    cout << "\nButa confirma gabaritu? (S/N) ";
    cin >> confirma;
    confirma = tolower(confirma);
    while (confirma != 's' && confirma != 'n') {
      cout << "\nDi fabur, kudji un opson (S) ou (N) : ";
      cin >> confirma;
      confirma = tolower(confirma);
    }
  }

  if (confirma != 's') {
    if (idioma == "pt-BR") {
      cout << "\n-- Digite o nº da questão você deseja corrigir: ";
    } else {
      cout << "\n-- Skirbi numeru di kistons ku bu misti kurgi: ";
    }

    cin >> numQ;
    numQ = validaResposta(numQ, 1, n, idioma);
    cout << "\n" << numQ << ": ";
    cin >> gabLista[numQ - 1];
    gabLista[numQ - 1] = validaResposta(gabLista[numQ - 1], idioma);
    confirmaGabarito(gabLista, n, nome, idioma);
  }
};

// imprimeGabarito : imprime o gabarito digitado / alterado para conferência
void imprimeGabarito(char gabLista[], int n, string nome, string idioma) {

  int linha = 30;

  if (idioma == "pt-BR") {
    cout << "\nConferir Gabarito " << nome << ": " << endl;
  } else {
    cout << "\nDjubi dritu  Gabaritu " << nome << ": " << endl;
  }

  cout << setw(linha) << setfill('-') << "-" << endl;

  for (int j = 0; j < n; j++) {
    cout << j + 1 << ": " << gabLista[j] << endl;
  }
  cout << endl;
};

// centraliza (string) :  centraliza o máximo possível o texto dentro do campo
// da tabela
string centraliza(const string texto, const int tamCampo) {

  int i;
  int tamTexto = texto.length();
  int espacoSobra = tamCampo - tamTexto;
  string pref = "", suf = "";

  for (i = 0; i < espacoSobra / 2; i++) {
    pref += " ";
    suf += " ";
  }

  return pref + texto + suf;
};

// centraliza (float) : centraliza o máximo possível o número dentro do campo da
// tabela
string centraliza(const float numero, const int tamCampo) {

  const int maxTexto = 4;
  int i;
  string texto = to_string(numero);
  int tamTexto = texto.length();

  if (tamTexto > maxTexto) {
    texto = texto.substr(0, maxTexto);
  }

  int espacoSobra = tamCampo - maxTexto;

  string pref = "", suf = "";

  for (i = 0; i < espacoSobra / 2; i++) {
    pref += " ";
    suf += " ";
  }

  return pref + texto + suf;
};
