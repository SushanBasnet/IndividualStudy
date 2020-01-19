/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <climits> 

class Solution {
public:
    struct Bound {
        long leftB = LONG_MIN;
        long rightB = LONG_MAX;
    };
    
    bool preOrderTraverse(TreeNode* node, Bound b) {
        if (node == NULL) return true;
        if (node->val < b.rightB && node->val > b.leftB) {
            Bound tb = b;
            tb.rightB = node->val;
            bool left = preOrderTraverse(node->left, tb);
            tb = b;
            tb.leftB = node->val;
            return left && preOrderTraverse(node->right, tb);
        }
        return false; 
    }
    
    bool isValidBST(TreeNode* root) {
        Bound b;
        return preOrderTraverse(root, b);
    }
    
    

    
    
};