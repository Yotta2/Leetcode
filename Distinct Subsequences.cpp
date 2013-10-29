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
    int numDistinct(string S, string T) {
        init(S, T);
        dfs(S, 0, T, 0);
        return f[0][0];
    }
private:
    void init(string &S, string &T) {
        f.assign(S.size() + 1, vector<int>(T.size() + 1, -1));
        for (int i = 0; i <= S.size(); i++)
            f[i][T.size()] = 1;
    }
    void dfs(string &S, int i, string &T, int j) {
        f[i][j] = 0;
        for (int k = i; k < S.size(); k++)
            if (S[k] == T[j]) {
                if (f[k + 1][j + 1] == -1)
                    dfs(S, k + 1, T, j + 1);
                f[i][j] += f[k + 1][j + 1];
            }
    }
    vector<vector<int> > f;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.numDistinct("b", "b") << endl;
    return 0;
}
