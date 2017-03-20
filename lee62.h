//
// Created by kevinlynna on 20/03/2017.
//

#ifndef LEE_LEE62_H
#define LEE_LEE62_H

class Solution_Low {
 public:
  int uniquePaths(int m, int n) {
    int a[m][n];

    int i,j;

    for (i = 0; i < m; i ++) {
      for (j = 0; j < n; j ++) {
        a[i][j] = 0;
      }
    }

    for (i = 0; i < m; i ++) {
      a[i][0] = 1;
    }

    for (j = 1; j < n; j ++) {
      a[0][j] = 1;
    }

    for (i = 1; i < m; i ++) {
      for (j = 1; j < n; j ++) {
        a[i][j] = a[i - 1][j] + a[i][j - 1];
      }
    }

    return a[i - 1][j - 1];
  }
};

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int a[n];

    int i, j;

    for (j = 0; j < n ; j ++) {
      a[j] = 1;
    }

    for (i = 1; i < m; i ++) {
      for (j = 1; j < n ; j ++) {
        a[j] += a[j - 1];
      }
    }

    return a[n -1];
  }
};

#endif //LEE_LEE62_H
