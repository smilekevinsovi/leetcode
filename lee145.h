//
// Created by kevinlynna on 29/03/2017.
//

#ifndef LEE_LEE145_H
#define LEE_LEE145_H

#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode *> st;
    TreeNode *node;
    TreeNode *last = nullptr;
    vector<int> result;
    if (root == nullptr) return result;

    node = root;

    while (node != nullptr || !st.empty()) {

        if (node != nullptr) {
            st.push(node);
            node = node -> left;
        } else {
            node = st.top();

            if (node->right != nullptr && last != node->right) {
                node = node->right;
            } else {
                result.push_back(node->val);
                last = node; st.pop();
                node = nullptr;
            }
        }
    }

    return result;
  }
};

#endif //LEE_LEE145_H
