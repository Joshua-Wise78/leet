#include "main.cpp"
#include <cassert>
#include <iostream>
#include <vector>

void run_test_case(int test_num, const std::vector<int> &height,
                   const int &expected) {
  Solution sol;

  int resultVal = sol.maxArea(height);
  if (resultVal == expected) {
    std::cout << "Test " << test_num << " passed\n";
  } else {
    std::cout << "Test " << test_num << "failed\n";
    std::cout << "Expected: " << expected << "\n";
    std::cout << "Got: " << resultVal << "\n";
  }
}

int main() {
  run_test_case(1, {1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
  run_test_case(2, {1, 1}, 1);
  return 0;
}
