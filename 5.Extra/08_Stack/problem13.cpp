// 636. Exclusive Time of Functions

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// ========================================================


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> vec(n, 0);
        stack<int> stc;

        int prev = 0;
        for (string log : logs) {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int fid = stoi(log.substr(0, p1));
            int t = stoi(log.substr(p2 + 1));
            string ty = log.substr(p1 + 1, p2 - p1 - 1);

            if (ty == "start") {
                if (!stc.empty()) {
                    vec[stc.top()] += t - prev;
                }
                stc.push(fid);
                prev = t;
            } else {
                cout << stc.top() <<" " << t << "-" << prev << "+" <<1 <<endl;
                vec[stc.top()] += t - prev + 1;
                cout <<vec[stc.top()] <<endl;
                stc.pop();
                prev = t + 1;
            }
        }

        return vec;
    }
};


// ========================================================


int main() {
    Solution sol;
    int n = 2;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> result = sol.exclusiveTime(n, logs);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}
