// https://www.hackerrank.com/challenges/new-year-chaos/problem
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v)
{
  for (int i=0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << "" << endl;
}

void max_bribes(vector<int> v)
{
  print_vector(v);
  int bribes_count = 0;
  for (int i=0; i < v.size();) {
    int elem = v[i];
    if (abs(elem - i) > 2) {
      cout << "Too chaotic" << endl;
      return;
    } else if (elem != i) {
      int buffer = v[i + 1];
      v[i + 1] = v[i];
      v[i] = buffer;
      bribes_count++;
    } else {
      i++;
    }
  }
  cout << " " << bribes_count << endl;
}

int main()
{
  max_bribes({1, 0, 4, 2, 3});
  cout << "/" << endl;
  max_bribes({1, 4, 0, 2, 3});
  // max_bribes({0, 2, 3, 4, 5, 1}); //
  // cout << result << endl;
  return 1;
}
