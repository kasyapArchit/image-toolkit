
#include "Pixel.h"

void Pixel::applyFilter(Color c, float alpha) {
  _color = (1 - alpha) * _color + alpha * c;
}

Pixel::Pixel(int x, int y, Color c) : _x(x), _y(y), _color(c) {}
Pixel::Pixel(Pixel const &p) {
  _x = p._x;
  _y = p._y;
  _color = p._color;
};
Color Pixel::color() const { return _color; }
void Pixel::set_color(Color c) { _color = c; }
ostream &operator<<(ostream &os, Pixel const &p) {
  os << p.color();
  return os;
};
