#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <time.h>
#include <functional>
#include <queue>
#include <cctype>
#include <sstream>

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        rowsFlags.assign(9, vector<bool>(10, false));
        colsFlags.assign(9, vector<bool>(10, false));
        squareFlags.assign(3, vector<vector<bool> >(3, vector<bool>(10, false)));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] != '.') {
                    rowsFlags[i][board[i][j] - '0'] = true;
                    colsFlags[j][board[i][j] - '0'] = true;
                    squareFlags[i / 3][j / 3][board[i][j] - '0'] = true;
                }
        found = false;
        dfs(board, 0, 0);
    }
private:
    void dfs(vector<vector<char> > &board, int x, int y) {
        if (found)
            return;
        if (x == 9) {
            found = true;
            return;
        }
        if (board[x][y] != '.') {
            if (y < 8) {
                dfs(board, x, y + 1);
                if (found)
                    return;
            } else {
                dfs(board, x + 1, 0);
                if (found)
                    return;
            }
        } else {
            for (int i = 1; i <= 9; i++)
                if (rowsFlags[x][i] == false
                    && colsFlags[y][i] == false
                    && squareFlags[x / 3][y / 3][i] == false) {
                    rowsFlags[x][i] = true;
                    colsFlags[y][i] = true;
                    squareFlags[x / 3][y / 3][i] = true;
                    board[x][y] = '0' + i;
                    if (y < 8) {
                        dfs(board, x, y + 1);
                        if (found)
                            return;
                    } else {
                        dfs(board, x + 1, 0);
                        if (found)
                            return;
                    }
                    board[x][y] = '.';
                    rowsFlags[x][i] = false;
                    colsFlags[y][i] = false;
                    squareFlags[x / 3][y / 3][i] = false;
                }
        }
    }
    vector<vector<bool> > rowsFlags;
    vector<vector<bool> > colsFlags;
    vector<vector<vector<bool> > > squareFlags;
    bool found;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<string> tmp({"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"});
    vector<vector<char> > board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = tmp[i][j];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    sol.solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
