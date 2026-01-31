// 1. Two Sum

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// using Sort Technoque
class Solution2 {
    public:
    vector<int> twoSum(vector<int> nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++) { arr.push_back({nums[i], i}); }

        sort(arr.begin(), arr.end());

        int left = 0, right = n-1;
        while(left< right) {
            int temp = arr[left].first+arr[right].first;
            if(temp<target) {
                left++;
            } else if(temp > target) {
                right--;
            } else {
                return {arr[left].second, arr[right].second};
            }
        }

        return {};
    }
};

// by map
class Solution {
    public:
    vector<int> twoSum(vector<int> nums, int target) {
        int n = nums.size();

        unordered_map<int, int> umap;
        for(int i=0; i<n; i++ ) {
            int key = target - nums[i];
            if (umap.count(key)) {
                return {umap[key], i};
            }
            umap[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    
    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {2,9,11,15,7};
    int target = 9;

    Solution2 sol;
    vector<int> ans = sol.twoSum(nums, target);
    for(int item: ans) {
        cout << item << " ";
    }
    cout <<endl;
    
    return 0;
}