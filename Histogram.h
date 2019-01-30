
#ifndef Histogram_H_
#define Histogram_H_
#include <iostream>
#include <vector>
using namespace std;
#include "Image.h"

class Histogram {

private:
  vector<int> histogram;
  int resolution;
  int considerationFactor; // Effects number of thresholds found

public:
  // Smoothness factor smoothens the histogram
  Histogram(Image const &I1, int smooth_factor = 3,
            int considerationFactor = 10);

  void renderHistogram(char const *fileName); // Draws the histogram
  vector<int> getDistribution();              // returns a vector of histogram
  vector<int> findThresholds(); // Finds and returns thresholds, effected by
                                // smoothness and considerationFactor
};

#endif
