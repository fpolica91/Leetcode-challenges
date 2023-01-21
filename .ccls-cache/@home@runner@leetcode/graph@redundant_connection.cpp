#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  unordered_map<int, unordered_set<int>> graph;
  unordered_set<int> seen;

  bool dfs(int source, int target) {
    if (seen.count(source) == 0) {
      seen.insert(source);
      if (source == target)
        return true;
      for (auto nei : graph[source]) {
        if (dfs(nei, target)) {
          return true;
        }
      }
    }
    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> res;
    for (auto edge : edges) {
      seen.clear();
      int v = edge[0];
      int u = edge[1];
      if (graph.count(v) && graph.count(u) && dfs(v, u)) {
        res.push_back(v);
        res.push_back(u);
        break;
      }
      graph[v].insert(u);
      graph[u].insert(v);
    }
    return res;
  }
};
