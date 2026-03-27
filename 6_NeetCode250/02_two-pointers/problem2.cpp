// 125. Valid Palindrome

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


// =============================================

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.length();
        
//         string str = "";
//         for (int i = 0; i < n; i ++) {
//             if(isalnum(s[i])) {
//                str += tolower(s[i]);
//             }
//         }

//         int left = 0, right = str.length()-1;
//         while(left < right) {
//             if(str[left] != str[right]) 
//                return false;
//             left++;
//             right--;
//         }

//         return true;
//     }
// };


// Using 2 pointers 
class Solution {
public:
    bool alnum(char c) {
        return (
            c >= 'A' && c <= 'Z' || 
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9'
        );
    }
   
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left < right) {

            while(left < right && !alnum(s[left])) {
                left++;
            }
            while(right > left && !alnum(s[right])) {
                right--;
            }
            
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};


// ===============================================

int main()
{
    string str = "A man, a plan, a canal: Panama";
    Solution sol;

    bool ans = sol.isPalindrome(str);
    if(ans) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout <<endl;

    return 0;
}