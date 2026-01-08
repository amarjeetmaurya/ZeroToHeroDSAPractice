// 901. Online Stock Span
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

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
                // cout <<"- ";
                int temp = s.top();
                s.pop();
                s.top() = s.top()-temp;
            }
            else if(tokens[c]=="/") {
                // cout << "/ ";
                int temp = s.top();
                s.pop();
                s.top() = s.top()/temp;
            }
            else if(tokens[c]=="*") {
                // cout <<"* ";
                int temp = s.top();
                s.pop();
                s.top() = s.top()*temp;
            }
            else {
                // cout<< stoi(tokens[c]) << " ";
                s.push(stoi(tokens[c]));
            }
        }
        int result = s.top();
        return result;
    }
};

// =========================================

int main()
{
    vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens1 = {"4","13","5","/","+"};
    vector<string> tokens2 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout << s.evalRPN(tokens);
    cout << s.evalRPN(tokens1);
    cout << s.evalRPN(tokens2);

    return 0;
}
