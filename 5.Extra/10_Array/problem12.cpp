// 172. Factorial Trailing Zeroes

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    int result = sol.trailingZeroes(n);

    cout << "Trailing zeroes in " << n << "! = " << result << endl;

    return 0;
}
