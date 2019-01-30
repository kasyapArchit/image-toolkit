
#ifndef SpecialImage_H_
#define SpecialImage_H_
#include <iostream>
#include <vector>
using namespace std;
#include "Image.h"
#include "Pixel.h"

class SpecialImage : public Image {
public:
  SpecialImage(char const *fileName); // Reads the Image from a file
  SpecialImage(Image const &I1, Image const &I2, float alpha); // Composition
  SpecialImage(const Image &); // Copy constructor
  // Basic constructor, all pixels initialzed to 0
  SpecialImage(unsigned int width, unsigned int height, int maxColor = 255);
  // Basic constructor, all pixels initialzed to color c
  SpecialImage(unsigned int width, unsigned int height, Color c,
               int maxColor = 255);

  SpecialImage invert();
  SpecialImage reflectHorizontal();
  SpecialImage reflectVertical();
  SpecialImage binarize(int threshold, Color low = Color(0, 0, 0),
                        Color high = Color(255, 255, 255));

  // SpecialImage applyMask(const Image &mask);
};


#endif
