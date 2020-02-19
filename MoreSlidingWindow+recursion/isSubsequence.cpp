class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        //early exits
        if (t.empty() || s.size() > t.size()) return false;
        int i=0;
        for(int j=0; j < t.size(); j++) {
            if (t[j] == s[i]) {
                i++;
                if (i == s.size()) return true;
            }
        }
        return false;
    }
};