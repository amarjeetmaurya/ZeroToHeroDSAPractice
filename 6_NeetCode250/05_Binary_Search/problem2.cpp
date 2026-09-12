#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    // Test cases
    vector<int> targets = {5, 2, 7, 0};
    for (int target : targets) {
        int result = sol.searchInsert(nums, target);
        cout << "Target " << target << " -> Insert position: " << result << endl;
    }

    return 0;
}
