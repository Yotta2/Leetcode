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
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        int prev0 = 1;
        int prev1 = 0;
        int curr = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0')
                curr = 0;
            else if (i + 2 <= s.size() && ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26))
                curr = prev0 + prev1;
            else
                curr = prev0;
            prev1 = prev0;
            prev0 = curr;
        }
        return curr;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
