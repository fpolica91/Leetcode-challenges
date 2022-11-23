#include "sliding_window_pattern/max_erasure_value.cpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};

  cout << "the answer is: " << maximumUniqueSubarray(nums) << endl;
  return 0;
}