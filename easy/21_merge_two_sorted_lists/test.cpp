#include "main.cpp"
#include <cassert>
#include <iostream>
#include <vector>

ListNode *createList(const std::vector<int> &vals) {
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int val : vals) {
    tail->next = new ListNode(val);
    tail = tail->next;
  }
  return dummy.next;
}

std::vector<int> listToVector(ListNode *head) {
  std::vector<int> result;
  while (head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

void freeList(ListNode *head) {
  while (head != nullptr) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

void run_test_case(int test_num, const std::vector<int> &v1,
                   const std::vector<int> &v2,
                   const std::vector<int> &expected) {
  Solution sol;
  ListNode *list1 = createList(v1);
  ListNode *list2 = createList(v2);

  ListNode *merged = sol.mergeTwoLists(list1, list2);
  std::vector<int> result = listToVector(merged);

  if (result != expected) {
    std::cerr << "Test Case " << test_num << " Failed!" << std::endl;
    std::cerr << "Expected: ";
    for (int x : expected)
      std::cerr << x << " ";
    std::cerr << "\nGot:      ";
    for (int x : result)
      std::cerr << x << " ";
    std::cerr << "\n" << std::endl;
    assert(false);
  } else {
    std::cout << "Test Case " << test_num << " Passed!" << std::endl;
  }

  freeList(merged);
}

int main() {
  std::cout << "Running tests for mergeTwoLists...\n" << std::endl;

  // Test Case 1: Example 1 (Standard lists)
  run_test_case(1, {1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});

  // Test Case 2: Example 2 (Both lists empty)
  run_test_case(2, {}, {}, {});

  // Test Case 3: Example 3 (One list empty)
  run_test_case(3, {}, {0}, {0});

  // Test Case 4: Different lengths
  run_test_case(4, {1, 5}, {2, 3, 4, 6}, {1, 2, 3, 4, 5, 6});

  std::cout << "\nAll tests passed successfully!" << std::endl;
  return 0;
}
