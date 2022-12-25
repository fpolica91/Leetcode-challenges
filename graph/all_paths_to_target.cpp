#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  void dfs(vector<vector<int>> &graph, int v, int target,
           vector<int> &current) {

    current.push_back(v);

    if (v == target) {
      ans.push_back(current);
    }

    for (int node : graph[v]) {
      dfs(graph, node, target, current);
      current.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int target = graph.size() - 1;

    vector<int> current;
    dfs(graph, 0, target, current);

    return ans;
  }
};