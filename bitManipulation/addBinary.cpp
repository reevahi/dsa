/*
@author github.com/iitzmahi
Solution is self explainatory
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i, j;
        i = a.length() - 1;
        j = b.length() - 1;
        string ans = "";
        bool carry = false;
        while (i >= 0 && j >= 0) {
            if (carry) {
                if (a.at(i) == '0' && b.at(j) == '0') {
                    ans = "1" + ans;
                    carry = false;
                } else if (a.at(i) == '1' && b.at(j) == '1') {
                    ans = "1" + ans;
                } else {
                    ans = "0" + ans;
                }
            } else {
                if (a.at(i) == '1' && b.at(j) == '1') {
                    ans = "0" + ans;
                    carry = true;
                } else if (a.at(i) == '0' && b.at(j) == '0') {
                    ans = "0" + ans;
                } else {
                    ans = "1" + ans;
                }
            }
            i--;
            j--;
        }
        while (i >= 0) {
            if (carry) {
                if (a.at(i) == '1') {
                    ans = "0" + ans;
                } else {
                    ans = "1" + ans;
                    carry = false;
                }
            } else {
                if (a.at(i) == '1') {
                    ans = "1" + ans;
                } else {
                    ans = "0" + ans;
                }
            }
            i--;
        }
        while (j >= 0) {
            if (carry) {
                if (b.at(j) == '1') {
                    ans = "0" + ans;
                } else {
                    ans = "1" + ans;
                    carry = false;
                }
            } else {
                if (b.at(j) == '1') {
                    ans = "1" + ans;
                } else {
                    ans = "0" + ans;
                }
            }
            j--;
        }
        if (carry) {
            ans = "1" + ans;
        }
        return ans;
    }
};