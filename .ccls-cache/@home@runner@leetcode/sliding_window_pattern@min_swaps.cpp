#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/submissions/848863236/

class Solution {
public:
  int minSwaps(vector<int> &data) {
    // find out how many ones are in the array
    int ones = 0;
    int currOnes = 0;
    int start = 0;
    int n = data.size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (data[i] == 1)
        ones++;
    }

    if (ones == 1 || ones == 0)
      return 0;

    for (int i = 0; i < n; i++) {

      if (data[i] == 1)
        currOnes++;

      int currlen = i - start + 1;

      if (currlen == ones) {
        ans = min(ans, currlen - currOnes);
        if (data[start] == 1)
          currOnes--;
        start++;
      }
    }

    return ans;
  }
};