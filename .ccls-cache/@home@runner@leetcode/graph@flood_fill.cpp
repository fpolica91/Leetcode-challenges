#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int x[4] = {0, 1, -1, 0};
  int y[4] = {1, 0, 0, -1};
  vector<vector<int>> visited;

  bool outOfBounds(vector<vector<int>> &image, int i, int j) {
    return (i > image.size() - 1 or i < 0 or j > image[0].size() - 1 or j < 0 or
            visited[i][j] == -1);
  }

  void dfs(vector<vector<int>> &image, int i, int j, int start_color,
           int color) {

    if (outOfBounds(image, i, j)) {
      return;
    }

    if (image[i][j] == start_color and visited[i][j] != -1) {
      image[i][j] = color;
      visited[i][j] = -1;
      for (int k = 0; k < 4; k++) {
        dfs(image, i + x[k], j + y[k], start_color, color);
      }
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int start_color = image[sr][sc];
    int m = image.size();
    int n = image[0].size();
    visited.resize(m, vector<int>(n, 0));
    if (start_color != color) {
      dfs(image, sr, sc, start_color, color);
    }

    return image;
  }
};