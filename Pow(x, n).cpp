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
    double pow(double x, int n) {
        if (n == 0)
            return 1;
        if (n % 2 == 0) {
            double tmp = pow(x, n / 2);
            return tmp * tmp;
        } else {
            double tmp = pow(x, n / 2);
            if (n > 0)
                return tmp * tmp * x;
            else
                return tmp * tmp / x;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
