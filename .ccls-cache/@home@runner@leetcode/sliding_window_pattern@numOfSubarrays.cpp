#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
// Threshold
class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int start = 0;
    int curr_sum = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
      curr_sum += arr[i];
      if (i - start == k - 1) {
        if ((curr_sum / k) >= threshold)
          ans++;

        curr_sum -= arr[start];
        start++;
      }
    }
    return ans;
  }
};