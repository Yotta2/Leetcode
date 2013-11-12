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

/* DP, O(n ^ 4), TLE...
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
            return 0;
        vector<vector<vector<vector<int> > > >
            f(matrix.size(),
              vector<vector<vector<int> > >(matrix[0].size(),
                                            vector<vector<int> >(matrix[0].size() + 1,
                                                                 vector<int>(matrix.size() + 1, -1))));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                f[i][j][1][1] = matrix[i][j] - '0';
        dfs(f, 0, 0, matrix[0].size(), matrix.size());
        return f[0][0][matrix[0].size()][matrix.size()];
    }
private:
    void dfs(vector<vector<vector<vector<int> > > > &f,
             int x,
             int y,
             int w,
             int h) {
        if (f[x][y][w][h] != -1)
            return;
        f[x][y][w][h] = 0;
        vector<bool> flags(4, true); // flags to mark whether subMatrix[i] is fully filled with 1
        if (w - 1 >= 1) {
            dfs(f, x, y, w - 1, h);
            if (f[x][y][w - 1][h] != (w - 1) * h)
                flags[0] = false;
            f[x][y][w][h] = max(f[x][y][w][h], f[x][y][w - 1][h]);
        }
        if (h - 1 >= 1) {
            dfs(f, x, y, w, h - 1);
            if (f[x][y][w][h - 1] != w *(h - 1))
                flags[1] = false;
            f[x][y][w][h] = max(f[x][y][w][h], f[x][y][w][h - 1]);
        }
        if (y + 1 < f[0].size() && w - 1 >= 1) {
            dfs(f, x, y + 1, w - 1, h);
            if (f[x][y + 1][w - 1][h] != (w - 1) * h)
                flags[2] = false;
            f[x][y][w][h] = max(f[x][y][w][h], f[x][y + 1][w - 1][h]);
        }
        if (x + 1 < f.size() && h - 1 >= 1) {
            dfs(f, x + 1, y, w, h - 1);
            if (f[x + 1][y][w][h - 1] != w *(h - 1))
                flags[3] = false;
            f[x][y][w][h] = max(f[x][y][w][h], f[x + 1][y][w][h - 1]);
        }
        if (flags[0] && flags[1] && flags[2] && flags[3])
            f[x][y][w][h] = w * h;
    }
};
*/

/*
 DP: let dp[i][j] denote the consecutive 1s in row i from point (i, j)
 until the last consecutive 1 to the right. It takes O(m * n) to get all values.

then we take each point (i, j) as the top left corner of the rectangle and
to get the maximal rectangle with (i, j) being the left top corner.
This could be achieved by scanning from row i until the last row or
until the width of the rectangle becomes 0. It takes O(m) to get it.
So this takes O(m * n * m) time
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
            return 0;
        vector<vector<int> > f(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                for (int k = j; k < matrix[0].size(); k++) {
                    if (matrix[i][k] != '1')
                        break;
                    f[i][j]++;
                }
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                int minWidth = f[i][j];
                for (int r = i; r < matrix.size(); r++) {
                    minWidth = min(minWidth, f[r][j]);
                    if (minWidth == 0)
                        break;
                    int area = minWidth * (r - i + 1);
                    maxArea = max(maxArea, area);
                }
            }
        return maxArea;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<vector<char> > matrix({{'0', '1', '0', '1', '1'},
                                  {'0', '1', '1', '1', '1'},
                                  {'0', '1', '1', '1', '1'},
                                  {'0', '1', '1', '1', '0'}});
    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}
