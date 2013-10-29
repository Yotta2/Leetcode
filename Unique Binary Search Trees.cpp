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
    int numTrees(int n) {
        f.assign(n + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= n; i++)
            f[i][i] = 1;
        if (n != 1)
            dfs(1, n);
        return f[1][n];
    }
private:
    void dfs(int i, int j) {
        f[i][j] = 0;
        for (int k = i; k <= j; k++) {
            if (k - 1 >= i) {
                if (f[i][k - 1] == -1)
                dfs(i, k - 1);
            }
            if (k + 1 <= j) {
                if (f[k + 1][j] == -1)
                dfs(k + 1, j);
            }
            if (k - 1 >= i && k + 1 <= j)
                f[i][j] += f[i][k - 1] * f[k + 1][j];
            else if(k - 1 >= i)
                f[i][j] += f[i][k - 1];
            else if (k + 1 <= j)
                f[i][j] += f[k + 1][j];
        }
    }
    vector<vector<int> > f;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
