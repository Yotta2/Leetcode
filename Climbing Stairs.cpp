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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int f[SIZE];
        memset(f, 0, sizeof(f));
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
