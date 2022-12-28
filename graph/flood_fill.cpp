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

class InterativeSolution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    vector<vector<int>> visited;

    bool isValid(vector<vector<int>> &image, int i, int j, int match_this_color){
        return (i <= image.size() -1 and i >= 0 and j <= image[i].size() - 1 and 
                j>=0 and image[i][j] == match_this_color);
    }
    
    void bfs(vector<vector<int>> &image, int i, int j, int match_this_color, int change_to_this_color){
        queue<pair<int, int>> q;
        
        if(!isValid(image, i, j, match_this_color))
            return;
       
        q.push({i, j});
        
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
             image[row][col] = change_to_this_color;
            for(int k = 0; k < 4; k++){
                if(isValid(image, row + x[k],  col + y[k],  match_this_color)){
                    q.push({row + x[k],  col + y[k]});
                }
            }
        }

    }

    

      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int change_to_this_color) {
        int match_this_color = image[sr][sc];
        if(match_this_color != change_to_this_color){
            bfs(image, sr, sc, match_this_color, change_to_this_color);
        }
        
        
        return image;

    }
};