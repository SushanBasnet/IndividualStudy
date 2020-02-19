

//567 perumtation in string

#include <unordered_map> 
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //first form a histogram hashmap
        unordered_map<char, int> hist;
        for(int i=0; i<s1.size(); i++) {    
                hist[s1[i]]++;
        }
        
        //print hist
        for (auto it = hist.begin(); it != hist.end(); it++) {
            cout << it->first << "," << it->second << endl;
        }
        int i=0, j=0; 
        while(i < s2.size() && j < s2.size()) {
            if (hist.find(s2[j]) == hist.end()) {
                // not in map
                if (i==j) {
                    i++;
                    j++;
                } else {
                    hist[s2[i]]++;
                    i+= 1;
                }
            } else {
                // inside the map
                hist[s2[j]]--;
                if (hist[s2[j]] == 0) hist.erase(s2[j]);
                if (hist.empty()) return true;
                j++;
            }
        }
        return false;
    }
};