#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int x[4] = {0, 0, 1, -1};
  int y[4] = {1, -1, 0, 0};
  int count = 0;

  bool isWater(vector<vector<int>> &grid, int i, int j) {
    return isValid(grid, i, j) and grid[i][j] == 0;
  }

  bool isVisited(vector<vector<int>> &grid, int i, int j) {
    return isValid(grid, i, j) and grid[i][j] == -1;
  }

  bool isValid(vector<vector<int>> &grid, int i, int j) {
    return (i >= 0 and i <= grid.size() - 1 and j >= 0 and
            j <= grid[i].size() - 1);
  }

  int functionalDfs(vector<vector<int>> &grid, int i, int j) {
    if (!isValid(grid, i, j))
      return 1;

    if (isWater(grid, i, j))
      return 1;

    if (isVisited(grid, i, j))
      return 0;

    if (grid[i][j] == 1)
      grid[i][j] = -1;

    int res = 0;
    for (int k = 0; k < 4; k++) {
      int new_row = i + x[k];
      int new_col = j + y[k];
      res += functionalDfs(grid, new_row, new_col);
    }

    return res;
  }

  void bfs(vector<vector<int>> &grid, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    if (grid[i][j] == 1)
      grid[i][j] = -1;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++) {
        int rr = r + x[k];
        int cc = c + y[k];
        if (isValid(grid, rr, cc) and grid[rr][cc] == 1) {
          q.push({rr, cc});
          grid[rr][cc] = -1;
        }
        if (!isValid(grid, rr, cc)) {
          count++;
        } else if (grid[rr][cc] == 0) {
          count++;
        }
      }
    }
  }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (grid[i][j] == -1)
      return 0;
    if (grid[i][j] == 1) {
      grid[i][j] = -1;
    }

    for (int k = 0; k < 4; k++) {
      int new_row = i + x[k];
      int new_col = j + y[k];
      if (isValid(grid, new_row, new_col) and
          !isWater(grid, new_row, new_col)) {
        if (grid[new_row][new_col] != -1) {
          dfs(grid, new_row, new_col);
        }
      }
      if (!isValid(grid, new_row, new_col) or isWater(grid, new_row, new_col)) {
        count++;
      }
    }

    return count;
  }

  int islandPerimeter(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          bfs(grid, i, j);
        }
      }
    }
    return count;
  }
};