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
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        if (a == 0)
            return 0;
        if (b == 1)
            return a;
        if (b == 2)
            return a >> 1;
        bool sign;
        if (a > 0 && b < 0 || a < 0 && b > 0)
            sign = false; // negative
        else
            sign = true;
        a = fabs(a);
        b = fabs(b);
        long long ans = pow(2, log2((double)a) - log2((double)b));
        if (sign)
            return ans;
        else
            return -ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.divide(2147483647, 1) << endl;
    return 0;
}

