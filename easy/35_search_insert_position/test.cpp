#include "main.cpp"
#include <cassert>
#include <iostream>

using namespace std;

void run_test_cases() {
  Solution solution;

  assert(solution.searchInsert({1, 3, 5, 6}, 5) == 2);
  cout << "Test 1 passed!" << endl;

  assert(solution.searchInsert({1, 3, 5, 6}, 2) == 1);
  cout << "Test 2 passed!" << endl;

  assert(solution.searchInsert({1, 3, 5, 6}, 7) == 4);
  cout << "Test 3 passed!" << endl;
}

int main() {
  run_test_cases();
  return 0;
}
