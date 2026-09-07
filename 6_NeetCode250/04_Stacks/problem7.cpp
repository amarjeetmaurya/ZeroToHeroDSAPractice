// 735. Asteroid Collision
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stc;

        for (int a : ast) {
            bool destroyed = false;
            while (!stc.empty() && stc.top() > 0 && a < 0) {
                if (abs(stc.top()) < abs(a)) {
                    stc.pop();
                    continue;
                }
                if (abs(stc.top()) == abs(a)) {
                    stc.pop();
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                stc.push(a);
            }
        }

        int n = stc.size();
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {
            result[i] = stc.top();
            stc.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> asteroids = {5, 10, -5};

    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Result after collision: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
