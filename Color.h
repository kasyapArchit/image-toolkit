#include <iostream>
using namespace std;
#ifndef Color_H_
#define Color_H_

class Color {
  int _red, _green, _blue;
  friend ostream &operator<<(ostream &os, Color const &c);

public:
  Color(int r = 0, int g = 0, int b = 0) : _red(r), _blue(b), _green(g) {}
  int red() { return _red; }
  int green() { return _green; }
  int blue() { return _blue; }
  friend Color operator*(float alpha, const Color c1);
  friend Color operator+(const Color &c2, const Color &c1);
  friend bool operator==(const Color &c2, const Color &c1);
  Color(Color const &c);
  ~Color() {}
  int brightness();
};
#endif
