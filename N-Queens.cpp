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
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> sol(n, string(n, '.'));
        dfs(0, n, sol, ans);
        return ans;
    }
private:
    int delta[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
    bool isValid(vector<string> &sol, int x, int y) {
        for (int i = 0; i < 3; i++) {
            int nextX = x + delta[i][0];
            int nextY = y + delta[i][1];
            while (true) {
                if (nextX < 0 || nextX >= sol.size() || nextY < 0 || nextY >= sol.size())
                    break;
                if (sol[nextX][nextY] == 'Q')
                    return false;
                nextX += delta[i][0];
                nextY += delta[i][1];
            }
        }
        return true;
    }
    void dfs(int rol, int n, vector<string> &sol, vector<vector<string> > &ans) {
        if (rol == n) {
            ans.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(sol, rol, i)) {
                sol[rol][i] = 'Q';
                dfs(rol + 1, n, sol, ans);
                sol[rol][i] = '.';
            }
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
