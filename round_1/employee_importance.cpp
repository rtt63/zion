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

int get_importance(vector<Employee> employees, int id) {
  Employee head;

  for (auto & employee: employees) {
    if (employee.id == id) {
      head = employee;
      break;
    }
  }

  int getWeight(Employee employee) {
    if (employee->subordinates.size() === 0) {
      return employee->importance;
    }

    int imp = employee->importance;
    for (let i = 0; i < employee->subordinates.size(); i++) {
      imp = imp + getWeight(employee->subordinates[i]);
    }

    return imp;
  }

  return getWeight(head);
}

int main() {
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
