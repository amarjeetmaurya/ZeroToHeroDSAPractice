// 144. preorder | 94. inorder | 145. postorder

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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

// Recursive approach
/* 
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
*/

// Approach using Stack
/* 
class Solution {
public:
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (!s.empty() || curr!=nullptr ) {
            while(curr!=nullptr) {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            result.push_back(curr->val);
            curr=curr->right;
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (!s.empty() || curr!=nullptr ) {
            while(curr!=nullptr) {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            result.push_back(curr->val);
            curr=curr->right;
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        stack<TreeNode *> s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        } 

        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};
*/

// Morris Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    result.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode* curr = &dummy;

        while (curr) {
            if (!curr->left) {
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    vector<int> temp;
                    TreeNode* node = curr->left;
                    while (node != curr) {
                        temp.push_back(node->val);
                        node = node->right;
                    }
                    reverse(temp.begin(), temp.end());
                    result.insert(result.end(), temp.begin(), temp.end());

                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return result;
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
