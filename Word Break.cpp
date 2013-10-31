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
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size() + 1, false);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (dict.find(s.substr(i)) != dict.end()) {
                f[i] = true;
                continue;
            }
            for (int j = i; j < s.size(); j++)
                if (dict.find(s.substr(i, j - i + 1)) != dict.end())
                    f[i] = f[i] || f[j + 1];
        }
        return f[0];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
