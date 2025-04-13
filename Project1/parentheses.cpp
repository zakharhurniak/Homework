#include "parentheses.h"
#include <stack>

bool areParenthesesBalanced(const std::string& expr) {
    std::stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            if ((c == ')' && s.top() != '(') ||
                (c == ']' && s.top() != '[') ||
                (c == '}' && s.top() != '{')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
