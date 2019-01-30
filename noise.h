#ifndef noise_h_
#define noise_h_
#include<iostream>
#include"Image.h"
#include"Pixel.h"
#include"Color.h"
class noise:public Image{
public:

  noise(int w,int h);
  ~noise();
  noise(const noise &n);
  void compositemage(Image im,float alpha);
};
#endif
