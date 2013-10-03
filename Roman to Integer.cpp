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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    void init(unordered_map<char, int> &letterToValueMap) {
        letterToValueMap['I'] = 1;
        letterToValueMap['V'] = 5;
        letterToValueMap['X'] = 10;
        letterToValueMap['L'] = 50;
        letterToValueMap['C'] = 100;
        letterToValueMap['D'] = 500;
        letterToValueMap['M'] = 1000;
    }
    int romanToInt(string s) {
        unordered_map<char, int> letterToValueMap;
        init(letterToValueMap);
        int ans = 0;
        int i = 0;
        while (i < s.size()) {
            int currValue = letterToValueMap[s[i]];
            if (i != s.size() - 1) {
                int nextValue = letterToValueMap[s[i + 1]];
                if (currValue >= nextValue)
                    ans += currValue;
                else {
                    ans += nextValue - currValue;
                    i++;
                }
            } else {
                ans += currValue;
            }
            i++;
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
