// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <iostream>
#include <map>
using namespace std;

string solution(string s)
{
  map<char, int> counts;

  for (int i = 0; i < s.size(); i++)
  {
    char elem = s[i];
    // check if exists
    map<char, int>::iterator it = counts.find(elem);
    // already presented
    if (it != counts.end())
    {
      // pure stackoverflow driven development
      it->second++;
    }
    else
    {
      counts.insert(make_pair(elem, 1));
    }
  }

  bool padding_used = false;
  int normal_value = 0;

  map<char, int>::iterator it2 = counts.begin();

  while (it2 != counts.end()) {
    int value = it2->second;

    if (normal_value == 0)
    {
      normal_value = value;
    }
    else if (abs(normal_value - value) == 1)
    {
      if (padding_used == true) {
        return "NO";
      } else {
        padding_used = true;
      }
    }
    else if (abs(normal_value - value) > 1)
    {
      return "NO";
    }
    it2++;

  }

  return "YES";
}

int main()
{
  string result = solution("abcdefghhgfedecba");
  cout << result << endl;
  return 1;
}
