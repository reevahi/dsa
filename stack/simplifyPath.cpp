/*
@author github.com/iitzmahi
Here we just iterate the whole string and chech whether the current
char is / if yes we push in the content gathered in temp string to the stack
according to the conditions and pop only if temp = ..
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string newPath = path + '/';
        string temp = "";
        for (int i = 0; i < newPath.length(); i++) {
            if (newPath[i] == '/') {
                if (temp != "") {
                    if (temp == ".." && !s.empty()) {
                        s.pop();
                    } else if (temp != "." && temp != "..") {
                        s.push(temp);
                    }
                    temp = "";
                }
            } else {
                temp += newPath[i];
            }
        }
        temp = "";
        while (!s.empty()) {
            temp = "/" + s.top() + temp;
            s.pop();
        }
        if (temp == "")
            return "/";
        return temp;
    }
};