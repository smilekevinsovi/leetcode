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

using namespace std;

class Solution {
 public:
  int maxLength(vector<int>& list) {
    map<int, pair<int, int>> max;

    typename vector<int>::iterator iter = list.begin();
    int v = *iter;
    max[v] = {1, 0};
    int max_value = v;
    iter ++;

    for ( ;iter != list.end(); iter ++) {
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
    miter ++) {

      if (miter->second.first > longest) {
        longest = miter->second.first;
      }
    }

    reverselyPrint(longest, max);

    return longest;
  }

  int findAndInsert(int v, int cur, map<int, pair<int, int>>& max) {
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

  void scanAndUpdate(int v, map<int, pair<int, int>>& max) {
    int mvalue = max[v].first;
    int x = max[v].second;
    while (x != 0) {
      mvalue = MAX(max[x].first + 1, mvalue);

      x = max[x].second;
    }

    mvalue = MAX(mvalue, max[v].first);

    max[v].first = mvalue;
  }

  void reverselyPrint(int max_value, map<int, pair<int, int>>& max) {
    int count = max_value;

    for (typename map<int, pair<int, int>>::reverse_iterator iter = max.rbegin();
        iter != max.rend() ;
    iter ++) {

      if (iter->second.first == count) {
        cout << iter->first << " ";
        count --;

        if (count == 0) break;
      }
    }

    cout << endl;
  }
};

#endif //LEE_MAXLENGTHINCREASE_H
