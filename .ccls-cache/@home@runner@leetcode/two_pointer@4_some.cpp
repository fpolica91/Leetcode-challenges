#include <bits/stdc++.h>
#include <iostream>
#include <vector>
// https : // leetcode.com/problems/4sum/solutions/

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4) {
      return vector<vector<int>>();
    }

    set<vector<int>> s;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++) {
      for (int j = i + 1; j < nums.size() - 2; j++) {
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          long long _sum =
              (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if (_sum == target) {
            s.insert({nums[i], nums[j], nums[left], nums[right]});
            right--;
            left++;
          } else if (_sum > target)
            right--;
          else
            left++;
        }
      }
    }
    return vector<vector<int>>(begin(s), end(s));
  }
};