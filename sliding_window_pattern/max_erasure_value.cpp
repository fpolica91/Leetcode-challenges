#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// https: // leetcode.com/problems/maximum-erasure-value/

int maximumUniqueSubarray(vector<int> &nums) {
  int start = 0;
  int ans = 0;
  int n = nums.size();
  vector<int> prefix(n + 1, 0);
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int curr = nums[i];
    prefix[i + 1] = prefix[i - 1] + curr;
    if (mp.find(curr) != mp.end()) {
      start = max(start, mp[curr] + 1);
    }
    ans = max(ans, prefix[i + 1] - prefix[start]);
    mp[curr] = i;
  }
  return ans;
}
