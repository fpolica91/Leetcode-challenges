#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://leetcode.com/problems/diet-plan-performance/description/c

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int start = 0; 
        int cals = 0;
        int tt = 0;
        for(int i = 0; i < calories.size(); i++){
            tt+= calories[i];
            if(i - start == k -1){
                if(tt > upper)
                    cals++;
                if(tt < lower)
                    cals--;
                tt-= calories[start];
                start++;
            }
        }
       return cals;
    }
};