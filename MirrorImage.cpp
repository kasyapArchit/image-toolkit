#include "MirrorImage.h"
MirrorImage::MirrorImage(Image im):Image(im){

}
MirrorImage::~MirrorImage(){

}

void MirrorImage::MirrorX(Image im){
  //this->set_size(im.width(),im.height());
  //Pixel **p;
  //p=im.get_pixel();
  for (int i = 0; i < im.height()/2; i++) {
    for (int j = 0; j < im.width(); j++) {
      //this->get_pixel()[i][j].set_x(i);
      //this->get_pixel()[i][j].set_y(j);
      Color c(im.color(i,j).red(),im.color(i,j).green(),im.color(i,j).blue());
      set_color(i,j,c);
      //this->get_pixel()[i][j].set_color();
    }
  }
  int k=0;
  for (int i = im.height()/2; i < im.height(); i++) {
    for (int j = 0; j < im.width(); j++) {
      //this->get_pixel()[i][j].set_x(i);
      //this->get_pixel()[i][j].set_y(j);
      Color c1(color(im.height()/2-k,j).red(),color(im.height()/2-k,j).green(),color(im.height()/2-k,j).blue());
      //this->get_pixel()[i][j].set_color(p[i][im.height()/2-k].color().red(),p[i][im.height()/2-k].color().green(),p[i][im.height()/2-k].color().blue());
      set_color(i,j,c1);
    }
    k++;
  }
  //k=0;
}
void MirrorImage::MirrorY(Image im){
  //this->set_size(im.width(),im.height());
  //Pixel **p;
  //p=im.get_pixel();
  for (int i = 0; i < im.height(); i++) {
    for (int j = 0; j < im.width()/2; j++) {
      //this->get_pixel()[i][j].set_x(i);
      //this->get_pixel()[i][j].set_y(j);
      Color c2(im.color(i,j).red(),im.color(i,j).green(),im.color(i,j).blue());
      //this->get_pixel()[i][j].set_color(p[i][j].color().red(),p[i][j].color().green(),p[i][j].color().blue());
      set_color(i,j,c2);
    }
  }
  int k=0;
  for (int i = 0; i < im.height(); i++) {
    for (int j = im.width()/2; j < im.width(); j++) {
      //cout<<i<<" "<<j<<" "<<im.width()<<" "<<im.height()<<" "<<(im.width()/2-k)<<endl;
      //this->get_pixel()[i][j].set_x(i);
      //this->get_pixel()[i][j].set_y(j);
      Color c3(im.color(i,im.width()/2-k).red(),im.color(i,im.width()/2-k).green(),im.color(i,im.width()/2-k).blue());
      set_color(i,j,c3);
      //this->get_pixel()[i][j].set_color(p[im.width()/2-k][j].color().red(),p[im.width()/2-k][j].color().green(),p[im.width()/2-k][j].color().blue());
      k++;
    }
    k=0;
  }
}
