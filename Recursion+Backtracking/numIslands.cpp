class Solution {
public:
    
    
      
    void traverse(vector<vector<char>>& grid, int i, int j) {
        //base case and OOB check
        if (i < 0 || i >=grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        //visit 
        grid[i][j] = '0';
        traverse(grid, i-1, j);
        traverse(grid, i, j+1);
        traverse(grid, i+1, j);
        traverse(grid, i, j-1);
        

    }
    
    int numIslands(vector<vector<char>>& grid) {
     

        // we need to keep track of visited so we dont visit again
        //visit each island and its surrounding with a recursive function
        if (grid.empty() || grid[0].empty()) return 0;
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    traverse(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    
  
    
};