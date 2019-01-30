

#ifndef Image_H_
#define Image_H_
#include <iostream>
#include <vector>
using namespace std;
#include "Pixel.h"

class Image {

protected:
  unsigned int _width, _height;
  Pixel **_img;
  int maxColor;

public:
  Image(char const *fileName); // Reads the Image from a file
  Image(const Image &);        // Copy constructor
  // Basic constructor, all pixels initialzed to 0
  Image(unsigned int width, unsigned int height, int maxColor = 255);
  // Basic constructor2, all pixels initialzed to color c
  Image(unsigned int width, unsigned int height, Color c, int maxColor = 255);
  ~Image(); // destructor

  Image &operator=(Image const &i1); // Assignment operator

  Color color(int i, int j) const; // getter
  int width() const;               // getter
  int height() const;              // getter
  int resolution() const;          // getter

  void set_color(int i, int j, Color c); // setter
  void set_pixel(int i, int j, Pixel p); // setter

  // Overloaded + operator - helpful in composition
  friend Image operator+(Image const &i1, Image const &i2);
  // Overloaded * operator - helpful in composition
  friend Image operator*(Image const &i1, float f);

  void write(char const *file); // Writes the image to a file
  void findColor(Color c, int &x, int &y);

  friend class Histogram;

};
#endif
