// 14. Longest Common Prefix

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================================

class Solution {
    public:
    string longestCommonPrefix(vector<string> strs) {
        int minLen = INT_MAX;
        for(int i=0; i<strs.size(); i++) {
            int strLen = strs[i].length();
            if(strLen == 0) {
                return "";
            }
            minLen = min(minLen, strLen);
        }

        int count = 0;
        for(int i=0; i<minLen; i++) {
            for(int j=1; j<strs.size(); j++) {
                if(strs[j-1][i] != strs[j][i]) {
                    return strs[0].substr(0,count);
                }
            }
            count++;
        }

        return strs[0].substr(0,count);
    }
};

// ==========================================

int main() {
    
    // vector<string> strs = {"flower", "flo", "flow"};
    // vector<string> strs = {"folower", "flo", "flow"};
    // vector<string> strs = {"flower", "flo", ""};
    // vector<string> strs = {"flower", "flo", "u"};
    vector<string> strs = {"f", "f", "f"};

    Solution sol;
    string ans = sol.longestCommonPrefix(strs);

    for(char item: ans) {
        cout << item << " ";
    }

    cout <<endl;
    
    return 0;
}