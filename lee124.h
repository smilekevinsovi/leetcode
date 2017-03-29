//
// Created by kevinlynna on 27/03/2017.
//

#ifndef LEE_LEE124_H
#define LEE_LEE124_H

#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TESTPOSADD(a, b) ((a) > 0 ? (a) + (b) : (b))
class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    int maxNodeValue = -9999999;

    visitNode(root, maxNodeValue);

    return maxNodeValue;
  }

  int visitNode(TreeNode *root, int& maxNodePre) {
    int left = root->left != nullptr ? visitNode(root->left, maxNodePre) : -9999999;
    int right = root->right != nullptr ? visitNode(root->right, maxNodePre) : -9999999;

    int maxLength = TESTPOSADD(left, root->val);
    maxLength = TESTPOSADD(right, maxLength);

    maxNodePre = MAX(maxNodePre, maxLength);

    int maxSide = MAX(left, right);

    return TESTPOSADD(maxSide, root->val);
  }
};

class Solution_No_Recrusive {
 public:
  int maxPathSum(TreeNode *root) {
    stack<TreeNode*> calStack;
    queue<TreeNode *> bfsQueue;

    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
      TreeNode * cur = bfsQueue.front();
      bfsQueue.pop();

      if (cur->left) {
        bfsQueue.push(cur->left);
      }

      if (cur->right) {
        bfsQueue.push(cur->right);
      }

      calStack.push(cur);
    }

    int maxValue = -99999999;

    while (!calStack.empty()) {
      TreeNode *cur = calStack.top();
      calStack.pop();

      int left = cur->left != nullptr ? cur->left->val : -9999999;
      int right = cur->right != nullptr ? cur->right->val : -9999999;

      int maxLength = TESTPOSADD(left, cur->val);
      maxLength = TESTPOSADD(right, maxLength);

      maxValue = MAX(maxValue, maxLength);

      int maxSide = MAX(left, right);

      cur->val = TESTPOSADD(maxSide, cur->val);
    }

    return maxValue;
  }

};


#endif //LEE_LEE124_H
