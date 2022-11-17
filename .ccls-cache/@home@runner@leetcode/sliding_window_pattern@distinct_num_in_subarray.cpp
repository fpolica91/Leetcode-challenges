// 1852. Distinct Numbers in Each Subarray
#include <bits/stdc++.h>
#include <iostream>
#include <vector> 
using namespace std; 


class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> results;
        int start = 0;
        for(int i = 0; i <= nums.size(); i++){
            if(i - start == k){
                results.push_back(freq.size());
                int l = nums[start];
                freq[l]--;
                if(freq[l] == 0)
                    freq.erase(l);
                start++;
            }
            if(i == nums.size())
                break;
            freq[nums[i]]++;

        }
        return results;
    }
};