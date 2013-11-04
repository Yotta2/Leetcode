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
    bool isMatch(const char *s, const char *p) {
        return recMatch(string(s), string(p));
    }
private:
    bool recMatch(string s, string p) {
        if (s == p)
            return true;
        if (p.empty())
            return false;
        if (s.empty()) {
            if (p.size() >= 2 && p[p.size() - 1] == '*');
            else
                return false;
        }
        if (p[p.size() - 1] != '*') {
            if (p[p.size() - 1] == '.' || p[p.size() - 1] == s[s.size() - 1]) {
                string sHead = s;
                sHead.resize(sHead.size() - 1);
                string pHead = p;
                pHead.resize(pHead.size() - 1);
                return recMatch(sHead, pHead);
            } else {
                return false;
            }
        } else { // is '*'
            string p0 = p;
            p0.resize(p0.size() - 2);
            string p1 = p;
            p1 += p[p.size() - 2];
            return recMatch(s, p0) || recMatch(s, p1);
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isMatch("", ".*.*.*") << endl;
    return 0;
}
