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
    int minDistance(string word1, string word2) {
        vector<vector<int> > f(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = word1.size(); i >= 0; i--)
            for (int j = word2.size(); j >= 0; j--) {
                if (i == word1.size())
                    f[i][j] = word2.size() - j;
                else if (j == word2.size())
                    f[i][j] = word1.size() - i;
                else if (word1[i] == word2[j])
                    f[i][j] = f[i + 1][j + 1];
                else
                    f[i][j] = min(f[i][j + 1] + 1, min(f[i + 1][j] + 1, f[i + 1][j + 1] + 1));
            }

        return f[0][0];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.minDistance("abe", "fgh") << endl;
    cout << sol.minDistance("abe", "z") << endl;
    cout << sol.minDistance("", "abe") << endl;
    cout << sol.minDistance("a", "a") << endl;
    return 0;
}
