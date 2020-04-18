// https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>> edges) {
  // union find
}

int main() {
  // vector<vector<int>> m {{1,4},{3,4},{1,3},{1,2},{4,5}};
  vector<vector<int>> m {{1,2},{2,3},{1,3}};
  vector<int> r = findRedundantConnection(m);
  print(r);
  cout << "[1,3]" << endl;
  return 1;
}
