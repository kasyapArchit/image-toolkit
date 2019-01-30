#ifndef connected_components_H_
#define connected_components_H_

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#include "Image.h"
#include "Pixel.h"


class Connected_Components
{
private:
   int* parent;    //parent array stores the equivalences of labels using union find disjoint structure
   int label_count;  //keeps track of count of labels
   int _height;     // height of image for which connected componenet labelling should be done
   int _width;      // width of image for which connected componenet labelling should be done
   

public:
     Connected_Components();      //default constructor

     Connected_Components(int width,int height);   //constructor

     ~Connected_Components();             // destructor

     Connected_Components(Connected_Components const &obj);   // copy constructor

     Connected_Components& operator=(Connected_Components const &connect_components); //assignment operator overloading
  
    int find(int x,int *parent);    //finds root parent of x 
    
    void Union(int x,int y,int *parent,int *rank);  // union two disjoint subsets x and y
   
    void identify_labels(Image &image);  //identifies and colors the connected components labels of given image

   
};
#endif