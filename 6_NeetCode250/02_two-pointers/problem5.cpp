// 88. Merge Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// optimal solution 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int last = nums1.size() - 1;

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[last--] = nums1[p1--];
            } else {
                nums1[last--] = nums2[p2--];
            }
        }
    }
};

// Time Complexity → 𝑂(𝑚+𝑛)
// Space Complexity → 𝑂(1)

// ===============================================

void printVector(const vector<int>& nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    sol.merge(nums1, 3, nums2, 3);
    cout << "Merged: "; printVector(nums1);

    // Test Case 2
    nums1 = {1};
    nums2 = {};
    sol.merge(nums1, 1, nums2, 0);
    cout << "Merged: "; printVector(nums1);

    return 0;
}
