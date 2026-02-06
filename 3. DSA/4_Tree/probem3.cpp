// Level Order Traversal (BFS) | Breadth First Search

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


TreeNode* buildTree(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1);
    
    root->right = buildTree(arr, 2*i + 2);

    return root;
}

// ========================================= 
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}


int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    return 1 + max(maxDepth(root->left),
                   maxDepth(root->right));
}

// ============================================== 



int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int i = 0;

    TreeNode *root =  (buildTree(nums, i));
    levelOrder(root);
    cout <<"Depth-> " << maxDepth(root);
    cout <<endl;

    return 0;
}

