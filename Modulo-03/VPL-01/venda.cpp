#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular& celular) {
  // TODO: Implemente este metodo

  this->m_celulares.push_back(
      Celular(celular._modelo, celular._fabricante, celular._armazenamento,
              celular._memoria, celular._peso, celular._cor,
              celular._quantidade, celular._valor_unitario));
}

void Venda::ordena() {
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular

  this->m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd) {
  // TODO: Implemente este metodo

  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); ++it) {
    if (it->_cod == cod) {
      it->_quantidade += qtd;
    }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */

  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); ++it) {
    if (it->_cod == cod) {
      if (it->_quantidade >= qtd) {
        it->_quantidade -= qtd;
      }
    }
  }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  // TODO: Implemente este metodo

  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); ++it) {
    if (it->_fabricante == fabricante) {
      it->_valor_unitario -= it->_valor_unitario * desconto / 100;
    }
  }
}

void Venda::removeModelo(int cod) {
  // TODO: Implemente este metodo

  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); ++it) {
    if (it->_cod == cod) {
      m_celulares.erase(it);
      break;
    }
  }
}

void Venda::imprimeEstoque() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */

  for (const auto& celular : this->m_celulares) {
    std::string cor_maiuscula;
    double peso_gramas;

    if (celular._quantidade > 0) {
      std::cout << celular._fabricante << " " << celular._modelo << ", ";
      std::cout << celular._armazenamento << "GB, " << celular._memoria
                << "GB RAM, ";

      peso_gramas = celular._peso;
      peso_gramas *= 1000;

      cor_maiuscula = celular._cor;
      cor_maiuscula[0] -= 32;
      // cor_maiuscula[0] = toupper(cor_maiuscula[0]);

      std::cout << peso_gramas << " gramas, " << cor_maiuscula << ", ";

      if (celular._quantidade == 1) {
        std::cout << celular._quantidade << " restante, ";
      } else {
        std::cout << celular._quantidade << " restantes, ";
      }

      std::cout << "R$ " << std::fixed << std::setprecision(2)
                << celular._valor_unitario;

      std::cout << std::fixed << std::setprecision(0);

      std::cout << std::endl;
    }
  }
}