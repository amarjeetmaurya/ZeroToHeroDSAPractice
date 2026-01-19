// 122. Best Time to Buy and Sell Stock II

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ========================================================

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int left = 0;
        int right = 1;
        int mPro = 0;

        while(right<p.size()) {
            if(p[left]<p[right]) {
                int profit = p[right] - p[left];
                mPro += profit;
                left=right;
            } else {
                left = right;
            }
            right++;
        }
        return mPro;
    }
};

// ========================================================

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}