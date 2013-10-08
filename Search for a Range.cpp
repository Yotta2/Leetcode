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
    vector<int> searchRange(int A[], int n, int target) {
        int lower = bsearch(A, n, target - 0.5);
        int upper = bsearch(A, n, target + 0.5) - 1;
        if (lower > upper)
            lower = upper = -1;
        vector<int> ans({lower, upper});
        return ans;
    }
private:
    int bsearch(int A[], int n, double target) {
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (A[m] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        return i;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

