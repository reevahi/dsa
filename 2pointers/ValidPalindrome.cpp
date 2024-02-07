/*
Here we have to just check that the given string is a plaindrome or not
To this we can simply use isalnum stl function of cpp
but here we can define a user defined func to check whether the character is
alphanumeric or not After checking this we can easily implement the 2 pointers
approach where we put first pointer at 0 and second pointer at the last string
index, and then if both of the pointers are pointing at valid alphanumeric
characters and both are equal in lower case then we just move the pointers and
if not then return false, if the pointers are not pointing at the alphanumeric
characters then we just move the pointers accordingly link:
https://leetcode.com/problems/valid-palindrome
*/
class Solution {
public:
    bool isAlphaNumeric(char c) {
        if (((tolower(c) >= 'a') && (tolower(c) <= 'z')) ||
            ((tolower(c) >= '0') && (tolower(c) <= '9')))
            return true;
            else
            return false;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (!isAlphaNumeric(s[i]))
                i++;
            else if (!isAlphaNumeric(s[j]))
                j--;
            else if ((tolower(s[i]) != (tolower(s[j]))))
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};