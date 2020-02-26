//
//  main.cpp
//  PermComb
//
//  Created by Sushan Basnet on 2/25/20.
//  Copyright © 2020 Sushan Basnet. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;




void combHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& entry, int start, int depth) {
    //base case
    if (depth==0) {
        ans.push_back(entry);
        return;
    }
    //recursive case
    for(int i=start; i<nums.size(); i++) {
        entry.push_back(nums[i]);  //not start but i
        combHelper(nums, ans, entry, i+1, depth-1);
        entry.pop_back();
    }
}

vector<vector<int>> combinations(vector<int> nums, int choose) {
    vector<vector<int>> ans;
    vector<int> entry;
    combHelper(nums, ans, entry, 0, choose);
    return ans;
    
}




int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3,4};
    vector<vector<int>> ansComb = combinations(nums, 3);
    vector<vector<int>> ansPerm; //= permutations(nums);
    cout << "Printing all combinations" << endl;
    for(auto v: ansComb) {
        for(auto n: v) {
            cout << n << " ";
        }
        cout << endl;
    }
    

    return 0;
}
