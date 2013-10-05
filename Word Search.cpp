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
    void init(vector<vector<bool> > &used, int row, int col) {
        used.assign(row, vector<bool>());
        for (int i = 0; i < used.size(); i++)
            used[i].assign(col, false);
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty())
            return true;
        vector<vector<bool> > used;
        init(used, board.size(), board[0].size());
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (word[0] == board[i][j]) {
                    used[i][j] = true;
                    if (dfs(i, j, board, 0, word, used))
                        return true;
                    used[i][j] = false;
                }
        return false;
    }
    bool dfs(int x, int y, vector<vector<char> > &board,
             int i, string word, vector<vector<bool> > &used) {
        if (i == word.size() - 1)
            return true;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int j = 0; j < 4; j++) {
            int nextX = x + dir[j][0];
            int nextY = y + dir[j][1];
            if (nextX < 0 || nextX >= board.size() || nextY < 0 || nextY >= board[0].size())
                continue;
            if (used[nextX][nextY])
                continue;
            if (word[i + 1] == board[nextX][nextY]) {
                used[nextX][nextY] = true;
                if (dfs(nextX, nextY, board, i + 1, word, used))
                    return true;
                used[nextX][nextY] = false;
            }
        }
        return false;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}

