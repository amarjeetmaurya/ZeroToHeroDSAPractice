// 209. Minimum Size Subarray Sum


#include<iostream>
#include <vector>
#include <climits>
using namespace std;

// ========================================================


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int total = 0;
        int result = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            total += nums[right];

            while (total >= target) {
                result = min(result, right - left + 1);
                total -= nums[left];
                left++;
            }
        }

        return (result == INT_MAX) ? 0 : result;
    }
};

// ========================================================


int main() {
    Solution sol;
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}