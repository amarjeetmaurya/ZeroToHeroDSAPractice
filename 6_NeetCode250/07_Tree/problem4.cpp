// 226. Invert Binary Tree 
#include<iostream>
#include<vector>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// =====================================================
class Solution {
private:
    vector<int> res;

    void postorder(TreeNode* root) {
        if(root==nullptr) return;      
        if(root->right != nullptr) {
            postorder(root->left);
        } 
        res.push_back(root->val);
        postorder(root->right);
    }

public:
    vector<int> invertTree(TreeNode* root) {
        postorder(root);
        return res;
    }
};

// =======================================================


int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    TreeNode *left1 = new TreeNode(4);
    TreeNode *right1 = new TreeNode(5);
    TreeNode *left2 = new TreeNode(6);
    TreeNode *right2 = new TreeNode(7);
    root->left = left;
    root->right = right;
    left->left = left1;
    left->right = right1;
    right->left = left2;
    right->right = right2;

    Solution sol;
    vector<int> result = sol.invertTree(root);
    for(int item: result) {
        cout <<item <<" ";
    }
    cout <<endl;

    return 0;
}
