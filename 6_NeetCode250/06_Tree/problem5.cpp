// 111 Minimum Depth of Binary Tree
//

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//==========
class Solution {
  public:
    int minDepth(TreeNode* root) {
            if (!root) return 0;
            if (!root->left && !root->right) return 1;
            if (!root->left) return 1 + minDepth(root->right);
            if (!root->right) return 1 + minDepth(root->left);
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
};

// =======
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
    int result = sol.minDepth(root);

    cout << result << endl;

    return 0;
}
