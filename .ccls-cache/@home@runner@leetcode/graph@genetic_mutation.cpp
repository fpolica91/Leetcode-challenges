#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minMutation(string start, string end, vector<string> &bank) {
    queue<string> q;
    unordered_set<string> seen;
    q.push(start);
    seen.insert(start);
    int steps = 0;
    while (!q.empty()) {
      int len = q.size();
      for (int k = 0; k < len; k++) {
        string node = q.front();
        if (node == end) {
          return steps;
        }
        q.pop();
        for (char c : "ACGT") {
          for (int i = 0; i < node.size(); i++) {
            string neighbor = node;
            neighbor[i] = c;
            if (!seen.count(neighbor) and
                find(bank.begin(), bank.end(), neighbor) != bank.end()) {
              q.push(neighbor);
              seen.insert(neighbor);
            }
          }
        }
      }
      steps++;
    }
    return -1;
  }
};