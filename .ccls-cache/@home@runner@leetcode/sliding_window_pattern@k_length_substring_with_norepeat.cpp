#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int count = 0;
        int start = 0;
        map<char, int> freq;
        for(int i =0; i < s.size(); i++){
            char key = s[i];
            if(freq.find(key) != freq.end()){
                start = max(start, freq[key] + 1);
                freq[key] = start;
            }
            if(i - start == k - 1){
                count++;
                start++;
            }

            freq[key] = i;
        }
        return count;
    }
};