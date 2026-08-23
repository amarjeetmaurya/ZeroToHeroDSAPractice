// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
using namespace std;

// Optimal solution using 2 pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

// Time Complexity → 𝑂(𝑛)
// Each element is visited at most once by the two pointers.

// Space Complexity → 𝑂(1)
// No extra data structures are used, only pointers.


// ===============================================

void printVector(const vector<int>& nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Result: "; printVector(res1);

    // Test Case 2
    vector<int> nums2 = {2,3,4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Result: "; printVector(res2);

    return 0;
}
