
#include <unordered_set>
#include <vector>

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_set<int> nonJudges;
        if (trust.empty() || trust[0].empty()) return 1;
        //find the town judge number
        for(vector<int> t: trust) {
            nonJudges.insert(t[0]);
        }
        int judge = -1;
        for(vector<int> t: trust) {
            if (nonJudges.find(t[1]) == nonJudges.end()) {
                //if it is not int the nonJudges, t[1] may be a judge
                judge = t[1];
                break;
            }
        }
        if (judge<0) return -1;
        
        //verify there is no node (that is not judge) that has trusts no-one (stray nodes)
        for(int i=1; i<=N; i++) {
            if (i != judge && nonJudges.find(i) == nonJudges.end()) {
                return -1;
            }
        }
        //verify all nodes point to the judge
        for(vector<int> t: trust) {
            //if in the set and points to judge
            if (nonJudges.find(t[0]) != nonJudges.end() && t[1] == judge) {
                nonJudges.erase(t[0]); //remove from the set
            }
        }
        //all people that trust judge should be removed from the set
        if (nonJudges.empty()) return judge;
        return -1;
    }
};