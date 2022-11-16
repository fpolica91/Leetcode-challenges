// 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0;
        double currentAv = 0;
        double finalAverage = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currentAv += nums[i];
            if(i - start + 1 >= k){
                finalAverage = max(finalAverage, (currentAv/k));
                currentAv -= nums[start];
                start++;
            }

        }
        return finalAverage;
    }
};