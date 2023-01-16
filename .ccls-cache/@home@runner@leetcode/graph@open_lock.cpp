#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// /https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:
  char getFront(int knob) {
    if (knob < 9)
      knob++;
    else
      knob = 0;
    return knob + '0';
  }
  char getBack(int knob) {
    if (knob > 0)
      knob--;
    else
      knob = 9;
    return knob + '0';
  }

  int openLock(vector<string> &deadends, string target) {
    queue<string> q;
    unordered_set<string> seen;
    int steps = 0;
    string start = "0000";
    int ans = INT_MAX;
    seen.insert(start);
    q.push(start);
    if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
      return -1;
    }

    while (!q.empty()) {
      int len = q.size();
      for (int i = 0; i < len; i++) {
        string current = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
          string forward = current;
          string backward = current;
          if (forward == target) {
            return steps;
          }

          int knob = forward[k] - '0';
          int knob2 = backward[k] - '0';

          forward[k] = getFront(knob);
          backward[k] = getBack(knob2);

          if (!seen.count(forward) and find(deadends.begin(), deadends.end(),
                                            forward) == deadends.end()) {
            seen.insert(forward);
            q.push(forward);
          }
          if (!seen.count(backward) and find(deadends.begin(), deadends.end(),
                                             backward) == deadends.end()) {
            seen.insert(backward);
            q.push(backward);
          }
        }
      }
      steps++;
    }

    return -1;
  }
};