// 169. Majority Element

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// =============================================

//  Sorting
class Solution1 {
    public:
    int majorityElements(vector<int> nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());

        int max[2] = {0,INT_MIN};
        int occure = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) {
                occure++;
            } else {
                if(occure > max[1]) {
                    max[1] = occure;
                    max[0] = nums[i-1];
                }
                occure = 1;
            }
        }
        if(occure > max[1]) {
            max[1] = occure;
            max[0] = nums[nums.size()-1];
        }

        // cout << "max: " <<max[0] << " | times: " <<max[1] << endl;
        return max[0];
    }
};


//  HashMap
class Solution2 {
    public:
    int majorityElements(vector<int> nums) {
        if(nums.size() == 1) return nums[0];

        unordered_map<int, int> umap;
        for(int i=1; i<nums.size(); i++) {
            umap[nums[i]]++;
        }

        int maxCount = INT_MIN;
        int maxVal = 0;
        for(auto item: umap) {
            if(item.second > maxCount) {
                maxCount = item.second;
                maxVal = item.first;
            }
        }

        return maxVal;
    }
};


// ==========================================

int main() {
    
    vector<int> nums = {3,2,3};
    // vector<int> nums = {2,2,1,1,1,2,2};

    Solution2 sol;
    cout << sol.majorityElements(nums) <<endl;
    
    return 0;
}