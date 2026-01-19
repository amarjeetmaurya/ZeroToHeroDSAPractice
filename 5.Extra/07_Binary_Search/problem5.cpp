// 35. Search Insert Position

#include <iostream>
#include <vector>
using namespace std;

// ========================================================

class Solution
{
public:
    int searchInsert(vector<int> &nums, int t)
    {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == t)
            {
                return mid;
            }
            else if (nums[mid] > t)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

// ========================================================

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << sol.searchInsert(nums, target) << endl;

    target = 2;
    cout << sol.searchInsert(nums, target) << endl;

    target = 7;
    cout << sol.searchInsert(nums, target) << endl;

    target = 0;
    cout << sol.searchInsert(nums, target) << endl;
    return 0;
}