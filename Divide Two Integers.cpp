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
    int divide(int dividend, int divisor) {
        int sign = -1;
        if (dividend > 0 && divisor > 0
            || dividend < 0 && divisor < 0)
            sign = 1;
        long double result = pow((long double)2, log2((long double)fabs(dividend)) - log2((long double)fabs(divisor)));
        if (sign == -1)
            return -result;
        else
            return result;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << log(5.5) << endl;
    cout << log(2) << endl;
    cout << sol.divide(5, 2) << endl;
    return 0;
}
