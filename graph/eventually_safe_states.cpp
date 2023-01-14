#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> indegree(n);
    vector<vector<int>> adjList(n);
    queue<int> q;
    vector<int> ans;

    // create adjacency list and count indegrees
    for (int i = 0; i < n; i++) {
      for (auto j : graph[i]) {
        adjList[j].push_back(i);
        indegree[i]++;
      }
    }

    // add all nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (auto neighbor : adjList[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};
