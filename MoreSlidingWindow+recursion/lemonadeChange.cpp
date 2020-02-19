



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int hist[3] = {0, 0, 0}; // 0 -> 5, 1 -> 10, 2 -> 20
        for(int b: bills) {
            if (b == 5) hist[0]++;
            else if (b==10) hist[1]++;
            else hist[2]++;
 
            if (b==5) continue;
            else if (b==10) {
                if (hist[0] > 0) hist[0]--;
                else return false;
            } else {
                if(hist[0] >= 1 && hist[1] >= 1) {  //10 - 5 change should be first priority!
                    hist[0]--; hist[1]--;
                } else if (hist[0] >= 3) {
                    hist[0] -= 3;
                }
                
                else {
                    return false;
                }
            }
        }
        return true;
    }
};