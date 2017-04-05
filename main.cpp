#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>


using namespace std;

class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>> &envelopes) {

  }
};

int main() {
  Solution s;
  vector<int> list = {1, 4, 1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 23, 5, 6, 7, 2, 3};
  //vector<int> list = {1, 4, 1, 2, 3, 4, 5, 6, 23, 1, 2, 3, 4};

  cout << s.lengthOfLIS(list) << endl;

  return 0;
}