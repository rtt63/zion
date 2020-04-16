// https://leetcode.com/problems/majority-element/
#include <iostream>
#include <map>
#include <array>
using namespace std;

int majority_elem(int ar[], int size)
{
  map<int, int> memo;

  for(int i = 0; i < size; i++) {
    char elem = ar[i];
    map<int, int>::iterator it = memo.find(elem);

    if (it != memo.end())
    {
      it->second++;
    }
    else
    {
      memo.insert(make_pair(elem, 1));
    }
  }

  map<int, int>::iterator it2 = memo.begin();

  while (it2 != memo.end())
  {
    if (it2->second > size / 2) {
      return it2->first;
    }
    it2++;
  }

  return 0;
}

int main()
{
  int ar[3] = {3, 2, 3};
  int result = majority_elem(ar, 3);
  cout << result << endl;
  return 1;
}
