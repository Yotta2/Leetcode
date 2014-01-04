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
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > f = grid;
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                int minTmp = INT_MAX;
                if (i + 1 < grid.size())
                    minTmp = min(f[i + 1][j], minTmp);
                if (j + 1 < grid[0].size())
                    minTmp = min(f[i][j + 1], minTmp);
                if (minTmp != INT_MAX)
                    f[i][j] += minTmp;
            }
        return f[0][0];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
