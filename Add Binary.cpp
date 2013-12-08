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
    string addBinary(string a, string b) {
        int maxLen = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < maxLen + 1)
            a += '0';
        while (b.size() < maxLen + 1)
            b += '0';
        int carry = 0;
        for (int i = 0; i < a.size(); i++) {
            a[i] = a[i] + b[i] - '0' + carry;
            carry = (a[i] - '0') / 2;
            a[i] = (a[i] - '0') % 2 + '0';
        }
        if (a[a.size() - 1] == '0')
            a.resize(a.size() - 1);
        reverse(a.begin(), a.end());
        return a;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
