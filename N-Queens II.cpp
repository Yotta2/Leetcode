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
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> colOk(n, true);
        int ans = 0;
        dfs(board, 0, n, colOk, ans);
        return ans;
    }
private:
    bool isLegal(int x, int y, vector<string> &board) {
        int dir[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};  // \ | / direction
        // \ direction
        for (int i = 0; i < 3; i++) {
            int xNext = x + dir[i][0];
            int yNext = y + dir[i][1];
            while (true) {
                if (xNext < 0 || xNext >= board.size() || yNext < 0 || yNext >= board.size())
                    break;
                if (board[xNext][yNext] == 'Q')
                    return false;
                xNext = xNext + dir[i][0];
                yNext = yNext + dir[i][1];
            }
        }
        return true;
    }

    void dfs(vector<string> &board, int row, int n, vector<bool> &colOk, int &ans) {
        if (n == row) {
            ans++;
            return;
        }

        if (row == 0) {  // prune half the search tree
            for (int i = 0; i < n / 2 + 1; i++) {
                if (n % 2 == 0 && i == n / 2)
                    break;
                if (colOk[i] && isLegal(row, i, board)) {
                    colOk[i] = false;
                    board[row][i] = 'Q';
                    dfs(board, row + 1, n, colOk, ans);
                    board[row][i] = '.';
                    colOk[i] = true;
                }
                if (i == n / 2 - 1)
                    ans *= 2;
            }
        } else {
            for (int i = 0; i < n; i++)
                if (colOk[i] && isLegal(row, i, board)) {
                    colOk[i] = false;
                    board[row][i] = 'Q';
                    dfs(board, row + 1, n, colOk, ans);
                    board[row][i] = '.';
                    colOk[i] = true;
                }
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.totalNQueens(12) << endl;
    return 0;
}

