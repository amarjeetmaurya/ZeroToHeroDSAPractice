// 1470. Shuffle the Array

#include<iostream>
#include<vector>
using namespace std;


// =========================================================

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int len = nums.size()/2;
        for(int i=0; i<len; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[len+i]);
        }
        return res;
    }
};


// ==================================================================


int main() {
    
    Solution sol;
    vector<int> nums = {2,5,1,3,4,7};
    vector<int> result = sol.shuffle(nums, 3);

    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}