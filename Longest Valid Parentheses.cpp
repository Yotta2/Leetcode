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
    int longestValidParentheses(string s) {
        vector<int> f(s.size() + 1, 0);
        int maxLen = 0;
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == '(') {
                int j = i + 1 + f[i + 1];
                if (s[j] == ')') {
                    f[i] = f[i + 1] + 2;
                    if (j + 1 < s.size())
                        f[i] += f[j + 1];
                }
                maxLen = max(maxLen, f[i]);
            }
        return maxLen;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.longestValidParentheses("(()") << endl;
    return 0;
}
