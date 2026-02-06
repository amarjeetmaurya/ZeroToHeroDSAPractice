// Binary Search Tree (BST)

#include<iostream>
#include<vector>
#include<queue>
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

// A proper BST
TreeNode* insertBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

TreeNode* buildBST(vector<int>& arr) {
    TreeNode* root = nullptr;
    for(int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

// ========================================= 

TreeNode* searchTree(TreeNode* root, int value) {
    // cout<< "-> "<< (root->val == value ) <<endl;
    if(!root || root->val == value) return root;

    if(value < root->val) {
        return searchTree(root->left, value);
    }
    return searchTree(root->right, value);
}

// ============================================== 



int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 15;

    TreeNode* root = buildBST(nums);
    TreeNode* result = searchTree(root, target);
    
    if(result) cout << "Found: " << result->val << endl;
    else cout << "Not found" << endl;


    return 0;
}

