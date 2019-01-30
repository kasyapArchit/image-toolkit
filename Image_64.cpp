#include "Image_64.h"
using namespace std;

Image_64::Image_64(char const *fileName) : Image(fileName) {}
Image_64::Image_64(const Image &img) : Image(img){};

bool Image_64::is_minima(int i, int j){
  int k = ((i-1) >= 0 ? (i-1) : 0);
  int l = ((j-1) >=0 ? (j-1) : 0);
  for(; k <= i+1 && k < _height ; k++){
    for(int a = l;a <= j+1 && a < _width;a++){
      if(k == i && a == j)
        continue;
      if(color(i,j).blue() >= color(k,a).blue())  
        return false;
    }
  }
  return true;
}

vector<Index_t>& Image_64::min_pix_arr(){
  vector<Index_t>* temp = new vector<Index_t>();
  for(int i = 0; i < _height; i++){
    for(int j = 0; j < _width; j++){
      if(is_minima(i,j)){
        struct Index_t a;
        a._x = i;
        a._y = j;
        (*temp).push_back(a);
      }
    }
  }
  return *temp;
}

Image_64 Image_64::image_24(vector<Index_t> &t){
  Image newImage(_width, _height, Color(0,0,0));
  int count =0;

  for(int i = 0; i < t.size(); i++){
    int k = ((t[i]._x-2) > 0 ? (t[i]._x-2) : 0);
    int l = ((t[i]._y-2) > 0 ? (t[i]._y-2) : 0);

    for(;k <= t[i]._x+2 && k < _height; k++){
      for(;l <= t[i]._y+2 && l < _width; l++){
        newImage.set_color(k, l, Color(255,255,255));
        count++;
      }
    }
  }
  // cout<<count<<endl;
  return newImage;
}

Image_64 Image_64::gaussian_filter(vector<Index_t> &l){
  int g[5][5] = {{1, 4, 7, 4, 1},
                 {4,16,26,16, 4},
                 {7,26,41,26, 7},
                 {4,16,26,16, 4},
                 {1, 4, 7, 4, 1}};

  for(int a = 0; a < l.size(); a++){
    //consider the minima at location (i,j)
    int i = l[a]._x;
    int j = l[a]._y;

    int x,y;    //for the starting point of the 24 neighbour-hood of the minima point
    int x1,y1;  //for finding out the satrting point in the gaussian filter matrix
    x = ((i-2) < 0 ? 0 : (i-2));
    x1 = ((i-2) < 0 ? (2-i) : 0);
    y = ((j-2) < 0 ? 0 : (j-2));
    y1 = ((j-2) < 0 ? (2-j) : 0);

    for(;x <= i+2 && x < _height; x++, x1++){
      int a_y  = y;
      int a_y1 = y1;    

      for(;a_y <= j+2 && a_y < _width; a_y++, a_y1++){
        int temp = int((255*g[x1][a_y1])/273);
        if((*this).color(x, a_y).red() != 255)
          temp = (temp + (*this).color(x, a_y).red())/2;

        (*this).set_color(x, a_y, Color(temp,temp,temp));
      }
    }
  }
  Image temp = (*this);
  // (*this).write("IMT2016064-C.ppm");
  return temp;
}