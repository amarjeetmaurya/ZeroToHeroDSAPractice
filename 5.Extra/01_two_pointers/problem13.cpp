// 881. Boats to Save People

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ========================================================

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left=0, right=people.size()-1;
        int result = 0;
        while(left<=right) {
            if(people[left] + people[right] <= limit) {
                result++;
                left++;
                right--;
            } else {
                result++;
                right--;
            } 
        }
        
        return result;
    }
};


// ========================================================

int main() {
    Solution sol;
    vector<int> people = {1,2};
    int limit = 3;
    cout << sol.numRescueBoats(people, limit) << endl;

    return 0;
}