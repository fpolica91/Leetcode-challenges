#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int sum = 0;
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root)
      return 0;
    int root_val = root->val;
    if (root->val >= low and root->val <= high)
      sum += root->val;
    rangeSumBST(root->left, low, high);
    rangeSumBST(root->right, low, high);
    return sum;
  }
};