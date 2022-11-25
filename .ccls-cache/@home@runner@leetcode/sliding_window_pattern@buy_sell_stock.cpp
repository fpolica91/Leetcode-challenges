#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int MaxProfit(vector<int> stockPrices) {
  int profit = 0;
  int buy = stockPrices[0];
  for (int i = 1; i < stockPrices.size(); i++) {
    if (buy > stockPrices[i]) {
      buy = stockPrices[i];
    } else {
      profit = max(profit, stockPrices[i] - buy);
    }
  }
  // Write your code here
  return profit;
}