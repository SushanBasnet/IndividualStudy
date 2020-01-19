/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if (root == NULL) return ans;
        TreeNode* tmp = root;
        while(tmp != NULL || !s.empty()) {
           while(tmp != NULL) {
               s.push(tmp);
               tmp = tmp -> left;
           }
            tmp = s.top();
            s.pop();
            ans.push_back(tmp->val);
            tmp = tmp -> right;
            
        }
        return ans;
    }
};