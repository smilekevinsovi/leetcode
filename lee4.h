//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE4_H
#define LEE_LEE4_H

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0) return fetchMediaImmediate(nums2);
    if (nums2.size() == 0) return fetchMediaImmediate(nums1);

    auto total = (nums1.size() + nums2.size());
    auto meida_num = total % 2 == 0? total / 2 - 1 : total / 2;

    int pos1 = 0;
    int pos2 = 0;
    int x = 0;

    while ((pos1 + pos2) <= meida_num) {
      x = compareAndForward(nums1, nums2, pos1, pos2);
    }

    if (total % 2 == 0) {
      auto y = compareAndForward(nums1, nums2, pos1, pos2);
      return ((double)x + y) / 2;
    } else {
      return (double)x;
    }
  }

  int compareAndForward(vector<int>& nums1, vector<int>& nums2, int& pos1, int& pos2) {
    if (pos1 == nums1.size()) return nums2[pos2 ++];
    if (pos2 == nums2.size()) return nums1[pos1 ++];
    if (nums1[pos1] < nums2[pos2]) {
      return nums1[pos1 ++];
    } else {
      return nums2[pos2 ++];
    }
  }

  double fetchMediaImmediate(vector<int>& nums) {
    auto size = nums.size();
    auto med = size % 2 == 0? size / 2 - 1: size / 2;

    if (size % 2 == 0) return ((double)(nums[med] + nums[med + 1])) / 2;
    else return (double)nums[med];
  }
};

#endif LEE_LEE4_H