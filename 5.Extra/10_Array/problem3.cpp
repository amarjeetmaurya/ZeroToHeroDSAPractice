// 485. Max Consecutive Ones

#include<iostream>
#include<vector>
using namespace std;


// =================================

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0, curr = 0;
        for(int i=0; i<nums.size(); i++) {
            cout <<nums[i] <<endl;
            if(nums[i]==1){
                curr++;
            } else {
                result = max(result, curr);
                curr = 0;
            }
        }

        result = max(result, curr);
        return result;
    }
};

// ==================================

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    
    // your code here
    return 0;
}