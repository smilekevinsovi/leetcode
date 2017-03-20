#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main() {
  Solution s;
  vector<int> list = {1, 4, 1 , 2, 3,4, 5, 1, 1, 2, 3, 4 ,5 ,6 ,7 ,8, 9,23,5 ,6,7, 2, 3};

  cout << s.maxLength(list) << endl;

  return 0;
}