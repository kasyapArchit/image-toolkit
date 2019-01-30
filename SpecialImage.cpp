#include "SpecialImage.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

SpecialImage::SpecialImage(char const *fileName) : Image(fileName) {}
SpecialImage::SpecialImage(Image const &I1, Image const &I2, float alpha)
    : Image(I1.width(), I1.height(), I1.resolution()) {
  (*this) = I1 * (1 - alpha) + I2 * alpha;
}
SpecialImage::SpecialImage(const Image &img) : Image(img){};
SpecialImage::SpecialImage(unsigned int width, unsigned int height,
                           int maxColor)
    : Image(width, height, maxColor){};
SpecialImage::SpecialImage(unsigned int width, unsigned int height, Color c,
                           int maxColor)
    : Image(width, height, c, maxColor){};

// SpecialImage SpecialImage::applyMask(const Image &mask) {
//   Image newImage(_width, _height, maxColor);
//   for (int i = 0; i < _height; i++) {
//     for (int j = 0; j < _width; j++) {
//       Color mask_color = mask.color(i, j);
//       Color original = color(i, j);
//       int r = mask_color.red() ? original.red() : 0;
//       int g = mask_color.green() ? original.green() : 0;
//       int b = mask_color.blue() ? original.blue() : 0;
//       newImage.set_color(i, j, Color(r, g, b));
//     }
//   }
//   return newImage;
// }
SpecialImage SpecialImage::binarize(int threshold, Color low, Color high) {
  Image newImage(_width, _height, maxColor);
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      newImage.set_color(i,j,color(i, j).brightness() > threshold ? high : low);
    }
  }
  return newImage;
}

SpecialImage SpecialImage::invert() {
  Image newImage(_width, _height, maxColor);
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      Color original = color(i, j);
      int r = maxColor - original.red();
      int g = maxColor - original.green();
      int b = maxColor - original.blue();
      newImage.set_color(i, j, Color(r, g, b));
    }
  }
  return newImage;
}
SpecialImage SpecialImage::reflectHorizontal() {
  Image newImage(_width, _height, maxColor);
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < (_width + 1) / 2; j++) {
      Color color1 = color(i, j);
      Color color2 = color(i, _width - j - 1);
      newImage.set_color(i, j, color2);
      newImage.set_color(i, _width - j - 1, color1);
    }
  }
  return newImage;
}
SpecialImage SpecialImage::reflectVertical() {
  Image newImage(_width, _height, maxColor);
  for (int i = 0; i < (_height + 1) / 2; i++) {
    for (int j = 0; j < _width; j++) {
      Color color1 = color(i, j);
      Color color2 = color(_height - i - 1, j);
      newImage.set_color(i, j, color2);
      newImage.set_color(_height - i - 1, j, color1);
    }
  }
  return newImage;
}
