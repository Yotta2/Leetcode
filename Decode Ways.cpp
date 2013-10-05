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
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        unordered_map<string, string> numToLetterMap;
        init(numToLetterMap);
        vector<int> f(s.size() + 1, 0);
        f[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == '0') {
                f[i] = 0;
            } else {
                if (i + 2 <= s.size() && numToLetterMap.find(s.substr(i, 2)) != numToLetterMap.end())
                    f[i] = f[i + 1] + f[i + 2];
                else
                    f[i] = f[i + 1];
            }
        return f[0];
    }
private:
    void init(unordered_map<string, string> &numToLetterMap) {
        for (int i = 1; i <= 26; i++) {
            char str[5];
            sprintf(str, "%d", i);
            char ch = 'A' + i - 1;
            numToLetterMap[str] = string() + ch;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.numDecodings("27") << endl;
    return 0;
}

