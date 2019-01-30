#include "PrimitiveSquareImage.h"


PrimitiveSquareImage::~PrimitiveSquareImage(){

}
PrimitiveSquareImage::PrimitiveSquareImage(Image im):Image(im){
  //this->set_size(im.get_w(),im.get_h());

  for(int i=0;i<im.width();i++){
    for(int j=0;j<im.height();j++){
      //this->get_pixel()[j][i].set_x(i);
      //this->get_pixel()[j][i].set_y(j);
      Color c(255,255,255);
      set_color(j,i,c);
    }
  }
  for(int j=im.height()/4;j<(3*im.height())/4;j++){
    for(int i=im.width()/4;i<(3*im.width())/4;i++){
      //this->get_pixel()[j][i].set_x(i);
      //this->get_pixel()[j][i].set_y(j);
      Color c1(im.color(j,i).red(),im.color(j,i).green(),im.color(j,i).blue());
      set_color(j,i,c1);
    }
  }
}
