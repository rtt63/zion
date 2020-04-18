// https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << "" << endl;
}

// find cycle in graph, NOT DONE YET
vector<int> findRedundantConnection(vector<vector<int>> edges) {
  set<int> visited;
  vector<int> result;
  for (int i = 0; i < edges.size(); i++) {
    vector<int> cur = edges[i];
    int n = cur[1];
    auto search = visited.find(n);
    if (search != visited.end()) {
      result = cur;
      break;
    } else {
      visited.insert(n);
    }
  }
  return result;
}

int main() {
  vector<vector<int>> m {{1,4},{3,4},{1,3},{1,2},{4,5}};
  vector<int> r = findRedundantConnection(m);
  print(r);
  cout << "[1,3]" << endl;
  return 1;
}
