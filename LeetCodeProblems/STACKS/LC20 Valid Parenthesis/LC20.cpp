// If my idea is ok, we can easly check with stacks if
//  We split the array into 2 and if the 2nd piece rotated are the same, the
//  parenthesis are the same.
#include <iostream>
#include <stack>
#include <string>

// #include <vector>

// template<typename T>
using namespace std;

// class Stack{
//     public:
//     std::vector<std::string> stack;
//     std::string pop(){
//         if (stack.empty()) {

//         }
//     }
// };

class Solution {
public:
  // Steps:
  // Check if the length of the string is pair
  // Turn the 2nd half of the string in a vector
  // Reverse the vector and convert it into a string
  // Comparte if are the same.

  // 8 / 2 = 4
  bool isValid(string s) {
    std::stack<char> queue;
    if (s.length() % 2 != 0) {
      return false;
    }

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
        queue.push(s[i]);
      } else {
        if (queue.empty()) {
          return false;
        }
        if ((queue.top() == '{' && s[i] == '}') ||
            (queue.top() == '[' && s[i] == ']') ||
            (queue.top() == '(' && s[i] == ')')) {
          queue.pop();
        } else {
          return false; 
        }
      }
    }
    return queue.empty();
  }
};

int main() {
  string s = "([}}])";
  Solution xd;
  std::cout << xd.isValid(s);
  return 0;
}
