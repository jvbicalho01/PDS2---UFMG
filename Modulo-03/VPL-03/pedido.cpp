#include "pedido.hpp"

Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */

  std::list<Produto*>::const_iterator it;
  for (it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    delete *it;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.

  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.

  float valor_total = 0.0;
  float valor_produto = 0.0;

  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    valor_produto = (*it)->getQtd() * (*it)->getValor();
    valor_total += valor_produto;
  }

  return valor_total;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.

  this->m_produtos.emplace_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */

  std::string resumo_pedidos;

  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    resumo_pedidos += (*it)->descricao();
    resumo_pedidos += "\n";
  }

  resumo_pedidos += "Endereco: ";
  resumo_pedidos += this->m_endereco;

  return resumo_pedidos;
}