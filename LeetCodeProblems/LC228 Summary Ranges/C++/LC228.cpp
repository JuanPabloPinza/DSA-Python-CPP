#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int> &nums) {
  vector<string> result;

  if (nums.empty()) {
    return result;
  }

  int front = nums[0];

  for (int i = 1; i <= nums.size(); i++) {
    if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
      if (front == nums[i - 1]) {
        result.push_back(to_string(front));
      } else {
        result.push_back(to_string(front) + "->" + to_string(nums[i - 1]));
      }
      if (i < nums.size()) {
        front = nums[i];
      }
    }
  }

  return result;
}

int main() {
  vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
  vector<string> result;
  // Expected: 0 2->4 6 8->9
  result = summaryRanges(nums);

  for (string s : result) {
    cout << s << " ";
  }

  return 0;
}