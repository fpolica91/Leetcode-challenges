#include "../main.h"

class Interval {
public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> result;
    auto cmp = [](const Interval &a, const Interval &b) {
      return a.start > b.start;
    };
    priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);

    for (const auto &intervals : schedule) {
      for (const auto &interval : intervals) {
        pq.push(interval);
      }
    }

    Interval prev = pq.top();
    pq.pop();

    while (!pq.empty()) {
      Interval curr = pq.top();
      pq.pop();

      if (prev.end < curr.start) {
        result.push_back({prev.end, curr.start});
        prev = curr;
      } else {
        prev.end = max(prev.end, curr.end);
      }
    }

    return result;
  }
};
