// 1768. Merge Strings Alternately

#include<iostream>
#include <vector>
using namespace std;


// ========================================================

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string result = "";
        int i=0;
        for(; i<min(word1.size(), word2.size()); i++) {
            result+=word1[i];
            result+=word2[i];
        }

        if(word1.size() == word2.size()) return result;

        int max = (word1.size() > word2.size())?1:2;
        if(max==1) {
            result.append(word1.substr(i));
        } else {
           result.append(word2.substr(i));
        }

        return result;
    }
};
// ========================================================

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "pqr";
    cout << sol.mergeAlternately(word1, word2) << endl;

    word1 = "ab";
    word2 = "pqrs";
    cout << sol.mergeAlternately(word1, word2) << endl;

    return 0;
}