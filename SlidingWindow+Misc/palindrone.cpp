#include <stack>
#include <cctype>
using namespace std;

// Using stack O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> c;
        string copy = "";
        for(auto it = s.begin(); it!=s.end(); it++) {
            
            if (isalnum(*it)) {
                c.push(tolower(*it));
                copy += tolower(*it);
            }
        }
        string ret = "";
        while(!c.empty()) {
            cout << c.top();
            ret += c.top();
            c.pop();
        }
        cout << copy;
        cout << ret;
        return (ret == copy);
    }
};

// Two pointers approach O(N)
class Solution2 {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i=0, j=s.size()-1;
        while(i < j) {
            if (!isalnum(s[i])) {
                i++; continue;
            }
            if (!isalnum(s[j])) {
                j--; continue;
            }
            //both are alphanum:
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
};