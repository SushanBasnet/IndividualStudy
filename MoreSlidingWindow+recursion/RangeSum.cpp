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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        preorderTraversal(root, L, R, sum);
        return sum;
    }
    
    
    void preorderTraversal(TreeNode* node, int L, int R, int& sum) {
        if (node==NULL) {
            return;
        }
        if (node->val <= R && node->val >= L) sum += node->val;
        preorderTraversal(node->left, L, R, sum);
        preorderTraversal(node->right, L, R, sum);
        
    }
    
};