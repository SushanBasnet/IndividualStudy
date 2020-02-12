#include <unordered_map>


// O(1) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
        
    }
};


// O(N) solution

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //stores (target-i, index)
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) { //if in map
                //we found a pair
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            } else { //not in map
                m[target-nums[i]] = i; //insert in map
            }
        }
        return ans;
    }
};