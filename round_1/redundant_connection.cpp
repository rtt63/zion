// https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
using namespace std;

void print(std::vector<int> nodes) {
  for (auto& node : nodes) {
    std::cout << node << ", ";
  }
  std::cout << "" << std::endl;
}

class DSU {
  std::vector<int> nodes_ids;
  std::vector<int> sets_sizes;

  public:
    DSU(int n) {
      nodes_ids = std::vector<int>(n);
      sets_sizes = std::vector<int>(n);

      for (int i = 0; i < nodes_ids.size(); i++) {
        nodes_ids[i] = i; // link to itself, like separated nodes in a fucking space
        sets_sizes[i] = 1; // each node is a fucking set of one
      }
    }

    int find(int id) {
      int root = id;
      while (nodes_ids[root] != root) {
        root = nodes_ids[root];
      }

      // compress paths
      // all nodes in set should directly point
      // to it's own root
      while (id != root) {
        int next = nodes_ids[id];
        nodes_ids[id] = root;
        id = next;
      }

      return root;
    }

    bool connected(int a, int b) {
      return find(a) == find(b);
    }

    void unify(int a, int b) {
      if (connected(a, b)) {
        return;
      }

      int root1 = find(a);
      int root2 = find(b);

      if (sets_sizes[root1] < sets_sizes[root2]) {
        sets_sizes[root2] += sets_sizes[root1];
        for (int i = 0; i < nodes_ids.size(); i++) {
          if (nodes_ids[i] == root1) {
            nodes_ids[i] = root2;
          }
        }
      } else {
        sets_sizes[root1] += sets_sizes[root2];
        for (int i = 0; i < nodes_ids.size(); i++) {
          if (nodes_ids[i] == root2) {
            nodes_ids[i] = root1;
          }
        }
      }
    }
};

vector<int> findRedundantConnection(vector<vector<int>> edges) {
  DSU dsu(6000);
  for (int i = 0; i < edges.size(); i++) {
    int l = edges[i][0];
    int r = edges[i][1];
    if (dsu.connected(l, r)) {
      return edges[i];
    } else {
      dsu.unify(l, r);
    }
  }
}

int main() {
  // vector<vector<int>> m {{1,4},{3,4},{1,3},{1,2},{4,5}};
  vector<vector<int>> m {{1,2},{2,3},{1,3}};
  vector<int> r = findRedundantConnection(m);
  print(r);
  cout << "[1,3]" << endl;
  return 1;
}

/*
Runtime: 184 ms, faster than 5.18% of C++ online submissions for Redundant Connection.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Redundant Connection.
*/
