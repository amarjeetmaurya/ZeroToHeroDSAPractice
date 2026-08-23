// 15. 3Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
};

// Time Complexity → O(n^2)
// Sorting takes O(n log n), and the two-pointer scan for each element takes O(n).
// Overall dominated by O(n^2).

// Space Complexity → O(1)
// Apart from the result storage, no extra data structures are used. Sorting is in-place.


// ===============================================

void print2DVector(const vector<vector<int>>& res) {
    cout << "[ ";
    for (auto& triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {-1,0,1,2,-1,-4};
    auto res1 = sol.threeSum(nums1);
    cout << "Result 1: "; print2DVector(res1);

    // Test Case 2 (empty array)
    vector<int> nums2 = {};
    auto res2 = sol.threeSum(nums2);
    cout << "Result 2: "; print2DVector(res2);

    return 0;
}
