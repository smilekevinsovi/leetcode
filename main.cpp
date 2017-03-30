#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    queue<TreeNode *> queue;
    vector<int> result;
    vector<int> output;

    if (root == nullptr) return result;
    queue.push(root);

    while(!queue.empty()) {
      result.push_back(queue.front()->val); queue.pop();


      if (root->right) queue.push(root->right);
      if (root->left) queue.push(root->left);
    }

    vector<int>::reverse_iterator it = result.rbegin();

    while (it != result.rend()) {
      output.push_back(*it);
      it ++;
    }

    return output;
  }
};
int main() {
  Solution s;
  vector<int> list = {1, 4, 1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 23, 5, 6, 7, 2, 3};

  cout << s.maxLength(list) << endl;

  return 0;
}