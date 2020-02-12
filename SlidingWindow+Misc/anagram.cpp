#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        //brute force method - sort
        unordered_map<char, int> hist;
        for(int i=0; i < s.size(); i++) {
            if (hist.find(s[i]) == hist.end()) {
                //if not in the map
                hist[s[i]] = 1;
            } else {
                hist[s[i]]++;
            }
        }
        
        for(int i=0; i < t.size(); i++) {
            if (hist.find(t[i]) == hist.end()) {
                return false;
            }
            hist[t[i]]--;
            if (hist[t[i]] <= 0) hist.erase(t[i]);
        }
        if (hist.empty()) return true;
        return false;
        
    }
};