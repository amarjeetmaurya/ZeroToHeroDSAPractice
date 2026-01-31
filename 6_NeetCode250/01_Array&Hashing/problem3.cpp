// 242. Valid Anagram

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    bool validAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++ ) {
            umap[s[i]]++;
            umap[t[i]]--;
        }

        for(auto item: umap) {
            if(item.second!=0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    
    string str1 = "listen";
    string str2 = "nelist";
    Solution sol;
    cout << (sol.validAnagram(str1, str2)?"true":"false") <<endl;
    
    return 0;
}