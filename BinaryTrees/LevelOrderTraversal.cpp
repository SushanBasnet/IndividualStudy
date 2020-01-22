/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level order traversal
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> level;
        if (root==NULL) return ans;
        q.push(root);
        q.push(NULL);  // use as indicator of end of level
        TreeNode* tmp;
        while(!q.empty()) {
            tmp = q.front();
            q.pop();
            
            if (tmp==NULL) {
                ans.push_back(level);
                level.clear();
                if (q.empty()) break;
                q.push(NULL);
            } else {
                level.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }    
        }
        return ans;
    }
};