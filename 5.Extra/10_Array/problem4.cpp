// 645. Set Mismatch

#include<iostream>
#include<vector>
using namespace std;


// ==============================================

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int dup = -1, miss = -1;
        for (int num : nums) {
            freq[num]++;
        }
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2)
                dup = i;
            if (freq[i] == 0)
                miss = i;
        }
        return {dup, miss};
    }
};


// ======================================================

int main() {
    
    Solution sol;
    vector<int> nums = {1,2,2,4};
    vector<int> result = sol.findErrorNums(nums);

    for(int val : result) {
        cout << val << " ";
    }
    // your code here
    return 0;
}