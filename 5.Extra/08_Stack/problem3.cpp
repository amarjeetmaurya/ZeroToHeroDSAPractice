// 496. Next Greater Element I 
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

// =========================================

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> vec(n, 0);
        int track = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prev = s.top();
                s.pop();
                vec[prev] = i - prev;
            }
            s.push(i);
        }
        return vec;
    }
};

// =========================================


int main() {
    vector<int> numm = {73,74,75,71,69,72,76,73};

    Solution s;
    vector<int> result = s.dailyTemperatures(numm);

    for(int n: result) {
        cout << n << " ";
    }
    
    return 0;
}