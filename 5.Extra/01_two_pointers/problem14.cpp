// 680. Valid Palindrome II

#include<iostream>
#include <vector>
using namespace std;


// ========================================================

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                int l1 = left + 1, r1 = right;
                int l2 = left, r2 = right - 1; 

                while (l1 < r1 && s[l1] == s[r1]) {
                    l1++;
                    r1--;
                }
                if (l1 >= r1) return true;

                while (l2 < r2 && s[l2] == s[r2]) {
                    l2++;
                    r2--;
                }
                return l2 >= r2;
            }
        }
        return true;
    }
};


class Solution2 {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            } else {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
        }
        return true;
    }
};

// ========================================================

int main() {
    Solution sol;
    string s = "abca";
    cout << sol.validPalindrome(s) << endl;
    Solution2 sol2;
    cout << sol2.validPalindrome(s) << endl;

    return 0;
}