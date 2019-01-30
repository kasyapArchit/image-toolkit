#include "Image.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
Image operator*(Image const &i1, float alpha) {
  int w = i1._width;
  int h = i1._height;
  int maxColor = i1.maxColor;
  Image temp_image(w, h, maxColor);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int r = min(maxColor, (int)(i1._img[i][j].color().red() * alpha));
      int g = min(maxColor, (int)(i1._img[i][j].color().green() * alpha));
      int b = min(maxColor, (int)(i1._img[i][j].color().blue() * alpha));
      temp_image._img[i][j].set_color(Color(r, g, b));
    }
  }
  return temp_image;
}
Image operator+(Image const &i1, Image const &i2) {
  if (i1._width != i2._width || i1._height != i2._height ||
      i1.maxColor != i2.maxColor) {
    cout << "ERROR with + operator" << endl;
  }

  int w = i1._width;
  int h = i1._height;
  int maxColor = i1.maxColor;
  Image temp_image(w, h, maxColor);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int r = min(maxColor,
                  i1._img[i][j].color().red() + i2._img[i][j].color().red());
      int g = min(maxColor, i1._img[i][j].color().green() +
                                i2._img[i][j].color().green());
      int b = min(maxColor,
                  i1._img[i][j].color().blue() + i2._img[i][j].color().blue());
      temp_image._img[i][j].set_color(Color(r, g, b));
    }
  }
  // cout << temp_image.maxColor << endl;
  return temp_image;
}

void Image::findColor(Color c, int &x, int &y) {
  int closest = _width * _width + _height * _height;
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      if (i * i + j * j < closest && _img[i][j].color() == c) {
        closest = i * i + j * j;
        x = i;
        y = j;
      }
    }
  }
}

Image::Image(Image const &img) {

  _height = img._height;
  _width = img._width;
  maxColor = img.maxColor;

  _img = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _img[i] = new Pixel[_width];
  }

  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      _img[i][j] = img._img[i][j];
    }
  }
};

Image &Image::operator=(Image const &img) {

  for (int i = 0; i < _height; i++) {
    delete[] _img[i];
  }
  delete[] _img;

  _height = img._height;
  _width = img._width;
  maxColor = img.maxColor;

  _img = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _img[i] = new Pixel[_width];
  }

  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      _img[i][j] = img._img[i][j];
    }
  }
  return *this;
};

Image::Image(unsigned int width, unsigned int height, int maxColor)
    : _width(width), _height(height), maxColor(maxColor) {
  _img = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _img[i] = new Pixel[_width];
  }
};
Image::Image(unsigned int width, unsigned int height, Color c, int maxColor)
    : _width(width), _height(height), maxColor(maxColor) {
  _img = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _img[i] = new Pixel[_width];
  }
  for (int i = 0; i < _height; i++)
    for (int j = 0; j < _width; j++)
      _img[i][j].set_color(c);
};
Image::Image(char const *fileName) {

  ifstream fin;
  fin.open(fileName);
  char type[10];
  fin >> type;
  if (strcmp(type, "P3")) {
    cout << "WRONG FORMAT" << endl;
  }
  fin >> _width;
  fin >> _height;
  fin >> maxColor;
  _img = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _img[i] = new Pixel[_width];
  }

  int r, g, b;
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      fin >> r >> g >> b;
      _img[i][j] = Pixel(i, j, Color(r, g, b));
    }
  }

  fin.close();
}

Color Image::color(int i, int j) const { return _img[i][j].color(); }
int Image::width() const { return _width; }
int Image::height() const { return _height; }
void Image::set_color(int i, int j, Color c) { _img[i][j].set_color(c); }
void Image::set_pixel(int i, int j, Pixel p) { _img[i][j] = p; }

Image::~Image() {
  for (int i = 0; i < _height; i++) {
    delete[] _img[i];
  }
  delete[] _img;
}

void Image::write(char const *file) {
  char filePath[100] = "./images/";
  strcat(filePath, file);
  // cout<<filePath<<endl;
  ofstream out(filePath);
  out << "P3" << endl;
  out << _width << " " << _height << endl;
  out << maxColor << endl;
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      out << color(i, j) << " ";
    }
    out << endl;
  }
  out.close();
};

int Image::resolution() const { return maxColor; }
