// 49. Group Anagram

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// =============================================

class Solution {
    public:
    vector<vector<string>> groupAnagram(vector<string> strs) {
        vector<vector<string>> result;
        unordered_map<string, int> umap;
        int count = 0;
        for(int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(umap.count(temp)) {
                result[umap[temp]].push_back(strs[i]);
                continue;
            }
            umap[temp] = count;
            count++;
        }
        // cout << "Hey!!!" << endl;
        return result;
    }
};

// ==========================================

int main() {
    vector<string> strs = {"tea", "eat", "ten", "ate", "nat", "bat"};

    Solution sol;
    vector<vector<string>> ans = sol.groupAnagram(strs);

    for(auto item: ans) {
        for(string each : item) {
            cout <<each <<" ";
        }
    }

    cout <<endl;
    
    return 0;
}