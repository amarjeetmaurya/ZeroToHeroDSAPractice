// 238. Product of Array Except Self

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ========================================================

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pfix = 1;
        vector<int> ans(n, 1);
        for(int i=0; i<nums.size(); i++) {
            ans[i] = pfix;
            pfix *= nums[i];
        }

        int sfix = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *= sfix;
            sfix *= nums[i];
        }
        
        return ans;
    }
};
// ========================================================

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> result = sol.productExceptSelf(nums);
    for(int val : result) {
        cout << val << " ";
    }
}