//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE26_H
#define LEE_LEE26_H

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();

    if (size == 0) return 0;

    int x = nums[0];
    int i = 1;
    int count = 1;

    while(i < size) {
      if (nums[i] != x) {
        x = nums[i];
        nums[count] = x;
        count ++;
      }

      i ++;
    }

    return count;
  }
};

#endif //LEE_LEE26_H
