// 1732. Find the Highest Altitude

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxH = 0;
        int sumH = 0;

        for (int i = 0; i < n; i++) {
            sumH += gain[i];
            maxH = max(maxH, sumH);
        }

        return maxH;
    }
};

int main() {
    // Example input: gains array
    vector<int> gain = {-5, 1, 5, 0, -7};

    Solution sol;
    int result = sol.largestAltitude(gain);

    cout << "Largest altitude: " << result << endl;

    return 0;
}
