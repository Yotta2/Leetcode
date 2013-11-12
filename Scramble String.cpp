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
    bool isScramble(string s1, string s2) {
        vector<vector<vector<bool> > > f(s1.size(), vector<vector<bool> >(s1.size(), vector<bool>(s1.size() + 1, false)));
        for (int i = 0; i < s1.size(); i++)
            for (int j = 0; j < s2.size(); j++)
                f[i][j][1] = (s1[i] == s2[j]);
        for (int l = 2; l <= s1.size(); l++)
            for (int i = 0; i + l <= s1.size(); i++)
                for (int j = 0; j + l <= s2.size(); j++)
                    for (int k = 1; k < l; k++)
                        f[i][j][l] = f[i][j][l]
                                    || (f[i][j][k] && f[i + k][j + k][l - k])
                                    || (f[i][j + l - k][k] && f[i + k][j][l - k]);
        return f[0][0][s1.size()];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isScramble("aa", "aa") << endl;
    return 0;
}
