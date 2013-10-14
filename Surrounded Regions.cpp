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
    void solve(vector<vector<char>> &board) {
        if (board.empty())
            return;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 'O' && visited[i][j] == false) {
                    visited[i][j] = true;
                    if (isSurrounded(i, j, board, visited)) {
                        flip(i, j, board);
                    }
                }
    }
private:
    bool isSurrounded(int x, int y, vector<vector<char> > &board, vector<vector<bool> > &visited) {
        bool flag = true;
        queue<Loc> q;
        q.push(Loc(x, y));
        while (!q.empty()) {
            Loc curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xNext = curr.x + delta[i][0];
                int yNext = curr.y + delta[i][1];
                if (xNext < 0 || xNext >= board.size() || yNext < 0 || yNext >= board[0].size()) {
                    flag = false;
                } else if (visited[xNext][yNext] == false && board[xNext][yNext] == 'O') {
                    visited[xNext][yNext] = true;
                    q.push(Loc(xNext, yNext));
                }
            }
        }
        return flag;
    }
    void flip(int x, int y, vector<vector<char> > &board) {
        if (board[x][y] == 'X')
            return;
        board[x][y] = 'X';
        for (int i = 0; i < 4; i++)
            flip(x + delta[i][0], y + delta[i][1], board);
    }
    int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct Loc {
        int x, y;
        Loc(int _x, int _y) : x(_x), y(_y) {}
    };
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<vector<char> > board(1, vector<char>(1, 'O'));
    sol.solve(board);
    return 0;
}
