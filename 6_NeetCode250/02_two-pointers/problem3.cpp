// 125. Valid Palindrome II

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


// =============================================


// ========== Using 2 pointers ============
// class Solution {
// public:

//     bool isPalindrome(string s) {
//         int left = 0, right = s.length() - 1;
//         while (left < right) {
//             if (s[left] != s[right]) {

//                 int templ = left + 1, tempr = right;
//                 bool ans1 = true;
//                 while (templ < tempr) {
//                     if (s[templ != tempr]) {
//                         ans1 = false;
//                         break;
//                     }
//                 }

//                 templ = left;
//                 tempr = right-1;
//                 bool ans2 = true;
//                 while (templ < tempr) {
//                     if (s[templ != tempr]) {
//                         ans2 = false;
//                         break;
//                     }
//                 }
//                 // cout << ans1 <<" - " <<ans2 <<endl;
//                 return (ans1 || ans2);
//             }
//             left++;
//             right--;
//         }

//         return true;
//     }
// };


// ========= using recursion ===========
class Solution {
public:
    bool isPal(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++; right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                bool ans1 = isPal(s, left + 1, right);
                bool ans2 = isPal(s, left, right - 1);
                return (ans1 || ans2);
            }
            left++; right--;
        }
        return true;
    }
};


// ===============================================

int main()
{
    string str = "abbcba";
    Solution sol;

    bool ans = sol.validPalindrome(str);
    if (ans) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl;

    return 0;
}