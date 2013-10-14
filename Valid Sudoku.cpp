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
    bool isValidSudoku(vector<vector<char> > &board) {
        if (!allRowsValid(board))
            return false;
        if (!allColsValid(board))
            return false;
        if (!allSubboxesValid(board))
            return false;
        return true;
    }
private:
    bool allRowsValid(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            vector<bool> used(board.size() + 1, false);
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    if (used[digit])
                        return false;
                    used[digit] = true;
                }
        }
        return true;
    }
    bool allColsValid(vector<vector<char> > &board) {
        for (int j = 0; j < board.size(); j++) {
            vector<bool> used(board.size() + 1, false);
            for (int i = 0; i < board.size(); i++)
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    if (used[digit])
                        return false;
                    used[digit] = true;
                }
        }
        return true;
    }
    bool allSubboxesValid(vector<vector<char> > &board) {
        for (int ulcX = 0; ulcX < 9; ulcX += 3)
            for (int ulcY = 0; ulcY < 9; ulcY += 3) {
                vector<bool> used(board.size() + 1, false);
                for (int i = ulcX; i < ulcX + 3; i++)
                    for (int j = ulcY; j < ulcY + 3; j++)
                        if (board[i][j] != '.') {
                            int digit = board[i][j] - '0';
                            if (used[digit])
                                return false;
                            used[digit] = true;
                        }
            }
        return true;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
