//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE64_H
#define LEE_LEE64_H

#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();
    int a[n];

    int i, j;

    vector<int>& line = grid[0];
    a[0] = line[0];
    for (j = 1; j < n ; j ++) {
      a[j] = a[j - 1] + line[j];
    }

    for (i = 1; i < m; i ++) {
      line = grid[i];
      a[0] += line[0];
      for (j = 1; j < n ; j ++) {
        a[j] = line[j] + MIN(a[j], a[j - 1]);
      }
    }

    return a[n -1];
  }
};

#endif //LEE_LEE64_H
