// https://leetcode.com/problems/beautiful-array/

#include <iostream>
#include <vector>
using namespace std;

void print_temp(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << " " << endl;
}

// TODO figure out
vector<int> beautiful(int N) {
  vector<int> ret;
      ret.push_back(1);
      while(ret.size() < N){
         vector <int> temp;
         for(int i = 0; i < ret.size(); i++){
            if(ret[i] * 2 - 1 <= N) temp.push_back(ret[i] * 2 - 1);
         }
         for(int i = 0; i < ret.size(); i++){
            if(ret[i] * 2 <= N)temp.push_back(ret[i] * 2);
         }
         ret = temp;
      }
      return ret;
}

int main() {
  print_temp(beautiful(4));
  // [2,1,4,3]
  cout << "YO" << endl;
  return 1;
}
