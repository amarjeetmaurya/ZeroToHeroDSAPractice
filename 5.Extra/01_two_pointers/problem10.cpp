// 151. Reverse Words in a String

#include<iostream>
#include <string>
#include <vector>
using namespace std;


// ========================================================

class Solution {
public:
    string reverseWords(string s) {
        string final = "";
        string word = "";
        vector<string> str;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                if(word!="") {
                    str.push_back(word);
                }
                word = "";
            } else {
                word+=s[i];
            }
        }
        if(word!="") str.push_back(word);

        for(int i=str.size()-1; i>0; i--) {
            final += str[i] + " ";
        }
        final+=str[0];

        return final;
    }
};


// ========================================================

int main() {
    Solution sol;   
    string s = "  hello world  ";
    cout << sol.reverseWords(s) << endl;

    return 0;
}