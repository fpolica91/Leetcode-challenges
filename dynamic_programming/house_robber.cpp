#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int process(vector<int> &nums, int i, vector<int> &memo) {
    if (i > nums.size() - 1) {
      return 0;
    }
    if (memo[i] != -1)
      return memo[i];

    int current = nums[i];

    int ans =
        max(process(nums, i + 1, memo), process(nums, i + 2, memo) + nums[i]);
    memo[i] = ans;
    return ans;
  }

  int rob(vector<int> &nums) {
    int ans = INT_MIN;
    vector<int> memo(nums.size() + 1, -1);
    ans = max(ans, process(nums, 0, memo));

    return ans;
  }
};