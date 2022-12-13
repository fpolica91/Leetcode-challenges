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
  int height(TreeNode *root) {
    if (!root)
      return 0;
    return max(height(root->left), height(root->right)) + 1;
  }

  int traverse(TreeNode *root, int x, int depth, int &ans) {
    if (root == NULL)
      return 0;
    traverse(root->left, x + 1, depth, ans);
    traverse(root->right, x + 1, depth, ans);

    if (!root->left and !root->right) {
      if (depth == x + 1) {
        ans += root->val;
      }
    }

    return ans;
  }

  int deepestLeavesSum(TreeNode *root) {
    int ht = height(root);
    int x = 0;
    int ans = 0;
    int tt = traverse(root, x, ht, ans);
    return tt;
  }
};