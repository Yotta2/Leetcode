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
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n, ans);
        return ans;
    }
private:
    bool isOutofBound(int x, int y, int n) {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return true;
        else
            return false;
    }
    bool isLegal(int x, int y, vector<string> &board) {
        int dir[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};  // \ | / direction
        // \ direction
        for (int i = 0; i < 3; i++) {
            int xNext = x + dir[i][0];
            int yNext = y + dir[i][1];
            while (true) {
                if (isOutofBound(xNext, yNext, board.size()))
                    break;
                if (board[xNext][yNext] == 'Q')
                    return false;
                xNext = xNext + dir[i][0];
                yNext = yNext + dir[i][1];
            }
        }
        return true;
    }

    void dfs(vector<string> &board, int row, int n, vector<vector<string> > &ans) {
        if (n == row) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
            if (isLegal(row, i, board)) {
                board[row][i] = 'Q';
                dfs(board, row + 1, n, ans);
                board[row][i] = '.';
            }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

