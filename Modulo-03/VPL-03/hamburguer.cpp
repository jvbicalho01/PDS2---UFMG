#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */

  std::string descricao_pedido;

  descricao_pedido =
      std::to_string(this->m_qtd) + "X Hamburguer " + this->m_tipo;

  if (this->m_artesanal == true) {
    descricao_pedido += " artesanal.";
  } else {
    descricao_pedido += " simples.";
  }

  return descricao_pedido;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  // TODO: Implemente este metodo.

  this->m_tipo = tipo;
  this->m_artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}