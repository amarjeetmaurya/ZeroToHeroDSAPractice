// 1929. Concatenation of Array

#include<iostream>
#include<vector>
using namespace std;


// =========================================================

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};



// ==========================================================

int main() {

    Solution sol;
    vector<int> nums = {1,2,1};
    vector<int> result = sol.getConcatenation(nums);

    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}