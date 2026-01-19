// 11. Container With Most Water

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ========================================================
class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0, right = h.size() - 1;

        int r = 0;
        while (left < right) {
            r = max(r, min(h[left], h[right]) * (right - left));
            if (h[left] > h[right]) right--;
            else left++;
        }
        return r;
    }
};

// ========================================================

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;

    return 0;
}