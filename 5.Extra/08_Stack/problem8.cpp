// 946. Validate Stack Sequences

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> spush;
        int track = 0;
        for(int i=0; i<popped.size(); i++) {
            spush.push(pushed[i]);
            while(!spush.empty() && spush.top()==popped[track]) {
                spush.pop();
                track++;
            } 
        }
        if(track==popped.size()) return true;

        return false;
    }
};

// =========================================

int main()
{
    // vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    vector<int> pushed = {1,2,3,4,5}, popped = {4,3,5,1,2};
    Solution s;

    bool result= s.validateStackSequences(pushed, popped);
    cout <<((result==0)?"false":"true");

    return 0;
}
