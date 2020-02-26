class Solution {
public:
    

    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& entry, int target, int rsum, int mask) {
        if (rsum==target) {
            ans.push_back(entry);
            return;
        }
        //depth < candidates.size() did not work because it can exceed candidates.size!
        if (rsum > target) return;
        
        for(int i=mask; i<candidates.size(); i++) {
            entry.push_back(candidates[i]);
            helper(candidates, ans, entry, target, rsum + candidates[i], i);
            entry.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //permutation with duplicates
        vector<vector<int>> ans;
        vector<int> entry;
        helper(candidates, ans, entry, target, 0, 0);
        return ans;
        
    }
    
    
    
    
};