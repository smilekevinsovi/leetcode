//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE27_H
#define LEE_LEE27_H

#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int size = nums.size();

    if (size == 0) return 0;

    int i = 0;
    int count = 0;

    while(i < size) {
      if (nums[i] != val) {
        nums[count] = nums[i];
        count ++;
      }

      i ++;
    }

    return count;
  }
};

#endif //LEE_LEE27_H
