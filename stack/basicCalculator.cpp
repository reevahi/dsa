/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            } else if (s[i] >= '0' && s[i] <= '9') {
                int temp = s[i] - '0';
                i++;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if (sign == 1) {
                    sum += temp;
                } else {
                    sum -= temp;
                }
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == ')') {
                sign = st.top();
                st.pop();
                if (sign == 1) {
                    sum = st.top() + sum;
                } else {
                    sum = st.top() - sum;
                }
                st.pop();
            }
        }
        return sum;
    }
};