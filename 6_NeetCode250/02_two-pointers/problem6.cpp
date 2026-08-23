// 26. Remove Duplicates from Sorted Array

#include <iostream>
#include <vector>
using namespace std;


// Optimal solution using 2 pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // length of unique elements
    }
};

// Time Complexity → 𝑂(𝑛)
// Each element is visited once by the fast pointer j.

// Space Complexity → 𝑂(1)
// In-place modification, no extra data structures used.


// ===============================================

void printVector(const vector<int>& nums, int length) {
    for (int k = 0; k < length; k++) cout << nums[k] << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1,1,2};
    int len1 = sol.removeDuplicates(nums1);
    cout << "Length: " << len1 << " | Result: ";
    printVector(nums1, len1);

    // Test Case 2
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    int len2 = sol.removeDuplicates(nums2);
    cout << "Length: " << len2 << " | Result: ";
    printVector(nums2, len2);

    return 0;
}
