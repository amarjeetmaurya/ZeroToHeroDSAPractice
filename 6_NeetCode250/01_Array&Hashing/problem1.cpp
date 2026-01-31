// 1929. Concatenation of Array

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> getConcatenation(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i=0; i<n; i++ ){
            ans[i] = nums[i];
            ans[n+i] = nums[i];
        }
        return ans;
    }
};

int main() {
    
    vector<int> nums = {2,4,5,6,7,8};
    Solution sol;
    vector<int> ans = sol.getConcatenation(nums);
    
    for(int item: ans) {
        cout <<item <<" ";
    }
    cout <<endl;
    return 0;
}