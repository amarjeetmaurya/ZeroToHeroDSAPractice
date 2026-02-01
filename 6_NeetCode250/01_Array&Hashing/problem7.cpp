// 27. Remove Element

#include<iostream>
#include<vector>
using namespace std;


// =============================================

class Solution {
    public:
    int removeElements(vector<int> &nums, int key) {
        vector<int> ans;
        int left = 0, right = nums.size()-1;
        int occure = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == key) {
                occure++;
                continue;
            };
            ans.push_back(nums[i]);
        }

       int i=0;
        for(; i<ans.size(); i++) {
            nums[i] = ans[i];
        }
        for(; i<nums.size(); i++) {
            nums[i] = 0;
        }

        return occure;
    }
};

class Solution2 {
    public:
    int removeElements(vector<int> &nums, int key) {
        int left = 0, right = 0;
        int occure = 0;
        
        while(right<nums.size()) {
            if(nums[right] != key) {
                nums[left] = nums[right];
                left++;
            } else {
                occure++;
            }
            right++;
        }

        return occure;
    }
};

// ==========================================

int main() {
    
    vector<int> nums = {3,2,2,3};
    // vector<int> nums = {1,2,3,4,5,6,7,7};
    int key = 3;

    Solution2 sol;
    cout << sol.removeElements(nums, key) <<endl;
    
    for(int num: nums) {
        cout <<num <<" ";
    }
    cout <<endl;
    
    return 0;
}