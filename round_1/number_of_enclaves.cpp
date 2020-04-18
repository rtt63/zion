// https://leetcode.com/problems/number-of-enclaves/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << "" << endl;
}

int c(int x, int y, vector<vector<int>> v) {
  if (x < 0 || y < 0 || y > (v.size() - 1) || x > (v[1].size() - 1) || v[x][y] == 0) {
    return 0;
  }
  return 1 + c(x - 1, y, v) + c(x + 1, y, v);
}

int num_enclaves(vector<vector<int>> v) {
  vector<int> values;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int value = c(i, j, v);
      cout << value << endl;
      values.push_back(value);
    }
    cout << "" << endl;
  }
  //
  // print(values);

  return 1;
}

int main() {
  vector<vector<int>> v{{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  int result = num_enclaves(v);
  cout << result << endl;
  return 1;
}
