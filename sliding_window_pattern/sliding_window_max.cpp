#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> largest;
    vector<int> result;
    for (int i = 0; i < k; i++) {
      while (!largest.empty() and nums[i] > nums[largest.back()]) {
        largest.pop_back();
      }
      largest.push_back(i);
    }
    result.push_back(nums[largest.front()]);
    for (int i = k; i < nums.size(); i++) {
      // while deque is not empty and the current number is greater the number
      // in back of deque
      while (!largest.empty() and nums[i] > nums[largest.back()]) {
        largest.pop_back();
      }

      // check if our largest element in deque is out of range, meaning nt part
      // of current window
      while (!largest.empty() and largest.front() <= i - k) {
        largest.pop_front();
      }

      largest.push_back(i);
      result.push_back(nums[largest.front()]);
    }
    return result;
  }
};