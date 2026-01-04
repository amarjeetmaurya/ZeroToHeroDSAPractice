// 496. Next Greater Element I
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while (nums1[i] != nums2[j])
                j++;
            int nextG = -1;
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums1[i]) {
                    nextG = nums2[k];
                    break;
                }
            }
            result.push_back(nextG);
        }
        return result;
    }

    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mapp;

        for(int num: nums2) {
            while(!s.empty() && s.top()<num) {
                mapp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for(auto num: nums1) {
            result.push_back(mapp.count(num)? mapp[num]: -1);
        }

        return result;
    }
};

int main() {
    // vector<int> nums1 = {4,1,2};
    // vector<int> nums2 = {1,3,4,2};
    // vector<int> nums1 = {2,4};
    // vector<int> nums2 = {1,2,3,4};
    vector<int> nums1 = {3,1,5,7,9,2,6};
    vector<int> nums2 = {1,2,3,5,6,7,9,11};

    Solution s;
    vector<int> result = s.nextGreaterElement(nums1, nums2);

    Solution s2;
    vector<int> result2 = s.nextGreaterElement2(nums1, nums2);

    for(int n: result) {
        cout << n << " ";
    }
    cout <<endl;
    for(int n: result2) {
        cout << n << " ";
    }
    
    return 0;
}