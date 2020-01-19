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
    void traverseHelper(vector<int>& ans, TreeNode* node) {
        if (node==NULL) return;
        ans.push_back(node->val);
        traverseHelper(ans, node->left);
        traverseHelper(ans, node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverseHelper(ans, root);
        return ans;
    }
};