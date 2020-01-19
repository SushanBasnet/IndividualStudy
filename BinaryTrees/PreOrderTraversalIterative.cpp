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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp != NULL) {
            while(tmp != NULL) {
                ans.push_back(tmp->val);
                s.push(tmp);
                tmp = tmp -> left;
            }
            tmp = s.top();
            s.pop();
            tmp = tmp -> right;
        }
        return ans;
    }
};