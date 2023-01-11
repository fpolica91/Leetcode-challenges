// 1091. Shortest Path in Binary Matrix
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int x[8] = {-1, -1, -1, +0, +0, +1, +1, +1};
  int y[8] = {-1, +0, +1, -1, +1, -1, +0, +1};

  bool isValid(int i, int j, vector<vector<int>> &grid) {
    return (i >= 0 and i <= grid.size() - 1 and j >= 0 and
            j <= grid[0].size() - 1 and grid[i][j] == 0);
  }

  void bfs(vector<vector<int>> &grid, vector<vector<int>> &dist, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      if (!isValid(r, c, grid))
        continue;

      for (int k = 0; k < 8; k++) {
        int nr = r + x[k];
        int nc = c + y[k];
        if (isValid(nr, nc, grid) and dist[nr][nc] > dist[r][c] + 1) {
          dist[nr][nc] = dist[r][c] + 1;
          q.emplace(nr, nc);
        }
      }
    }
  }

  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (grid.size() == 1 and grid[0][0] == 1)
      return -1;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 1;
    bfs(grid, dist, 0, 0);

    return dist[n - 1][m - 1] != INT_MAX ? dist[n - 1][m - 1] : -1;
  }
};