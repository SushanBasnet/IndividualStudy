/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void invertHelper(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertHelper(root->left);
        invertHelper(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        //swap left and right from top down
        invertHelper(root);
        return root;
    }
};