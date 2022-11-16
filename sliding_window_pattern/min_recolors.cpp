// 2379. Minimum Recolors to Get K Consecutive Black Blocks
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black_blocks=0;
        int start = 0;
        int min_ops = INT_MAX;
        for(int i =0; i < blocks.size(); i++){
            if(blocks[i] == 'B') black_blocks++;
            
            int substr_size = i - start + 1;
            // if the size of substring is greater or equal to k, we've found a substring of valid size.
            // check how many changes it will require to be valid
            if(substr_size >= k){
                min_ops = min(min_ops, i - start + 1 - black_blocks);
                if(blocks[start] == 'B') black_blocks--;
                start++;
            }

        }
        return min_ops;
    }
    int minimumRecolors2(string blocks, int k) {
        int ops = 0;
        int ll = INT_MAX;
        for(int i = 0; i <= blocks.size() - k; i++){
            ops = 0;
            for(int j = i; j < blocks.size(); j++){
                if(j - i == k)
                    break;
                if(blocks[j] == 'W')
                    ops++;
            }

            ll = min(ll, ops);
            
        }
        return ll;
    }
    int minimumRecolors3(string blocks, int k) {
        map<char, int> freq;
        int start=0;
        int max_freq=0;
        int ops = INT_MAX;
        for(int i = 0; i < blocks.size(); i++){
            freq[blocks[i]]++;
            if(blocks[i] == 'B') max_freq=max(max_freq, freq[blocks[i]]);

            if(i - start + 1 >= k){
                freq[blocks[start]]--;
                if(freq[blocks[start]] == 0) freq.erase(blocks[start]);
                ops = min(ops, i - start + 1 - max_freq);
                start++;
            }
        }
        return ops;
    }
};