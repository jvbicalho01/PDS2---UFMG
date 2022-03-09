#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.

int Celular::cod = 1;

Celular::Celular() {

  _cod = cod++;

}

Celular::Celular(std::string modelo,
                std::string fabricante,
                int armazenamento,
                int memoria,
                double peso,
                std::string cor,
                int qtd,
                float valor) {
  // TODO: Implemente este metodo

  this->_modelo = modelo;
  this->_fabricante = fabricante;
  this->_armazenamento = armazenamento;
  this->_memoria = memoria;
  this->_peso = peso;
  this->_cor = cor;
  this->_quantidade = qtd;
  this->_valor_unitario = valor;
  _cod = cod / 2;
  cod++;

}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular

  if (this->_fabricante == other._fabricante){
    return this->_modelo < other._modelo;
  } else{
    return this->_fabricante < other._fabricante;
  }

  
}