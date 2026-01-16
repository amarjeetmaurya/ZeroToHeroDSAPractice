// 13. Roman to Integer

#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;


// ========================================================
class Solution {
public:
    int romanToInt(string s) {
        // nyc
        unordered_map<char, int> val =
         {
          {'I', 1},
          {'V', 5},  
          {'X', 10},
          {'L', 50},  
          {'C', 100}, 
          {'D', 500},
          {'M', 1000}
          };
      
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
             int current = val[s[i]]; 
             int next = (i + 1 < s.size()) ? val[s[i + 1]] : 0; 
             if (current < next) { 
                result -= current;  
            } else {
                result += current; 
            }
        }
        return result;
    }
};

// ========================================================


int main() {
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.romanToInt(s) << endl;
    // your code here
    return 0;
}