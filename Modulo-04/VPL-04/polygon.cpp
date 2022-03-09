/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include "polygon.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Polygon& poly) {
  for (const Point& p : poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator==(const Polygon& lhs, const Polygon& rhs) {
  // TODO: implement this method.

  bool igual = false;

  for (const Point& p : (const std::vector<Point>&)lhs) {
    if (rhs.contains(p)) {
      igual = true;
    } else {
      return false;
    }
  }

  for (const Point& p : (const std::vector<Point>&)rhs) {
    if (lhs.contains(p)) {
      igual = true;
    } else {
      return false;
    }
  }
  return igual;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  // TODO: implement this method.

  int x = this->limits[0].x;
  int y = this->limits[0].y;
  int largura = this->limits[2].x - this->limits[0].x;
  int altura = this->limits[2].y - this->limits[0].y;

  if ((p.x >= x && p.x <= x + largura) && (p.y >= y && p.y <= y + altura)) {
    return true;
  }

  return false;
}

Point::Point(int xx, int yy) : x(xx), y(yy) {
  // TODO: implement this method.

  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // TODO: implement this method.

  int menor_x, maior_x, menor_y, maior_y;
  std::vector<Point> aux;

  if (x0 <= x1) {
    menor_x = x0;
    maior_x = x1;
  } else {
    menor_x = x1;
    maior_x = x0;
  }

  if (y0 <= y1) {
    menor_y = y0;
    maior_y = y1;
  } else {
    menor_y = y1;
    maior_y = y0;
  }

  aux.push_back(Point(menor_x, menor_y));
  aux.push_back(Point(menor_x, maior_y));
  aux.push_back(Point(maior_x, maior_y));
  aux.push_back(Point(maior_x, menor_y));

  for (int i = 0; i < aux.size(); ++i) {
    this->limits.push_back(aux[i]);
  }
}