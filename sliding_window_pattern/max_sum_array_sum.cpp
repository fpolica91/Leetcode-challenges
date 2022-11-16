#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxSubArray(vector<int> &nums) {
  int largest = INT_MIN;
  int current = 0;

  for (int i = 0; i < nums.size(); i++) {
    current += nums[i];

    largest = max(largest, current);

    if (current < 0)
      current = 0;
  }
  return largest;
}