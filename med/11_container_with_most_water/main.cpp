#ifndef MAIN_CPP
#define MAIN_CPP

#include <vector>

class Solution {
public:
  int maxArea(const std::vector<int> &height) {
    if (height.size() == 0)
      return 0;

    int left = 0;
    int area = 0;
    int right = height.size() - 1;
    while (left < right) {
      int temp = 0;
      if (height[left] < height[right]) {
        temp = (right - left) * height[left];
        left++;
      } else {
        temp = (right - left) * height[right];
        right--;
      }

      if (temp > area) {
        area = temp;
      }
    }
    return area;
  }
};

#endif
