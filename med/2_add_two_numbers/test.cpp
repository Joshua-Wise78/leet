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
  
  ListNode *result_list = sol.addTwoNumbers(list1, list2);
  std::vector<int> result_vec = listToVector(result_list);
  
  if (result_vec == expected) {
    std::cout << "Test " << test_num << " passed!\n";
  } else {
    std::cout << "Test " << test_num << " FAILED!\n";
    std::cout << "  Expected: ";
    for (int v : expected) std::cout << v << " ";
    std::cout << "\n  Got:      ";
    for (int v : result_vec) std::cout << v << " ";
    std::cout << "\n";
  }
  
  freeList(list1);
  freeList(list2);
  freeList(result_list);
}

int main() {
  // Test 1: Standard case with carry
  run_test_case(1, {2, 4, 3}, {5, 6, 4}, {7, 0, 8});
  
  // Test 2: Zeroes
  run_test_case(2, {0}, {0}, {0});
  
  // Test 3: Different lengths and cascading carries
  run_test_case(3, {9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1});
  
  return 0;
}
