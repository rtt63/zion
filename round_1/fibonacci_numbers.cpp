// https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem

#include <iostream>
#include <map>
using namespace std;



int fib(int n) {
  map<int, int> memo = {
    {1, 1},
    {2, 1}
  };

  if (memo[n]) {
    return memo[n];
  }

  int i = 3;
  while (i <= n) {
    memo[i] = memo[i - 1] + memo[i - 2];
    i++;
  }

  return memo[n];
}

int main() {
  int result = fib(40);
  cout << result << endl;
  return 1;
}
