// 150. Evaluate Reverse Polish Notation

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// =====================================================

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stc;

        for (const string &token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                int b = stc.top(); stc.pop();
                int a = stc.top(); stc.pop();

                switch (token[0]) {
                    case '+': stc.push(a + b); break;
                    case '-': stc.push(a - b); break;
                    case '*': stc.push(a * b); break;
                    case '/': stc.push(a / b); break;
                }
            } else {
                stc.push(stoi(token));
            }
        }
        
        return stc.top();
    }
};

// =====================================================


int main() {
    Solution sol;

    // Example test cases
    vector<string> tokens1 = {"2","1","+","3","*"};   // (2 + 1) * 3 = 9
    vector<string> tokens2 = {"4","13","5","/","+"}; // 4 + (13 / 5) = 6
    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // Expected result = 22

    cout << "Test 1 result: " << sol.evalRPN(tokens1) << endl;
    cout << "Test 2 result: " << sol.evalRPN(tokens2) << endl;
    cout << "Test 3 result: " << sol.evalRPN(tokens3) << endl;

    return 0;
}
