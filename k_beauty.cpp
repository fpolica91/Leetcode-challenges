
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// 2269. Find the K-Beauty of a Number

class Solution {
public:
  int divisorSubstrings(int num, int k) {
    string number = to_string(num);
    int count = 0;
    int start = 0;
    string s = "";
    for (int i = 0; i < number.size(); i++) {
      s += number[i];
      if (s.size() > k) {
        s.erase(0, 1);
        start++;
      }
      if (stoi(s) > 0) {
        if (num % stoi(s) == 0 and s.size() == k) {
          count++;
        }
      }
    }
    return count;
  }
};