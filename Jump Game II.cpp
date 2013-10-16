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
    int jump(int A[], int n) {
        if (n == 1)
            return 0;
        int currFarthest = A[0];
        int nextFarthest = 0;
        int jumpCount = 0;
        for (int i = 0; i < n; i++) {
            if (currFarthest >= n - 1) {
                return jumpCount + 1;
            }
            if (currFarthest >= i) {
                if (nextFarthest < i + A[i])
                    nextFarthest = i + A[i];
            } else {
                currFarthest = nextFarthest;
                jumpCount++;
                if (nextFarthest < i + A[i])
                    nextFarthest = i + A[i];
            }
        }
        return jumpCount + 1;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
