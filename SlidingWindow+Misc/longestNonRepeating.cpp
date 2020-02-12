#include <unordered_map>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> visited;
        int i=0, j=0, count = 0; 
        
        while(j < s.size()) {
            auto it = visited.find(s[j]);
            if (it != visited.end()) { //if in the map
                if (it->second < i) visited.erase(it); //was outside window
                else i = 1 + it->second; 
            } 
            visited[s[j]] = j; //update position of char
            j++;
            if (j-i>count) count = j-i; //update max
        }
        return count;
    }
};