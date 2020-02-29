//
//  main.cpp
//  WordSearchProject
//
//  Created by Sushan Basnet on 2/28/20.
//  Copyright © 2020 Sushan Basnet. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
enum direction {NONE=-1, NW=0, N=1, NE=2, W=3, E=4, SW=5, S=6, SE=7};
struct Ans {
    int row=0;
    int col=0;
    direction d;
};

bool helper(vector<vector<char>>& grid, int i, int j, string& word, int pos, int d,  Ans& ans) {
    //base case Out-Of-Bounds Check
    
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size()) {
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

Ans search(vector<vector<char>>& grid, string word ) {
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

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> grid
        {{'A','G','L','O','W','O','G','L','E','S','T','C','E','L','S','I'},
        {'M','H','O','P','R','N','I','U','A','T','E','D','J','W','P','A'},
        {'G','O','I','M','I','E','Z','A','A','N','A','E','O','B','A','S'},
        {'S','N','O','K','S','C','Z','W','S','W','S','T','Y','I','M','P'},
        {'S','T','I','R','R','E','D','O','N','P','W','A','S','C','H','I'},
        {'A','H','N','N','L','R','R','E','I','O','O','R','P','E','E','R'},
        {'Z','F','R','E','E','S','D','H','K','I','S','T','O','P','R','E'},
        {'I','L','A','S','M','K','S','S','A','F','A','R','I','I','N','G'},
        {'P','S','A','D','I','R','C','A','B','K','C','M','B','D','I','M'},
        {'P','L','G','N','I','F','E','I','R','B','L','L','B','E','A','E'},
        {'E','C','I','A','R','G','O','F','U','G','E','U','U','R','E','L'},
        {'R','M','W','Y','X','E','I','S','T','Q','S','P','C','M','A','T'},
        {'E','Q','S','G','N','I','T','T','E','U','O','H','L','I','S','S'},
        {'D','S','T','U','A','N','R','E','G','G','U','J','V','S','D','Y'}};
    
    Ans ans = search(grid, "FASSK");
    cout << "Row = " << ans.row << endl;
    cout << "Col = " << ans.col << endl;
    cout << "Dir = " << ans.d << endl;
    
    
    
    return 0;
}
