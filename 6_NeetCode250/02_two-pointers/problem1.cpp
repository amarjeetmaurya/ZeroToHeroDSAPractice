// 344. Reverse String

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


// =============================================

// class Solution
// {
// public:
//     void reverseString(vector<char> &nums) {
//         int slen = nums.size();
//         for (int i = 0; i < slen/2; i++) {
//             int a=3,b =4;
//             swap(nums[i], nums[slen-i-1]);
//         }
//     }
// };

// class Solution
// {
// public:
//     void reverseString(vector<char> &nums) {
//         int slen = nums.size();
//         reverse(nums.begin(), nums.end());
//     }
// };

// using 2 pointers
class Solution {
public:
    void reverseString(vector<char> &nums) {
        int left = 0, right = nums.size()-1;

        while(left <right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

// ===============================================

int main()
{
    string temp = "abcdef";
    vector<char> str(temp.begin(), temp.end());
    Solution sol;

    sol.reverseString(str);

    for (char val : str) {
        cout << val << " ";
    }

    return 0;
}