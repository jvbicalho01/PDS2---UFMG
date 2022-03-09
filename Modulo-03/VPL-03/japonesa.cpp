#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  std::string descricao_pedido;

  descricao_pedido = std::to_string(this->m_qtd) + "X Comida japonesa - " +
                     this->m_combinado + ", " + std::to_string(this->m_sushis) +
                     " sushis, " + std::to_string(this->m_temakis) +
                     " temakis e " + std::to_string(this->m_hots) + " hots.";

  return descricao_pedido;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  // TODO: Implemente este metodo.

  this->m_combinado = combinado;
  this->m_sushis = sushis;
  this->m_temakis = temakis;
  this->m_hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}