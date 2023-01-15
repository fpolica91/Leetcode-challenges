// 1129. Shortest Path with Alternating Colors
// 1091. Shortest Path in Binary Matrix
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &r,
                                       vector<vector<int>> &b) {
    vector<vector<pair<int, int>>> adj(n);
    int red = 0;
    int blue = 1;
    vector<int> ans(n, -1);
    ans[0] = 0;
    for (auto &v : r) {
      adj[v[0]].push_back({v[1], red});
    }

    for (auto &v : b) {
      adj[v[0]].push_back({v[1], blue});
    }

    vector<vector<bool>> visited(n, vector<bool>(2));
    queue<vector<int>> q;
    q.push({0, 0, -1});
    visited[0][1] = true;
    visited[0][0] = true;
    ans[0] = 0;

    while (!q.empty()) {
      auto current = q.front();
      int source = current[0];
      int distance = current[1];
      int prev_color = current[2];
      q.pop();
      for (auto &[neighbor, color] : adj[source]) {
        if (!visited[neighbor][color] and color != prev_color) {
          visited[neighbor][color] = true;
          q.push({neighbor, distance + 1, color});
          if (ans[neighbor] == -1) {
            ans[neighbor] = distance + 1;
          }
        }
      }
    }
    return ans;
  }
};