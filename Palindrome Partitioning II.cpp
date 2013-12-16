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
    int minCut(string s) {
        vector<int> f(s.size() + 1, INT_MAX);
        vector<vector<int> > p(s.size() + 1, vector<int>(s.size() + 1, -1));
        init(p, s);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (p[i][s.size() - 1] == 1) {
                f[i] = 0;
                continue;
            }
            for (int j = i + 1; j < s.size(); j++) {
                if (p[i][j - 1] == 0)
                    continue;
                f[i] = min(f[j] + 1, f[i]);
            }
        }
        return f[0];
    }
private:
    void init(vector<vector<int> > &p, string &s) {
        for (int i = 0; i < s.size(); i++)
            for (int j = i; j < s.size(); j++)
                recCheck(p, s, i, j);
    }
    void recCheck(vector<vector<int> > &p, string &s, int i, int j) {
        if (i == j) {
            p[i][j] = 1;
            return;
        }
        if (s[i] != s[j]) {
            p[i][j] = 0;
            return;
        } else {
            if (i + 1 == j) {
                p[i][j] = 1;
                return;
            }
            if (p[i + 1][j - 1] == -1)
                recCheck(p, s, i + 1, j - 1);
            p[i][j] = p[i + 1][j - 1];
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
