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
    int sqrt(int x) {
        int i = 0;
        int j = x;
        while (i <= j) {
            long long m = (i + j) / 2;
            if (m * m == x)
                return m;
            if (m * m > x)
                j = m - 1;
            else
                i = m + 1;
        }
        return i - 1;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.sqrt(2147395599);
    return 0;
}
