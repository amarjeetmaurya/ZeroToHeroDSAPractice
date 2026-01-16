// 1365. How Many Numbers Are Smaller Than the Current Number

#include<iostream>
#include<vector>
using namespace std;


// ============================================


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int occ = 0;
            for (int j = 0; j < nums.size(); j++) {
                if(nums[j] < nums[i]) {
                    occ++;
                }
            }
            result.push_back(occ);
        }
        return result;
    }
};


// =================================================


int main() {
    
    Solution sol;
    vector<int> nums = {8,1,2,2,3};
    vector<int> result = sol.smallerNumbersThanCurrent(nums);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}