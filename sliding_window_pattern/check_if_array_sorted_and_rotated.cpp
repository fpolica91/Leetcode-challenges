#include <bits/stdc++.h>
#include <iostream>
#include <vector> 
using namespace std; 


  bool check(vector<int>& nums) {
      int counter = 0;
      for(int i = 0; i < nums.size(); i++){
          // if an element of the left is greater than one on the right, we've found a peak.
          if(nums[i] > nums[(i+1)%nums.size()]){
              counter++;
          }
      }
      if(counter <= 1)
          return true;
      return false;
  }