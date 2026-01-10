// 735. Asteroid Collision

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for (int a : ast) {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                     continue;
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push(a);
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        int left = 0, right = result.size() - 1;
        while (left < right) {
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
    vector<int> astro = {3,5,-6,2,-1,4};
    Solution s;

    vector<int> result= s.asteroidCollision(astro);
     for(int i: result) {
        cout << "-> " << i << endl;
    }
    return 0;
}
