//
// Created by kevinlynna on 04/04/2017.
//

#ifndef LEE_LEE300_H
#define LEE_LEE300_H

#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int *max = new int[nums.size()];
    for (typename vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
      scanAndReplace(max, *iter);
    }

    return length;
  }


  void scanAndReplace(int max[], int value) {

    if (length == 0) {
      max[length++] = value;
      return;
    }

    if (max[0] > value) {
      max[0] = value;
      return;
    }

    if (max[length - 1] < value) {
      max[length++] = value;
      return;
    }

    int bottom = 0;
    int len = length;
    int middle = 0;
    int v = 0;

    while (len > 1) {
      middle = bottom + len / 2;
      v = max[middle];

      if (v == value) return;

      if (v > value) {
        len = len / 2;
      } else {
        bottom = middle + 1;
        len = len - len / 2 - 1;
      }
    }

    if (max[bottom] >= value) max[bottom] = value;
    else max[bottom + 1] = value;
  }

 protected:
  int length = 0;

}

#endif //LEE_LEE300_H
