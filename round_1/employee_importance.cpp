// https://leetcode.com/problems/employee-importance/
#include <iostream>
#include <vector>
using namespace std;

class Employee {
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

// BFS?
int get_importance(vector<Employee*> employees, int id) {
  int result = 0;
        queue<int> q;
        map<int, Employee*> emps_map;
        vector<Employee*>::iterator it = employees.begin();
        while (it != employees.end()) {
          emps_map[(*it)->id] = (*it);
          // if head
          if ((*it)->id == id) {
            result += (*it)->importance;
            // add target subordinates of head (first hand)
            for (auto& i : (*it)->subordinates) {
              q.push(i);
            }
        }
          it++;
  }
  while (!q.empty()) {
    Employee* temp = emps_map[q.front()];
    q.pop();
    result += temp->importance;
    // add next level subordinates to queue
    for (auto& i : temp->subordinates) {
      q.push(i);
    }
  }
  return result;
}

int main() {
  // dunno how this works :(
  Employee first = {1, 5, {2, 3}};
  Employee second = {2, 3, {}};
  Employee third = {3, 3, {}};
  vector<Employee> employees;
  employees.push_back(first);
  employees.push_back(second);
  employees.push_back(third);
  int result = get_importance(employees, 1);
  cout << result << endl;
  return 1;
}
