#include<iostream>
#include"Image.h"
#include"Pixel.h"
#include"Color.h"
#include"noise.h"
using namespace std;
noise::noise(int w,int h):
  Image(w,h)
{
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        int r=rand()%256;
        int g=rand()%256;
        int b=rand()%256;
        Color *c=new Color(r,g,b);
        set_color(i,j,*c);
    }
  }
}
noise::~noise(){
  //empty
}
noise::noise(const noise &n):
Image(n){
  //empty
}
void noise::compositemage(Image img2,float alpha){
    for (int i = 0; i<_width; i++) {
      for (int j = 0; j<_height; j++) {
        _img[i][j].applyFilter(img2.color(i,j),alpha);
      }
    }
  }
