#ifndef MAIN_CPP
#define MAIN_CPP

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;

    int carry = 0;
    ListNode dummyNode;
    ListNode *current = &dummyNode;
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
      int val1 = 0;
      int val2 = 0;

      if (l1 != nullptr) {
        val1 = l1->val;
        l1 = l1->next; // Advance l1
      }
      if (l2 != nullptr) {
        val2 = l2->val;
        l2 = l2->next; // Advance l2
      }

      int sum = val1 + val2 + carry;
      carry = sum / 10;

      // Create new node and then set the current pointer to the new node
      current->next = new ListNode(sum % 10);
      current = current->next;
    }

    return dummyNode.next;
  }
};

#endif
