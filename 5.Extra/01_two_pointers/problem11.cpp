// 344. Reverse String

#include<iostream>
#include <vector>
using namespace std;


// ========================================================

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        for(int i=0; i<n/2+1; i++) {
            char temp = s[i];
            s[i] = s[n-i];
            s[n-i] = temp;
        }
    }
};

// ========================================================

int main() {
    Solution sol;   
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for(char c : s) {
        cout << c << " ";
    }

    return 0;
}