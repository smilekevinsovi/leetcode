//
// Created by kevinlynna on 29/03/2017.
//

#ifndef LEE_LEE297_H
#define LEE_LEE297_H

#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionCallRecrusive {
 public:
  virtual ~SolutionCallRecrusive() {
    delete(reOne);
  }

  void recoverTree(TreeNode* root) {
    visitNode(root);

    int temp = lessOne->val;
    lessOne->val = moreOne->val;
    moreOne->val = temp;
  }

  void visitNode(TreeNode * node) {
    if (node == nullptr) return ;

    visitNode(node->left);

    if (moreOne == nullptr && preOne->val > node->val) moreOne = preOne;
    if (moreOne != nullptr && preOne->val > node->val) lessOne = node;

    preOne = node;

    visitNode(node->right);
  }

 protected:
  TreeNode * preOne = new TreeNode(-999999);
  TreeNode * reOne = preOne;
  TreeNode * lessOne = nullptr;
  TreeNode * moreOne = nullptr;
};

class Solution {
 public:
  virtual ~Solution() {
    delete(reOne);
  }

  void recoverTree(TreeNode* root) {
    TreeNode * node = root;
    stack<TreeNode *> st;

    while (node || !st.empty()) {
      while (node) {
        st.push(node);
        node = node->left;
      }

      node = st.top(); st.pop();

      if (moreOne == nullptr && preOne->val > node->val) moreOne = preOne;
      if (moreOne != nullptr && preOne->val > node->val) lessOne = node;

      node = node->right;
    }

    int temp = lessOne->val;
    lessOne->val = moreOne->val;
    moreOne->val = temp;
  }


 protected:
  TreeNode * preOne = new TreeNode(-999999);
  TreeNode * reOne = preOne;
  TreeNode * lessOne = nullptr;
  TreeNode * moreOne = nullptr;
};

#endif //LEE_LEE297_H
