#include "main.cpp"
#include <cassert>
#include <iostream>

using namespace std;

void run_test_cases() {
  Solution solution;

  assert(solution.isValid("()") == true);
  cout << "Test 1 passed!" << endl;

  assert(solution.isValid("()[]{}") == true);
  cout << "Test 2 passed!" << endl;

  assert(solution.isValid("(]") == false);
  cout << "Test 3 passed!" << endl;

  assert(solution.isValid("([]{})") == true);
  cout << "Test 4 passed!" << endl;

  cout << "\n✅ All test cases passed successfully!" << endl;
}

int main() {
  cout << "Running tests for Valid Parentheses...\n" << endl;
  run_test_cases();
  return 0;
}
