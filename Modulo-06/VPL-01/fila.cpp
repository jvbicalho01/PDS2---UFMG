#include "fila.h"

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
  // TODO

  this->primeiro_ = nullptr;
  this->ultimo_ = nullptr;
  this->tamanho_ = 0;
}

void Fila::Inserir(int k) {
  // TODO

  No* novo_valor;
  novo_valor = new No;
  novo_valor->chave = k;
  novo_valor->proximo = nullptr;

  if (this->primeiro_ == nullptr) {
    this->primeiro_ = novo_valor;
    this->ultimo_ = novo_valor;
  } else {
    this->ultimo_->proximo = novo_valor;
    this->ultimo_ = novo_valor;
  }

  this->tamanho_++;
}

void Fila::RemoverPrimeiro() {
  // TODO

  if (this->primeiro_ == nullptr && this->ultimo_ == nullptr) {
    throw ExcecaoFilaVazia();
  }

  No* aux;
  aux = this->primeiro_;
  this->primeiro_ = aux->proximo;
  // this->primeiro_ =  this->primeiro_->proximo;
}

int Fila::primeiro() const {
  // TODO

  if (this->primeiro_ == nullptr && this->ultimo_ == nullptr) {
    throw ExcecaoFilaVazia();
  }

  return this->primeiro_->chave;
}

int Fila::ultimo() const {
  // TODO

  if (this->primeiro_ == nullptr && this->ultimo_ == nullptr) {
    throw ExcecaoFilaVazia();
  }

  return this->ultimo_->chave;
}

int Fila::tamanho() const {
  // return this->tamanho_;  // TODO

  No* aux;
  aux = this->primeiro_;

  int tamanho = 0;

  while (aux != nullptr) {
    tamanho++;

    aux = aux->proximo;
  }

  return tamanho;
}