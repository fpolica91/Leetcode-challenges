// 727. Minimum Window Subsequence
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  string minWindow(string s1, string s2) {
    // initialize both pointers to 0;
    int ptr1 = 0;
    int ptr2 = 0;
    int longest_substring = INT_MAX;
    string ans = "";
    // while we haven't reached the end of pointer one.
    while (ptr1 < s1.size()) {

      if (s1[ptr1] == s2[ptr2]) {
        // increment to find the next matching element.
        ptr2++;
        // this means that the first string contains the second string.
        if (ptr2 == s2.size()) {
          ptr2--;
          int start = ptr1;
          // here we will stretch the window from start to end by decrementing
          // the size of start;
          int end = start + 1;
          // we'll iterate backwards to find all the chars of s2
          // abced ace
          while (ptr2 >= 0) {
            if (s1[start] == s2[ptr2]) {
              ptr2--;
            }
            start--;
          }

          start++;
          if (end - start < longest_substring) {
            longest_substring = end - start;
            ans = s1.substr(start, longest_substring);
          }
          ptr1 = start;
          ptr2 = 0;
        }
      }

      ptr1++;
    }
    return ans;
  }
};