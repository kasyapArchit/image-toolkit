#include "Color.h"
#include "Histogram.h"
#include "Image.h"
#include "Image_64.h"
#include "Pixel.h"
#include "SpecialImage.h"
#include "PrimitiveSquareImage.h"
#include "MirrorImage.h"
#include "ScaledImage.h"
#include "connected_components.h"
#include "noise.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void IMT2016124(char const *file)  {
  cout << "IMT2016124: Running task 8 " << endl;
  Image k(file);
  noise *np = new noise(k.width(), k.height());
  np->write("noising.ppm");
  np->compositemage(k, 0.2);
  np->write("composit.ppm");
  Histogram h(k, 3, 10);
  h.renderHistogram("mama.ppm");
  int height = np->height();
  int width = np->width();
  vector<int> v = h.findThresholds();
  Image C =
      SpecialImage(k).binarize(v[1], Color(0, 0, 0), Color(255, 255, 255));
  C.write("binarymama.ppm");
  Connected_Components connected_components(width, height);
  connected_components.identify_labels(C);
  cout << "IMT2016124: Completed task 8 " << endl << endl;
}

void IMT2016037(char const *file) {
  cout << "IMT2016037: Running task 6 " << endl;

  Image I037(file);
  Histogram h(I037, 3, 10);
  h.renderHistogram("IMT2016037-histogram.ppm");
  vector<int> v = h.findThresholds();
  int height=I037.height();
  int width=I037.width();
  int median_threshold;
  if(v.size()%2==0) { median_threshold=(v[(v.size()/2)]+v[(v.size()/2)-1])/2;}
  else{ median_threshold=(v[(v.size()/2)+1])/2;}
  Image C = SpecialImage(I037).binarize(median_threshold, Color(0, 0,0),Color(255,255,255));
  C.write("IMT2016037(binarized-image)-C.ppm");
  Connected_Components connected_components(width,height);
  connected_components.identify_labels(C);

  cout << "IMT2016037: Completed task 6 " << endl << endl;
}

void IMT2016085(char const *file) {
  cout << "IMT2016085: Running task 7 \n";

  Image im(file);
  ScaledImage sim(im);
  sim.write("IMT2016085-1st.ppm");
  MirrorImage msimx(im);
  MirrorImage msimy(msimx);
  msimx.MirrorX(sim);
  msimy.MirrorY(msimx);
  PrimitiveSquareImage pima(msimy);
  msimx.write("IMT2016085-2nd.ppm");
  msimy.write("IMT2016085-3nd.ppm");
  pima.write("output_task<7>_imt<2016085>.ppm");


  cout << "IMT2016085: Completed task 7\n\n";
}

void IMT2016105(char const *file) {
  cout << "IMT2016105: Running task 1 " << endl;
  Image I1051(file);
  Image I1052(file);
  int width = I1051.width();
  int height = I1051.height();

  // creating hole1//e min(floor(image_width*0.125), floor(image_height*0.125))
  float cx1 = width / 4;
  float cy1 = height / 4;
  float cx2 = (width / 4) * 3;
  float cy2 = height / 4;
  float cx3 = width / 4;
  float cy3 = (height / 4) * 3;
  float cx4 = (width / 4) * 3;
  float cy4 = (height / 4) * 3;

  float r = min((width * 0.125), (height * 0.125));

  Color w(255, 255, 255);
  // clipping
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width / 2; j++) {
      if (pow(pow(i - cy1, 2) + pow(j - cx1, 2), 0.5) > r) {
        I1051.set_color(i, j, w);
      }
    }
  }
  for (int i = 0; i < height / 2; i++) {
    for (int j = width / 2; j < width; j++) {

      if (pow(pow(i - cy2, 2) + pow(j - cx2, 2), 0.5) > r) {
        I1051.set_color(i, j, w);
      }
    }
  }
  for (int i = height / 2; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      if (pow(pow(i - cy3, 2) + pow(j - cx3, 2), 0.5) > r) {
        I1051.set_color(i, j, w);
      }
    }
  }
  for (int i = height / 2; i < height; i++) {
    for (int j = width / 2; j < width; j++) {
      if (pow(pow(i - cy4, 2) + pow(j - cx4, 2), 0.5) > r) {
        I1051.set_color(i, j, w);
      }
    }
  }
  I1051.write("IMT2016105-C.ppm");
  I1052 = SpecialImage(I1052).reflectHorizontal();
  // stenciling
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width / 2; j++) {
      if (pow(pow(i - cy1, 2) + pow(j - cx1, 2), 0.5) < r) {
        I1052.set_color(i, j, w);
      }
    }
  }
  for (int i = 0; i < height / 2; i++) {
    for (int j = width / 2; j < width; j++) {

      if (pow(pow(i - cy2, 2) + pow(j - cx2, 2), 0.5) < r) {
        I1052.set_color(i, j, w);
      }
    }
  }
  for (int i = height / 2; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      if (pow(pow(i - cy3, 2) + pow(j - cx3, 2), 0.5) < r) {
        I1052.set_color(i, j, w);
      }
    }
  }
  for (int i = height / 2; i < height; i++) {
    for (int j = width / 2; j < width; j++) {
      if (pow(pow(i - cy4, 2) + pow(j - cx4, 2), 0.5) < r) {
        I1052.set_color(i, j, w);
      }
    }
  }
  I1052.write("IMT2016105-D.ppm");
  // clubbing two images
  Image composite = (I1051 * 0.5) + (I1052 * 0.5);
  composite.write("output_task<1>_imt<2016105>.ppm");
  cout << "IMT2016105: Completed task 1\n\n";
}

void IMT2016064(char const *file) {
  cout << "IMT2016064: Running task 2 \n";

  Image im(file);
  Image inv = SpecialImage(im).reflectHorizontal();
  inv.write("IMT2016064-A.ppm");
  vector<Index_t> min_px = Image_64(inv).min_pix_arr();
  // cout << "Size = " << min_px.size() << endl;
  Image_64 im_24 = Image_64(inv).image_24(min_px);
  im_24.write("IMT2016064-B.ppm");
  Image im_gsf = im_24.gaussian_filter(min_px);
  im_gsf.write("IMT2016064-C.ppm");
  Image result = SpecialImage(im_gsf, inv, 0.75);
  result.write("output_task<2>_imt<2016064>.ppm");
  cout << "IMT2016064: Completed task 2\n\n";
}

void IMT2016008(char const *file) {
  cout << "IMT2016008: Running task 5 " << endl;

  Image I1(file);
  Histogram h(I1, 3, 10);

  h.renderHistogram("IMT2016008-histogram.ppm");
  vector<int> v = h.findThresholds();

  if (v.size() >= 2) {
    Image C = SpecialImage(I1).binarize(v[0], Color(0, 0, 255));
    Image D = SpecialImage(I1).binarize(v[1], Color(0, 255, 255));
    C.write("IMT2016008-C.ppm");
    D.write("IMT2016008-D.ppm");
    SpecialImage result(D, C, 0.2);
    result.write("output_task<5>_imt<2016008>.ppm");
  } else {
    Image C = SpecialImage(I1).reflectVertical();
    Image D = SpecialImage(I1).reflectHorizontal();
    C.write("IMT2016008-C.ppm");
    D.write("IMT2016008-D.ppm");
    SpecialImage result(D, C, 0.2);
    result.write("IMT2016008.ppm");
  }

  cout << "IMT2016008: Completed task 5 " << endl << endl;
}
