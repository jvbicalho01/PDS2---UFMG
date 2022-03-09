#include <math.h>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string& str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string& str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string& str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais
            << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string& str) const {
  // TODO: Implemente este metodo

  std::regex regularExpr("[\\s*\\d\\s*]+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string& str) {
  // TODO: Implemente este metodo:

  std::stringstream stream(str);
  int numero;
  int soma = 0;

  while (stream >> numero) {
    soma += numero;
  }

  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string& str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+\\s*");

  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string& str) {
  // TODO: Implemente este metodo:

  std::stringstream stream(str);

  std::string time_1, time_2;
  int gols_1, gols_2;

  stream >> time_1 >> gols_1 >> time_2 >> gols_2;

  if (gols_2 > gols_1) {
    std::cout << "Vencedor: " << time_2 << std::endl;
  } else if (gols_1 > gols_2) {
    std::cout << "Vencedor: " << time_1 << std::endl;
  } else {
    std::cout << "Empate" << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string& str) {
  // TODO: Implemente este metodo:

  std::stringstream stream(str);

  std::vector<std::string> frase;
  std::string palavra;

  while (stream >> palavra) {
    frase.emplace_back(palavra);
  }

  std::cout << frase.size() << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string& str) const {
  // TODO: Implemente este metodo

  std::regex regularExpr("[ A-Za-z ]+");
  return std::regex_match(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string& str) {
  // TODO: Implemente este metodo:
  std::stringstream stream(str);

  std::vector<std::string> frase;
  std::string palavra;

  while (stream >> palavra) {
    frase.emplace_back(palavra);
  }

  if (frase.size() > 0) {
    int index = frase.size() - 1;
    std::cout << frase[index--];

    while (index >= 0) {
      std::cout << " " << frase[index--];
    }
    std::cout << std::endl;
  }
}

bool EscritorDeDatas::linhaValida(const std::string& str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  // std::regex regularExpr("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  std::regex regularExpr(dateFormat);
  return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string& str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:

  std::stringstream stream(str);

  int dia, mes, ano;
  char barra;

  stream >> dia >> barra >> mes >> barra >> ano;

  std::vector<std::string> meses = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
                                    "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

  std::cout << meses[mes - 1] << std::endl;
}