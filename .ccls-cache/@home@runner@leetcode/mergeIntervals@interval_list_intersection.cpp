#include "../main.h"

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> ans;
    if (!firstList.size() or !secondList.size())
      return ans;

    int k = 0;
    int i = 0;

    while (i < firstList.size() and k < secondList.size()) {
      int start = max(firstList[i][0], secondList[k][0]);
      int end = min(firstList[i][1], secondList[k][1]);

      if (start <= end) {
        ans.push_back({start, end});
      }
      if (firstList[i][1] < secondList[k][1])
        i++;
      else
        k++;
    }
    return ans;
  }
};