

#include <map>
#include <utility>

using namespace std;


class Solution {
public:
    //grid is m x n where m = columns, n = rows
    
    int uniquePaths(int m, int n) {
        vector<int> columns(m, 0);
        vector<vector<int>> grid(n, columns); //n rows of m columns [nxm] matrix
    
        //boundary case of one square gird
        grid[0][0] = 1;        
        for(int col=1; col < m; col++) {
            grid[0][col] = 1;
        }
        for(int row = 1; row < n; row++) {
            grid[row][0] = 1;
        }
        for (int row = 1; row < n; row++) {
            for (int col = 1; col < m; col++) {
                grid[row][col] = grid[row-1][col] + grid[row][col-1];
            }
        }
        
        return grid[n-1][m-1];
    }
};