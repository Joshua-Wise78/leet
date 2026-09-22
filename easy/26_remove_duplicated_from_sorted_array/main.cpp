#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0)
      return 0;

    size_t k = 1;
    for (size_t i = 1; i < nums.size() - 1; ++i) {
      if (nums[i] != nums[i - 1]) {
        nums[k] = nums[i];
        k++;
      }
    }
    return k;
  }
};
