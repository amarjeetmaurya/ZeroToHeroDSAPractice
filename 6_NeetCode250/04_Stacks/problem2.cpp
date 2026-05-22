// 20. Valid Parentheses

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// =====================================================

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        stack<char> stc;
        while(i < s.length()) {
            if(s[i] == '(') {
                stc.push(s[i]);
            } else if(s[i] == ')') {
                if(stc.empty() || stc.top() != '(') {
                    return false;
                }
                stc.pop();
            } else if(s[i] == '{') {
                stc.push(s[i]);
            } else if(s[i] == '}') {
                if(stc.empty() || stc.top() != '{') {
                    return false;
                }
                stc.pop();
            } else if(s[i] == '[') {
                stc.push(s[i]);
            } else if(s[i] == ']') {
                if(stc.empty() || stc.top() != '[') {
                    return false;
                }
                stc.pop();
            }
            i++;
        }
        return stc.empty();
    }
};

// =====================================================


int main() {
    Solution sol;

    // Example test cases
    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "([{}])";

    cout << s1 << " -> " << (sol.isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (sol.isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (sol.isValid(s3) ? "Valid" : "Invalid") << endl;

    return 0;
}
