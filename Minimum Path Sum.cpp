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
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > f(m + 1, vector<int>(n + 1, INT_MAX));
        f[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (i == m - 1 && j == n - 1)
                    continue;
                else
                    f[i][j] = grid[i][j] + min(f[i + 1][j], f[i][j + 1]);
        return f[0][0];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<vector<int> > grid({{1, 2, 5}, {3, 2, 1}});
    cout << sol.minPathSum(grid) << endl;
    return 0;
}

