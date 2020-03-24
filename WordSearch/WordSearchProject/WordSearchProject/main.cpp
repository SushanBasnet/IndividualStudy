

#include <iostream>
#include <vector>
#include <fstream>

#define PATH "/Users/sbasnet/Documents/C++/IndividualStudy/WPSolver"

using namespace std;
enum direction {NONE=-1, NW=0, N=1, NE=2, W=3, E=4, SW=5, S=6, SE=7};
struct Ans {
    int row=0;
    int col=0;
    direction d;
};

bool helper(vector<vector<char> >& grid, int i, int j, string& word, int pos, int d,  Ans& ans) {
    //base case Out-Of-Bounds Check
    
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return false;
    }
    //non-matching character check
    if (word[pos] == grid[i][j]) {
        if (pos == word.size()-1) {
            ans.d = (direction) d;
            return true;
        }
    } else {
        return false;
    }
    
    if (d >= 0) {
        switch (d) {
            case NW:
                return helper(grid, i-1, j-1, word, pos+1, d, ans); //NW
            case N:
                return helper(grid, i-1, j, word, pos+1, d, ans); //N
            case NE:
                return helper(grid, i-1, j+1, word, pos+1, d, ans); //N
            case W:
                return helper(grid, i, j-1, word, pos+1, d, ans); //W
            case E:
                return helper(grid, i, j+1, word, pos+1, d, ans); //E
            case SW:
                return helper(grid, i+1, j-1, word, pos+1, d, ans); //SW
            case S:
                return helper(grid, i+1, j, word, pos+1, d, ans); //S
            case SE:
                return helper(grid, i+1, j+1, word, pos+1, d, ans); //SE
            default:
            break;
        }
    } else {
        //make 8 recursive calls for each direction
        d=0;
        for(int s=-1; s<= 1; s++) {
            for(int t=-1; t<= 1; t++) {
                if (s==0 && t==0) continue;
                bool earlyExit = helper(grid, i+s, j+t, word, pos+1, d, ans);
                if (earlyExit) return true;
                d++;
            }
        }
    }
    return false;
    
}

Ans search(vector<vector<char> >& grid, string word ) {
    Ans ans;
    if (word.empty() || grid.empty()) return ans; //important because of word.size()-1
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == word[0]) {
                if (helper(grid, i, j, word, 0, -1, ans)) {
                    ans.row = i;
                    ans.col = j;
                }
            }
        }
    }
    return ans;
}

vector<vector<char>> readFromFile(const char* fileName) {
    
    string fullPath = string(PATH) +"/"+ fileName;
    ifstream in(fullPath );
    
    
    vector<vector<char>> grid;
    string inputStr;
    if(in.is_open())
    {
        while(in >> inputStr) {
            cout << inputStr << endl;
            vector<char> entry;
            for(auto c: inputStr) {
                entry.push_back(c);
            }
            grid.push_back(entry);
        }
    }
    return grid;
    
}

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> grid = readFromFile(argv[1]);
    
    cout << "FINDING WORD: "  << string(argv[2]) << endl;
    
    Ans ans = search(grid, argv[2]);
    cout << "Row = " << ans.row << endl;
    cout << "Col = " << ans.col << endl;
    cout << "Dir = " << ans.d << endl;
    
    
    
    return 0;
}
