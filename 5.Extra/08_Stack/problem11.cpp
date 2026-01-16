// 1441. Build an Array With Stack Operations

#include<iostream>
#include<vector>
using namespace std;


// ===================================

class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {

        vector<string> vec;

        int i = 0;
        for (int num = 1; num <= n; num++) {
            if(i==t.size()) break;
            if (num == t[i]) {
                vec.push_back("Push");
                i++;
            } else {
                vec.push_back("Push");
                vec.push_back("Pop");
            }
        }

        return vec;
    }
};

// ===================================


int main() {
    Solution sol;
    vector<int> target = {1,3};
    int n = 3;
    vector<string> result = sol.buildArray(target, n);

    for(string s : result) {
        cout << s << " ";
    }
    return 0;
}