// https://www.hackerrank.com/challenges/pairs/problem
#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
// can do better?
int decision(vector<int> arr, int k)
{
  int counter = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i; j < arr.size(); j++)
    {
      if (abs(arr[i] - arr[j]) == k)
      {
        counter++;
      }
    }
  }

  return counter;
}

int main()
{
  int result = decision({1, 2, 3, 4}, 1);
  cout << result << endl;
  return 0;
}
