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
    bool isPalindrome(string s) {
        s = preprocess(s);
        int p = 0;
        int q = s.size() - 1;
        while (p <= q) {
            if (s[p] != s[q])
                return false;
            p++;
            q--;
        }
        return true;
    }
private:
    string preprocess(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                res += s[i];
            if (s[i] >= 'A' && s[i] <= 'Z')
                res += s[i] - 'A' + 'a';
            if (s[i] >= '0' && s[i] <= '9')
                res += s[i];
        }
        return res;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
