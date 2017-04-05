//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_MAXLENGTHINCREASE_H
#define LEE_MAXLENGTHINCREASE_H

#define MAX(a, b) ((a) > (b)? (a) : (b))

#include <iostream>
#include <vector>
#include <string>
#include <map>

// basic theory :
//   do not calculate max length in one position, but max length for value which is at the position.
//
//   1. create one container to store max length for each value at now
//   2. from 0 -> n, iterator each position, suppose the value at the position is V
//   3. find out the max length for value stored yet which is less the V, suppose K, then set max length for V as K + 1
//   4. at end, scan whole max length container, find the max one
//
//   since the value may be discrete, one list as max length container may helps.
//   also one hash quick jump table helps too.
//   time complexity is based on : 1. length of sequence N; 2. value range M. which is O(NM)
//   normally M ~ N, then O(N^2)

using namespace std;

class SolutionON2 {
 public:
  int maxLength(vector<int> &list) {
    map<int, pair<int, int>> max;

    typename vector<int>::iterator iter = list.begin();
    int v = *iter;
    max[v] = {1, 0};
    int max_value = v;
    iter++;

    for (; iter != list.end(); iter++) {
      v = *iter;

      if (max.find(v) != max.end()) {
        scanAndUpdate(v, max);
      } else {
        findAndInsert(v, max_value, max);
        if (v > max_value) max_value = v;
      }
    }

    int longest = 0;
    for (typename map<int, pair<int, int>>::iterator miter = max.begin();
         miter != max.end();
         miter++) {

      if (miter->second.first > longest) {
        longest = miter->second.first;
      }
    }

    reverselyPrint(longest, max);

    return longest;
  }

  int findAndInsert(int v, int cur, map<int, pair<int, int>> &max) {
    if (v > cur) max[v] = {1, cur};
    else {
      int pre;
      while (cur > v) {
        pre = cur;
        cur = max[cur].second;
      }

      max[pre] = {max[pre].first, v};
      max[v] = {1, cur};
    }

    scanAndUpdate(v, max);
  }

  void scanAndUpdate(int v, map<int, pair<int, int>> &max) {
    int mvalue = max[v].first;
    int x = max[v].second;
    while (x != 0) {
      mvalue = MAX(max[x].first + 1, mvalue);

      x = max[x].second;
    }

    mvalue = MAX(mvalue, max[v].first);

    max[v].first = mvalue;
  }

  void reverselyPrint(int max_value, map<int, pair<int, int>> &max) {
    int count = max_value;

    for (typename map<int, pair<int, int>>::reverse_iterator iter = max.rbegin();
         iter != max.rend();
         iter++) {

      if (iter->second.first == count) {
        cout << iter->first << " ";
        count--;

        if (count == 0) break;
      }
    }

    cout << endl;
  }
};


// improved one O(NlogN)
//   It is not necessary to store each value's max length. We only need to record the min value for each length as far
//   as now we visited yet.
//
//   It is because the bigger value one could be replace by smaller one if they provide same max length now. So we only
//   need to record the min value so far provide one max length value.
//
//   be care the value stored in max length container is strictly incremental, so the scan process for one value could
//   use binary search which leading time complexity into (N, M same as up one) : O(NlogM), normally M ~ N, O(NlogN)


class SolutionONLOGN {
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
};

// Two dimension's incremental sequence


#endif //LEE_MAXLENGTHINCREASE_H
