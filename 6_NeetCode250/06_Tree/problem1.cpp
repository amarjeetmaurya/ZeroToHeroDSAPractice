// 144. preorder | 94. inorder | 145. postorder

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
    vector<int> inres;
    vector<int> preres;
    vector<int> postres;

    void preorder(TreeNode* root) {
        if(root==nullptr) return;       
        preres.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {
        if(root==nullptr) return;       
        inorder(root->left);
        inres.push_back(root->val);
        inorder(root->right);
    }

    void postorder(TreeNode* root) {
        if(root==nullptr) return;       
        postorder(root->left);
        postorder(root->right);
        postres.push_back(root->val);
    }

public:
     vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return preres;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return inres;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return postres;
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
    vector<int> inResult = sol.preorderTraversal(root);
    cout << "PreOrder-> ";
    for(int item: inResult) {
        cout <<item <<" ";
    }
    cout <<endl;
    
    vector<int> preResult = sol.inorderTraversal(root);
    cout << "InOrder-> ";
    for(int item: preResult) {
        cout <<item <<" ";
    }
    cout <<endl;
    vector<int> postResult = sol.postorderTraversal(root);
    cout << "PostOrder-> ";
    for(int item: postResult) {
        cout <<item <<" ";
    }
    cout <<endl;

    return 0;
}
