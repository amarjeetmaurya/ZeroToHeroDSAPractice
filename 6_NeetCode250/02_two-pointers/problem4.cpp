// 1768. Merge Strings Alternately

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// ========== Using 2 pointers ============

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        string result = "";
        int i = 0;
        while (i < m || i < n) {
            if (i < m) result += word1[i];
            if (i < n) result += word2[i];
            i++;
        }
        return result;
    }
};

// Time Complexity → O(m + n)
// We traverse each character of both strings once. 
// Concatenation happens in linear time relative to total length.

// Space Complexity → O(m + n)
// The result string stores all characters from both inputs. 
// No extra data structures are used beyond that.


// ===============================================

int main() {
    string str1 = "abc", str2 = "pqr";
    Solution sol;

    string ans = sol.mergeAlternately(str1, str2);
    cout << ans << endl; // Output: "apbqcr"

    // Extra test cases
    cout << sol.mergeAlternately("ab", "pqrs") << endl; // "apbqrs"
    cout << sol.mergeAlternately("abcd", "pq") << endl; // "apbqcd"

    return 0;
}
