// 217. Contains Duplicate

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// class Solution {
//     public:
//     bool containsDuplicates(vector<int> nums) {
//         int n = nums.size();

//         set<int> ss;
//         for(int i=0; i<n; i++ ) {
//              ss.insert(nums[i]);
//         }
//         if(ss.size() != nums.size()) return true;
//         return false;
//     }
// };

class Solution {
    public:
    bool containsDuplicates(vector<int> nums) {
        int n = nums.size();

        set<int> ss;
        for(int i=0; i<n; i++ ) {
            if(ss.count(nums[i])) {
                return true;
            }
            ss.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    
    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {1,2,3,4,5,6,7,7};
    Solution sol;
    cout << (sol.containsDuplicates(nums)?"true":"false") <<endl;
    
    return 0;
}