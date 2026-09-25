#ifndef MAIN_CPP
#define MAIN_CPP

#include <vector>

class Solution {
public:
  int searchInsert(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};

#endif
