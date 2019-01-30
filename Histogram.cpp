#include "Histogram.h"
#include "SpecialImage.h"

void Histogram::renderHistogram(char const *fileName) {

  int height = 0;
  int width = histogram.size();
  for (int i = 0; i < width; i++)
    height = max(height, histogram[i] / 10);

  height++;
  SpecialImage graph(width, height, Color(255, 255, 255));

  for (int i = 0; i < width; i++)
    for (int j = 0; j < histogram[i] / 10; j++)
      graph.set_color(j, i, Color(0, 0, 0));

  std::vector<int> v = findThresholds();
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < height; j++) {
      graph.set_color(j, v[i], Color(255, 0, 0));
    }
  }
  graph.reflectVertical().write(fileName);
}

Histogram::Histogram(Image const &I1, int smooth_factor,
                     int considerationFactor)
    : histogram(I1.resolution() + 1, 0),
      considerationFactor(considerationFactor) {
  resolution = I1.resolution();
  vector<int> raw_histogram(I1.resolution() + 1, 0);
  for (int i = 0; i < I1._height; i++)
    for (int j = 0; j < I1._width; j++) {
      raw_histogram[I1.color(i, j).brightness()]++;
    }

  for (int i = 0; i < I1.resolution(); i++) {
    histogram[i] = raw_histogram[i];
  }

  for (int i = smooth_factor; i < I1.resolution() - smooth_factor; i++) {
    int avg = 0;
    for (int j = i - smooth_factor; j < i + smooth_factor + 1; j++) {
      avg += raw_histogram[j];
    }
    histogram[i] = (avg) / (2 * smooth_factor + 1);
  }
}

vector<int> Histogram::getDistribution() { return histogram; }

vector<int> Histogram::findThresholds() {
  vector<int> thresholds;

  for (int i = considerationFactor; i < resolution - considerationFactor; i++) {
    int flag = 0;
    for (int j = i - considerationFactor; j < i && !flag; j++) {
      if (histogram[j] < histogram[i])
        flag = 1;
    }
    for (int j = i + 1; j < i + considerationFactor + 1 && !flag; j++) {
      if (histogram[j] < histogram[i])
        flag = 1;
    }

    if (!flag && histogram[i]) {
      thresholds.push_back(i);
      i += 2 * considerationFactor + 2;
    }
  }
  return thresholds;
}
