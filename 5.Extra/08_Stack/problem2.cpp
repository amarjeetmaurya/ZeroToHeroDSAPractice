// 496. Next Greater Element I 
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> result(n, -1);
        for (int i = 0; i < 2*n; i++) {
            int num = nums[i % n];
            while (!s.empty() && nums[s.top()] < num) {
                result[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }
        return result;
    }
};

int main() {
    vector<int> numm = {1,2,3,4,3};

    Solution s;
    vector<int> result = s.nextGreaterElements(numm);

    for(int n: result) {
        cout << n << " ";
    }
    
    return 0;
}