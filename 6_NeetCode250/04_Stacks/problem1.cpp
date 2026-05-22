// 682. Baseball Game


#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// =====================================================

class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> stc;

        int i = 0;
        while (i < op.size()) {
            if (op[i] == "D") {
                stc.push(2 * stc.top());
            } else if (op[i] == "C") {
                stc.pop();
            } else if (op[i] == "+") {
                int prev = stc.top();
                stc.pop();
                int temp = prev + stc.top();
                stc.push(prev);
                stc.push(temp);
            } else {
                int temp = stoi(op[i]);
                stc.push(temp);
            }
            i++;
        }

        int sum = 0;
        while (!stc.empty()) {
            sum += stc.top();
            stc.pop();
        }

        return sum;
    }
};

// =====================================================


int main() {
    Solution sol;

    // Example input
    vector<string> ops = {"5","2","C","D","+"};

    int result = sol.calPoints(ops);
    cout << "Final score: " << result << endl;

    return 0;
}
