#include <iostream>
using namespace std;
#include "Color.h"

Color operator*(float alpha, const Color c1) {
  return Color(c1._red * alpha, c1._green * alpha, c1._blue * alpha);
}
Color operator+(const Color &c2, const Color &c1) {
  return Color(c1._red + c2._red, c1._green + c2._green, c1._blue + c2._blue);
}
bool operator==(const Color &c2, const Color &c1) {
  return c1._red == c2._red && c1._green == c2._green && c1._blue == c2._blue;
}

Color::Color(Color const &c) {
  _red = c._red;
  _blue = c._blue;
  _green = c._green;
};

int Color::brightness() { return (_red + _green + _blue) / 3; }

ostream &operator<<(ostream &os, Color const &c) {
  os << c._red << " " << c._green << " " << c._blue;
  return os;
};
