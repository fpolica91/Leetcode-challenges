#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];

            if(m.find(key) != m.end()){
                if(abs(i - m[key]) <= k)
                    return true;
            }

            
            m[key] = i;

        }

        return false;

    }
};