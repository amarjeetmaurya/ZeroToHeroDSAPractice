// 901. Online Stock Span
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string result = "";
        while(!st.empty()) {
            // cout <<st.top();
            result+=st.top();
            st.pop();
        }
        int left =0, right=result.length()-1;
        while(left<right) {
            swap(result[left], result[right]);
            left++;
            right--;
        }
        return result;
    }
};
// =========================================

int main()
{
    string str = "leetc**co*de";
    Solution s;
    string result= s.removeStars(str);
    for(char c: result) {
        cout << c;
    }

    return 0;
}
