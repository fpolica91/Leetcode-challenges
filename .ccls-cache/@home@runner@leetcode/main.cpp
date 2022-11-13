#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

long long TT(vector<int> &tasks, int space) {

  if (space == 0)
    return tasks.size();
  if (tasks.size() == 0)
    return 0;

  map<int, long> freq;
  long long days = 0;

  for (int i = 0; i < tasks.size(); i++) {
    int curr = tasks[i];
    if (freq.find(curr) != freq.end()) {
      int diff = days - freq[curr] - 1;
      if (diff < space) {
        days += (space - diff);
      }
    }

    freq[curr] = days++;
    cout << curr << " : " << freq[curr] << endl;
  }
  return days;
}

int main() {
  vector<int> arr{1, 2, 1, 2, 3, 1};
  TT(arr, 3);
  return 0;
}