// 1480. Running Sum of 1d Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i];
            result.push_back(temp);
        }

        return result;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    vector<int> result = sol.runningSum(nums);

    cout << "Running sum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
