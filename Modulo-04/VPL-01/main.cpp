#include <algorithm>
#include <iostream>
#include <vector>

#include "Algoritmos.hpp"

template <class T>
void read_input(std::vector<T>& vec) {
  T val;
  while (std::cin >> val) {
    vec.push_back(val);
  }
}

template <class T>
void print_input(std::vector<T>& vec) {
  // TODO
  int num_elementos = vec.size();

  for (int i = 0; i < num_elementos - 1; i++) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[num_elementos - 1] << std::endl;
}

template <class T>
T get_max(std::vector<T>& vec) {
  if (vec.empty()) {
    std::cout << "Erro: vetor vazio.\n";
  }
  // TODO
  T maior_valor;
  maior_valor = vec[0];

  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] > maior_valor) {
      maior_valor = vec[i];
    }
  }

  return maior_valor;
}

template <class T>
unsigned int count_duplicates(std::vector<T>& vec) {
  // TODO
  unsigned int num_duplicadas = 0;

  std::sort(vec.begin(), vec.end());

  for (int i = 0; i < vec.size() - 1; i++) {
    if (vec[i] == vec[i + 1]) {
      num_duplicadas++;
      vec.erase(vec.begin() + i);
      i--;
    }
  }

  return num_duplicadas;
}

template <class T>
void test_print_input() {
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T>
void test_get_max() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T>
void test_count_dups() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main() {
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste) {
    case 0:
      test_print_input<std::string>();
      break;
    case 1:
      test_print_input<int>();
      break;
    case 2:
      test_get_max<double>();
      break;
    case 3:
      test_get_max<char>();
      break;
    case 4:
      test_count_dups<int>();
      break;
    case 5:
      test_count_dups<std::string>();
      break;
    default:
      std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}