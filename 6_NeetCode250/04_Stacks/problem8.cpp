// 739. Daily Temperatures

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && temps[j] <= temps[i]) {
                if (res[j] == 0) {
                    j = n;
                    break;
                }
                j += res[j];
            }

            if (j < n) {
                res[i] = j - i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = sol.dailyTemperatures(temps);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
