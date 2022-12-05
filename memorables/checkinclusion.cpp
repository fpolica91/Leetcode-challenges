#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    map<char, int> freq;
    int matches = 0;
    int start = 0;
    for (int i = 0; i < s1.size(); i++)
      freq[s1[i]]++;

    for (int i = 0; i < s2.size(); i++) {
      char key = s2[i];
      if (freq.find(key) != freq.end()) {
        freq[key]--;
        if (freq[key] == 0) {
          matches++;
        }
      }
      if (freq.size() == matches) {
        return true;
      }

      if (i - start + 1 >= s1.size()) {
        char left = s2[start];
        start++;
        if (freq.find(left) != freq.end()) {
          if (freq[left] == 0) {
            matches--;
          }
          freq[left]++;
        }
      }
    }

    return false;
  }
};