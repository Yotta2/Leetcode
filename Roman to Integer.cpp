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
    int romanToInt(string s) {
        numeralToValueHM hm;
        init(hm);
        int i = 0;
        int intValue = 0;
        while (i < s.size()) {
            if (i != s.size() - 1 && hm[s[i]] < hm[s[i + 1]]) {
                intValue += hm[s[i + 1]] - hm[s[i]];
                i++;
            } else {
                intValue += hm[s[i]];
            }
            i++;
        }
        return intValue;
    }
private:
    typedef unordered_map<char, int> numeralToValueHM;
    void init(numeralToValueHM &hm) {
        hm['I'] = 1;
        hm['V'] = 5;
        hm['X'] = 10;
        hm['L'] = 50;
        hm['C'] = 100;
        hm['D'] = 500;
        hm['M'] = 1000;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
