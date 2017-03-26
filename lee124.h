//
// Created by kevinlynna on 27/03/2017.
//

#ifndef LEE_LEE124_H
#define LEE_LEE124_H

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

#endif //LEE_LEE124_H
