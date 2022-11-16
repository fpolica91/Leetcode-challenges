#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// 1763. Longest Nice Substring
// https://leetcode.com/problems/longest-nice-substring/

class Solution {
public:
  bool checkValid(vector<int> &chars, string &subs) {
    for (int i = 0; i < subs.size(); i++) {
      char key = subs[i];
      if (islower(key)) {
        if (!(chars[(int)key] > 0) || !(chars[(int)key - 32] > 0)) {
          return false;
        }
      }

      if (isupper(key)) {
        if (!(chars[(int)key] > 0) || !(chars[(int)key + 32] > 0)) {
          return false;
        }
      }
    }
    return true;
  }

  string longestNiceSubstring(string s) {
    string ans = "";

    if (s.size() < 2)
      return "";

    for (int i = 0; i < s.size(); i++) {
      string subs = "";
      vector<int> chars(123, 0);
      int key = (int)s[i];
      chars[key]++;
      subs += s[i];

      for (int j = i + 1; j < s.size(); j++) {
        int k = s[j];
        chars[k]++;
        subs += s[j];
        if (checkValid(chars, subs)) {
          if (ans.size() < subs.size())
            ans = subs;
        }
      }
    }
    return ans;
  }
};

// [a,B, ]