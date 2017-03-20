//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE63_H
#define LEE_LEE63_H


class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1) return 0;

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int a[n];

    int i, j;

    vector<int>& line = obstacleGrid[0];
    a[0] = 1;
    for (j = 1; j < n ; j ++) {
      if (line[j] == 1) a[j] = 0;
      else a[j] = a[j - 1];
    }

    for (i = 1; i < m; i ++) {
      line = obstacleGrid[i];
      if (line[0] == 1) a[0] = 0;
      for (j = 1; j < n ; j ++) {
        if (line[j] == 1) a[j] = 0;
        else a[j] += a[j - 1];
      }
    }

    return a[n -1];
  }
};

#endif //LEE_LEE63_H
