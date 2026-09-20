#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {

    std::stack<char> paren;

    if (s.length() <= 1) {
      return false;
    }

    for (char c : s) {
      if (c == '{' || c == '(' || c == '[') {
        paren.push(c);
      }
      if (c == '}' || c == ']' || c == ')') {
        if (paren.empty())
          return false;

        char check = paren.top();
        if (c == '}') {
          if (check != '{')
            return false;
        }
        if (c == ')') {
          if (check != '(')
            return false;
        }
        if (c == ']') {
          if (check != '[')
            return false;
        }
        paren.pop();
      }
    }

    if (paren.empty())
      return true;
    else
      return false;
  }
};
