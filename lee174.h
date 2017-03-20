//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE174_H
#define LEE_LEE174_H

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b ,c) ((a) < (b) ? MIN(b, c) : MIN(a, c))

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {

    int m = dungeon.size();
    int n = dungeon[0].size();
    int a[n];

    int i, j;

    vector<int>& line = dungeon[m - 1];
    a[n - 1] = line[n - 1];
    for (j = n - 2; j >= 0 ; j --) {
      a[j] = MIN(a[j + 1] + line[j], line[j]);
    }

    for (i = m - 2; i >= 0; i --) {
      line = dungeon[i];
      a[n - 1] = MIN(a[n - 1] + line[n - 1], line[n - 1]);
      for (j = n - 2; j >= 0 ; j --) {
        a[j] = MIN3(a[j + 1] + line[j], a[j] + line[j], line[j]);
      }
    }

    return a[0] >= 0 ? 1 : - a[0] + 1;
  }
};

#endif //LEE_LEE174_H
