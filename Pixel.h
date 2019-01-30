#include<iostream>
#include "Color.h"
using namespace std;
#ifndef Pixel_H_
#define Pixel_H_


class Pixel {
  int _x, _y;
  Color _color;

public:
  Pixel(int x, int y, Color c);
  Pixel():_x(-1),_y(-1){};
  Pixel(Pixel const &p);
  Color color() const;
  void set_color(Color c);
  void applyFilter(Color c, float alpha);

  friend ostream &operator<<(ostream &os, Pixel const &p);
  ~Pixel() {}
};

#endif
