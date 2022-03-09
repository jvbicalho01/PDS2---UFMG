#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */

  std::list<Pedido*>::const_iterator it;
  for (it = m_pedidos.begin(); it != m_pedidos.end(); ++it) {
    delete *it;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo

  this->m_pedidos.emplace_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */

  int num_pedidos = 1;
  float total_vendas = 0.0;

  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); ++it) {
    std::cout << "Pedido " << num_pedidos << std::endl;
    std::cout << (*it)->resumo();
    std::cout << std::endl;
    total_vendas += (*it)->calculaTotal();
    num_pedidos++;
  }

  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2)
            << total_vendas << std::endl;
  std::cout << "Total de pedidos: " << num_pedidos - 1;
}