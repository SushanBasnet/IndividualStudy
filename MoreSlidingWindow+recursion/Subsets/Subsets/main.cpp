#include <vector>
#include <iostream>
using namespace std;


//program generates all the subsets of a given vector (also called powersets)



/*
 Purpose: Generate all subsets of a vector, and return as vector of vectors
 input: vector<int>
 output: vector<vector<int>>
 */

void helper(const vector<int>& nums, vector<int>& entry, vector<vector<int>>& ans, int i);

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> ans;
    vector<int> entry;
    helper(nums, entry, ans, 0);
    return ans;
}

void helper(const vector<int>& nums, vector<int>& entry, vector<vector<int>>& ans, int i) {
    //base case
    if (i >= nums.size()) {
        //push entry to ans;
        ans.push_back(entry);
        return;
    }
    //recursive case
    helper(nums, entry, ans, i+1);
    entry.push_back(nums[i]);
    helper(nums, entry, ans, i+1);
    entry.pop_back();
}


int main(int argc, const char * argv[]) {
    vector<int> nums{1, 2, 3, 4};
    vector<vector<int>> ans = subsets(nums);
    for (vector<int> entry: ans) {
        if (entry.empty()) cout << "(empty)";  //indicate empty vector
        for(int i: entry) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
