// 448. Find All Numbers Disappeared in an Array

#include<iostream>
#include<vector>
using namespace std;


// =============================================


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};


// ==================================================

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = sol.findDisappearedNumbers(nums);

    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}