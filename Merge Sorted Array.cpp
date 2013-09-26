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
    void merge(int A[], int m, int B[], int n) {
        int i, j, k;
        i = m - 1;
        j = n - 1;
        k = m + n - 1;
        while (true) {
            if (i < 0 || j < 0)
                break;
            if (A[i] >= B[j]) {
                A[k] = A[i];
                k--;
                i--;
            } else {
                A[k] = B[j];
                k--;
                j--;
            }
        }
        while (true) {
            if (j < 0)
                break;
            A[k] = B[j];
            k--;
            j--;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
