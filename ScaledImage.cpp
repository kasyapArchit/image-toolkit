#include "ScaledImage.h"
/*ScaledImage::ScaledImage(){

}*/
ScaledImage::~ScaledImage(){

}

ScaledImage::ScaledImage(Image im):Image(im){

	for(int i=0;i<_height;i++){
		for(int j=0;j<_width;j++){
			//this->get_pixel()[j][i].set_x(i);
			//this->get_pixel()[j][i].set_y(j);
			Color c(255,255,255);
			set_color(i,j,c);
		}
	}
	for(int i=0;i<_height/2;i++){
		for(int j=0;j<_width/2;j++){
			//this->get_pixel()[j][i].set_x(i);
			//this->get_pixel()[j][i].set_y(j);
      Color c1(im.color(i*2,j*2).red(),im.color(i*2,j*2).green(),im.color(i*2,j*2).blue());
			set_color(i,j,c1);
		}
	}
	//this->get_pixel()[this->get_w()/2-1][this->get_h()/2-1].set_x(this->get_w()/2);
	//this->get_pixel()[this->get_w()/2-1][this->get_h()/2-1].set_y(this->get_h()/2);
	//this->get_pixel()[this->get_w()/2-1][this->get_h()/2-1].set_color(p[this->get_w()-1][this->get_h()-1].color().red(),p[this->get_w()-1][this->get_h()-1].color().green(),p[this->get_w()-1][this->get_h()-1].color().blue());
}
