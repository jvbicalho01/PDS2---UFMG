#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  std::string descricao_pedido;

  descricao_pedido = std::to_string(this->m_qtd) + "X Pizza " + this->m_sabor +
                     ", " + std::to_string(this->m_pedacos) + " pedacos";

  if (this->m_borda_recheada == true) {
    descricao_pedido += " e borda recheada.";
  } else {
    descricao_pedido += " e sem borda recheada.";
  }

  return descricao_pedido;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  this->m_sabor = sabor;
  this->m_pedacos = pedacos;
  this->m_borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}