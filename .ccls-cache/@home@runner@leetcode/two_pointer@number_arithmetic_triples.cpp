#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int arithmeticTriplets(vector<int> &nums, int diff) {
  int ans = 0;
  // i is our static value, we search thru array for every ith element
  for (int i = 0; i < nums.size() - 2; i++) {
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      if (nums[k] - nums[j] == diff and nums[j] - nums[i] == diff) {
        ans++;
        break;
      }
      // if subtracting i from j gives us a number that is smaller than diff
      //  we need to move the j pointer to a bigger number
      // remember the array is strictly increasing
      else if (nums[j] - nums[i] < diff)
        j++;
      // if the right most minus j are equal to diff, but the j - i are not, we
      // need to break as it is the only way to move the i pointer.
      else if (nums[k] - nums[j] == diff and nums[j] - nums[i] != diff)
        break;
      // else decrement the k integer as the diff is possibly larger than diff
      else
        k--;
    }
  }
  return ans;
}