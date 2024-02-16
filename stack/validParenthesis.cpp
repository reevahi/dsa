/*
@author github.com/iitzmahi
Here we pop an element only if it has ist opening counterpart at the top of
the stack otherwise we just push in the character, and at last we check if the
stack is still filled then that means that there has been a mismatch in the
order of parenthesis/ invalid parenthesis
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            char temp = s[i];
            if (temp == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if (temp == '}' && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (temp == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                stk.push(temp);
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};