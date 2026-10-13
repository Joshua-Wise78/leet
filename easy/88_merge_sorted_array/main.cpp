#ifndef MAIN_CPP
#define MAIN_CPP

#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    // If nums1 is empty just set it to nums2 and return
    if (nums1.size() == 0) {
      nums1 = nums2;
      return;
    }
    // If there is nothing to compare on just return
    if (nums2.size() == 0)
      return;

    int ptr1 = m - 1;
    int ptr2 = n - 1;
    int write = m + n - 1;
    while (ptr1 >= 0) {
      if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) {
        nums1[write] = nums1[ptr1];
        ptr1 = ptr1 - 1;
      } else {
        nums1[write] = nums2[ptr2];
        ptr2 = ptr2 - 1;
      }
      write = write - 1;
    }
  }
};

#endif
