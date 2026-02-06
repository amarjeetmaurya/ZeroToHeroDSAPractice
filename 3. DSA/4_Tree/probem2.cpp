// Build Tree from Array (LeetCode style)
// [1,2,3,null,4]

//    1
//   / \
//  2   3
//   \
//    4

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

// Inorder Traversal 
void inorder(TreeNode* root) {
    if(root==nullptr) return;       
    inorder(root->left);
    cout << (root->val) << "| ";
    inorder(root->right);
}

// ==============================================

TreeNode* buildTree(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1);
    
    root->right = buildTree(arr, 2*i + 2);

    return root;
}

// ========================================= 


int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int i = 0;

    inorder(buildTree(nums, i));
    cout <<endl;

    return 0;
}

