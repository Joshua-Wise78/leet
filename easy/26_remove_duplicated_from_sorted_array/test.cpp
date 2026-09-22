#include "main.cpp"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void run_test_cases() {
  Solution solution;

  vector<int> nums = {1, 1, 2};

  // Test Case 1
  int k = solution.removeDuplicates(nums);

  assert(k == 2);

  vector<int> expected = {1, 2};
  for (int i = 0; i < k; ++i) {
    assert(nums[i] == expected[i]);
  }
  cout << "Tests compiled successfully!\n";

  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  k = solution.removeDuplicates(nums);
  assert(k == 5);

  expected = {0, 1, 2, 3, 4};
  for (int i = 0; i < k; ++i) {
    assert(nums[i] == expected[i]);
  }
}

int main() {
  run_test_cases();
  return 0;
}
