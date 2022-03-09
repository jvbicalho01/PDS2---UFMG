// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {}

Complexo::Complexo(double a) : Complexo(a, 0) {}

Complexo::Complexo(double a, double b) {
  real_ = a;
  imag_ = b;
}

double Complexo::real() const {
  return real_;
}

double Complexo::imag() const {
  return imag_;
}

bool Complexo::operator==(Complexo x) const {
  // Precisão numérica utilizda.
  static const double epsilon = 1E-6;

  // Quando o módulo é zero, não importa o valor do argumento.
  return fabs(x.real_ - real_) < epsilon && fabs(x.imag_ - imag_) < epsilon;
}

void Complexo::operator=(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
}

double Complexo::modulo() const {
  return sqrt(real_ * real_ + imag_ * imag_);
}

Complexo Complexo::conjugado() const {
  Complexo c;
  c.real_ = real_;
  c.imag_ = -imag_;
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  c.real_ = -real_;
  c.imag_ = -imag_;
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  double denominador = real_ * real_ + imag_ * imag_;
  i.real_ = real_ / denominador;
  i.imag_ = -imag_ / denominador;
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  p.real_ = real_ * y.real_ - imag_ * y.imag_;
  p.imag_ = real_ * y.imag_ + imag_ * y.real_;
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
