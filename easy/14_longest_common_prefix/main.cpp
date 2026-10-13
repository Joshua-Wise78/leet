#ifndef MAIN_CPP
#define MAIN_CPP

#include <iomanip>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.size() == 0)
      return "";

    std::string prefix = "";
    std::string word = strs[0];

    // Iterate the word length
    for (int i = 0; i < word.length(); ++i) {
      // Grab the character from iteration
      char c = word[i];
      // iterate words in the vector and check if the characters match
      for (int j = 0; j < strs.size(); ++j) {
        std::string checkWord = strs[j];
        if (c != checkWord[i]) {
          return prefix;
        }
      }
      // If we make it thru all words in the list then we append it
      prefix = prefix + c;
    }

    return prefix;
  }
};

#endif
