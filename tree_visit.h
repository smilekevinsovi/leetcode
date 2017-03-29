//
// Created by kevinlynna on 29/03/2017.
//

#ifndef LEE_TREE_VISIT_H
#define LEE_TREE_VISIT_H


#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef void (*TreeVisitor)(TreeNode *);

// dfs

class DFSTreeVisit {
 public:
  void preOrder(TreeNode *root, TreeVisitor visitor) {
    if (root == nullptr) return;
    stack<TreeNode *> st;
    TreeNode *node;

    st.push(root);

    while (!st.empty()) {
      node = st.top();
      st.pop();

      visitor(node);

      if (node->right) st.push(node->right);
      if (node->left) st.push(node->left);
    }
  }

  void inOrder(TreeNode *root, TreeVisitor visitor) {
    if (root == nullptr) return;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (node || !st.empty()) {
      if (node) {
        st.push(node);
        node = node->left;
      } else {
        node = st.top();
        st.pop();
        visitor(node);

        node = node->right;
      }
    }
  }

  void postOrder(TreeNode *root, TreeVisitor visitor) {
    if (root == nullptr) return;
    stack<TreeNode *> st;
    TreeNode *node = root;
    TreeNode *last = nullptr;

    while (node || !st.empty()) {
      if (node) {
        st.push(node);
        node = node->left;
      } else {
        node = st.top();

        if (node->right && node->right != last) {
          node = node->right;
        } else {
          visitor(node);
          last = node; st.pop();
          node = nullptr;
        }
      }
    }
  }
};

class BFSTreeVisit {
 public:
  void bfs(TreeNode *root, TreeVisitor visitor) {
    if (root == nullptr) return;

    queue<TreeNode *> qu;
    qu.push(root);
    TreeNode *node;

    while (!qu.empty()) {
      node = qu.front(); qu.pop();

      visitor(node);

      if (node->left) qu.push(node->left);
      if (node->right) qu.push(node->right);
    }
  }
};

#endif //LEE_TREE_VISIT_H
