// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << "" << endl;
}

int activityNotifications(vector<int> expenditure, int d) {
  int count = 0;
  for (int i = d; i < expenditure.size(); i++) {
    vector<int> story(expenditure.begin() + i - d, expenditure.begin() + i);
    print(story);
    int tmp = 0;
    for (int j = 0; j < story.size(); j++) {
      tmp += story[j];
    }
    if (((tmp * 2) / story.size()) <= expenditure[i]) {
      count++;
    }
  }
  return count;
}

// timeout large input
int main() {
  // vector<int> data{1, 2, 3, 4, 4};
  vector<int> data{10, 20, 30, 40, 50};
  int result = activityNotifications(data, 3);
  cout << result << endl;
  return 1;
}
