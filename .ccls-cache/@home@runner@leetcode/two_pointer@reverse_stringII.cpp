#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reverse-string-ii/

string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < s.size(); i += 2 * k) {
        int start = i;
        int j = min(start+k, n);
        reverse(s.begin()+start, s.begin()+j);
    }
    return s;
}