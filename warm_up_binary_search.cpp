// binary search using vector
#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> v, int target)
{
  int left = 0;
  int right = v.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (v[mid] == target) {
      return mid;
    }
    else if (v[mid] > target) {
      right = mid;
    }
    else if (v[mid] < target) {
      left = mid;
    }
  }

  return -1;
}

int main()
{
  vector<int> v{1, 2, 5, 8, 12, 37, 66, 100};
  int result = binary_search(v, 37);
  cout << result << endl;
  return 1;
}
