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
#include <utility>

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty())
            return false;
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
        bool found = false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                used[i][j] = true;
                dfs(i, j, board, 0, word, found, used);
                used[i][j] = false;
            }
        return found;
    }
private:
    void dfs(int x, int y, vector<vector<char> > &board,
             int index, string word, bool &found, vector<vector<bool> > &used) {
        if (found)
            return;
        if (board[x][y] != word[index])
            return;
        if (index == word.size() - 1) {
            found = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xNext = x + delta[i][0];
            int yNext = y + delta[i][1];
            if (xNext < 0 || yNext < 0 || xNext >= board.size() || yNext >= board[0].size())
                continue;
            if (used[xNext][yNext])
                continue;
            used[xNext][yNext] = true;
            dfs(xNext, yNext, board, index + 1, word, found, used);
            used[xNext][yNext] = false;
        }
    }
    int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
