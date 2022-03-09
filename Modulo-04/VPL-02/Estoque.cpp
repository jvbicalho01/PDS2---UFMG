#include <iostream>
#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO

  // A mercadoria esta no map?
  if (!m_estoque.count(mercadoria)) {
    // se nao, deve inserir
    m_estoque[mercadoria] = qtd;
  } else {
    // se estiver, acrescentar as quantidades para ela
    m_estoque[mercadoria] += qtd;
  }
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO

  if (m_estoque[mercadoria] < qtd) {
    std::cout << mercadoria << " insuficiente";
  } else if (!m_estoque.count(mercadoria)) {
    std::cout << mercadoria << " inexistente";
  } else {
    m_estoque[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO

  if (!m_estoque.count(mercadoria)) {
    return 0;
  } else {
    return m_estoque.at(mercadoria);
  }
}

void Estoque::imprime_estoque() const {
  // TODO

  for (auto it = m_estoque.begin(); it != m_estoque.end(); ++it) {
    std::cout << it->first << ", " << it->second << std::endl;
  }
}

Estoque& Estoque::operator+=(const Estoque& rhs) {
  // TODO

  // for (const auto& [mercadoria, qtd] : rhs.m_estoque)
  for (auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); ++it) {
    this->add_mercadoria((*it).first, (*it).second);
  }

  return *this;
}

Estoque& Estoque::operator-=(const Estoque& rhs) {
  // TODO

  for (auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); ++it) {
    this->sub_mercadoria((*it).first, (*it).second);
  }

  return *this;
}

bool operator<(Estoque& lhs, Estoque& rhs) {
  // TODO

  bool menor = false;

  for (auto it = lhs.m_estoque.begin(); it != lhs.m_estoque.end(); ++it) {
    if (rhs.m_estoque.count((*it).first)) {
      if (rhs.get_qtd((*it).first) > lhs.get_qtd((*it).first)) {
        menor = true;
      } else {
        // menor = false;
        return false;
      }
    } else {
      // menor = false;
      return false;
    }
  }

  return menor;
}

bool operator>(Estoque& lhs, Estoque& rhs) {
  // TODO

  bool maior = false;

  for (auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); ++it) {
    if (lhs.m_estoque.count((*it).first)) {
      if (lhs.get_qtd((*it).first) > rhs.get_qtd((*it).first)) {
        maior = true;
      } else {
        // maior = false;
        return false;
      }

    } else {
      // maior = false;
      return false;
    }
  }

  return maior;
}