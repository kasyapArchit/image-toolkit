#pragma once
#include <iostream>
#include <fstream>
#include "Image.h"
using namespace std;
class ScaledImage:public Image
{
public:
	ScaledImage();
	~ScaledImage();
	ScaledImage(Image im);
	
};
