// 150. Evaluate Reverse Polish Notation


#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// ========================================================

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // for()
        stack<int> s;
        for(int c=0; c<tokens.size(); c++) {
            if(tokens[c]=="+") {
                // cout <<"+ ";
                int temp = s.top();
                s.pop();
                s.top() = s.top()+temp;
            }
            else if(tokens[c]=="-") {
                int temp = s.top();
                s.pop();
                s.top() = s.top()-temp;
            }
            else if(tokens[c]=="/") {
                int temp = s.top();
                s.pop();
                s.top() = s.top()/temp;
            }
            else if(tokens[c]=="*") {
                int temp = s.top();
                s.pop();
                s.top() = s.top()*temp;
            }
            else {
                s.push(stoi(tokens[c]));
            }
        }
        int result = s.top();
        return result;
    }
};

// ========================================================

int main() {
    
    Solution sol;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << sol.evalRPN(tokens) << endl;

    return 0;
}
