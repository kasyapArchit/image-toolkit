#ifndef Image_64_H_
#define Image_64_H_

#include <vector>
#include "Image.h"

//structure to hold the index values
struct Index_t{
  int _x,_y;
};

class Image_64 : public Image {
public:
  Image_64(char const *fileName); // Reads the Image from a file
  Image_64(const Image &); // Copy constructor

  bool is_minima(int i,int j); //calculates the pixels with min. blue value in the 8-neighbourhood
  //I have considered partial neighbourhoods too
  std::vector<Index_t>& min_pix_arr();  //returns all the minimum places in the image
  Image_64 image_24(std::vector<Index_t> &t);  //colors the 24-neighbourhood minimum points as white and all other as black
  Image_64 gaussian_filter(std::vector<Index_t> &l);	//applies the gaussian filter
};

#endif