class Solution {
    public:
    
    void helper(vector<int>& candidates, set<vector<int>>& ans, vector<int> entry, int target, int rsum, int mask) {
        //base cases
        if (target==rsum) {
            std::sort(entry.begin(), entry.end());
            ans.insert(entry);
            return;
        }
        if (rsum > target) return; //rsum exceeds target and only positive ints
        for(int i=mask; i < candidates.size(); i++) {
            entry.push_back(candidates[i]);
            helper(candidates, ans, entry, target, rsum + candidates[i], i+1);
            entry.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> entry;
        helper(candidates, ans, entry, target, 0, 0);
        vector<vector<int>> ansV;
        for(auto it = ans.begin(); it != ans.end(); it++) {
            ansV.push_back(*it);
        }
        return ansV;
    }
    
    
};
