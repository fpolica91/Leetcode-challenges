// 1466. Reorder Routes to Make All Paths Lead to the City Zero
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto &v : connections) {
      adj[v[0]].emplace_back(v[1], 1);
      adj[v[1]].emplace_back(v[0], 0);
    }
    int ans = 0;
    queue<int> q{{0}};
    vector<int> visited(n);
    while (!q.empty()) {
      int source = q.front();
      q.pop();
      visited[source] = true;
      for (auto [ney, cost] : adj[source]) {
        if (visited[ney]) {
          continue;
        }
        q.push(ney);
        ans += cost;
      }
    }
    return ans;
  }
};