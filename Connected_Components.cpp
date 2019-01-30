#include "Image.h"
#include "Pixel.h"
#include "connected_components.h"
#include <iostream>
#include <vector>

using namespace std;

Connected_Components::Connected_Components() {}
Connected_Components::Connected_Components(int width, int height)
    : _width(width), _height(height) {
  parent = new int[height * width];
  for (int i = 0; i < height * width; i++) {
    parent[i] = i;
  }
}
Connected_Components::~Connected_Components() { delete[] parent; }
Connected_Components::Connected_Components(Connected_Components const &obj) {
  delete[] parent;
  label_count = obj.label_count;
  _height = obj._height;
  _width = obj._width;
  parent = new int[_width * _height];
  for (int i = 0; i < _height * _width; i++) {
    parent[i] = obj.parent[i];
  }
}
Connected_Components &Connected_Components::
operator=(Connected_Components const &connect_components) {
  delete[] parent;
  label_count = connect_components.label_count;
  _height = connect_components._height;
  _width = connect_components._width;
  parent = new int[_width * _height];
  for (int i = 0; i < _height * _width; i++) {
    parent[i] = connect_components.parent[i];
  }

  return *this;
}

int Connected_Components::find(int x, int *parent) {
  if (parent[x] == x) {
    return x;
  } else {
    return find(parent[x], parent);
  }
}
void Connected_Components::Union(int x, int y, int *parent, int *rank) {
  int xRoot = find(x, parent);
  int yRoot = find(y, parent);
  if (xRoot == yRoot) {
    return;
  } else {
    parent[max(xRoot, yRoot)] = min(xRoot, yRoot);
    rank[xRoot]++;
  }
}
void Connected_Components::identify_labels(Image &image) {
  int *rank = new int[_height * _width];
  int **labels = new int *[_height];
  for (int i = 0; i < _height; i++) {
    labels[i] = new int[_width];
  }
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      labels[i][j] = 0;
    }
  }
  label_count = -1;

  for (int i = 0; i < _height * _width; i++) {
    rank[i] = 0;
  }

  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      if (i == 0) {

        if (j == 0) {
          label_count++;
          labels[i][j] = label_count;
        } else {

          if (image.color(i, j - 1).brightness() ==
              image.color(i, j).brightness()) {
            labels[i][j] = labels[i][j - 1];
          } else {
            label_count++;
            labels[i][j] = label_count;
          }
        }
      }

      else if (j == 0) {
        if (image.color(i - 1, j).brightness() ==
            image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j];
        } else if (image.color(i - 1, j + 1).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j + 1];
        } else {
          label_count++;
          labels[i][j] = label_count;
        }
      } else if (j == _width - 1) {
        if (image.color(i - 1, j - 1).brightness() ==
            image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j - 1];
        } else if (image.color(i - 1, j).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j];
        } else if (image.color(i, j - 1).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i][j - 1];
        } else {
          label_count++;
          labels[i][j] = label_count;
        }
      } else {
        if (image.color(i - 1, j - 1).brightness() ==
            image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j - 1];
        } else if (image.color(i - 1, j).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j];
        } else if (image.color(i - 1, j + 1).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i - 1][j + 1];
        } else if (image.color(i, j - 1).brightness() ==
                   image.color(i, j).brightness()) {
          labels[i][j] = labels[i][j - 1];
        } else {
          label_count++;
          labels[i][j] = label_count;
        }

        if (image.color(i - 1, j - 1).brightness() ==
            image.color(i, j).brightness()) {
          Union(labels[i - 1][j - 1], labels[i][j], parent, rank);
        }
        if (image.color(i - 1, j).brightness() ==
            image.color(i, j).brightness()) {
          Union(labels[i - 1][j], labels[i][j], parent, rank);
        }
        if (image.color(i - 1, j + 1).brightness() ==
            image.color(i, j).brightness()) {
          Union(labels[i - 1][j + 1], labels[i][j], parent, rank);
        }
        if (image.color(i, j - 1).brightness() ==
            image.color(i, j).brightness()) {
          Union(labels[i][j - 1], labels[i][j], parent, rank);
        }
      }
    }
  }
  Color color_set[] = {Color(255, 0, 0),   Color(0, 255, 0),
                       Color(0, 0, 255),   Color(0, 255, 255),
                       Color(255, 0, 255), Color(255, 255, 0)};

  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
        if (image.color(i, j).brightness() == 255) {
          image.set_color(i, j, color_set[find(labels[i][j], parent) % 6]);
        } else if (image.color(i, j).brightness() == 0) {
          image.set_color(i, j, color_set[find(labels[i][j], parent) % 6]);
        }
    }
  }
  image.write("IMT2016037-ConnectedComponents.ppm");
}
