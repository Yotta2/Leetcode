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
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m + n;
        if (sum % 2 == 0) {
            return (findKthSmallest(A, m, B, n, sum / 2)
                    + findKthSmallest(A, m, B, n, sum / 2 + 1)) / 2.0;
        }
        else
            return findKthSmallest(A, m, B, n, sum / 2 + 1);

    }
private:
    int findKthSmallest(int A[], int m, int B[], int n, int k) {
        //always assume that m is equal or smaller than n
        if (m > n)
            return findKthSmallest(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (n == 0)
            return A[k - 1];
        if (k == 1)
            return min(A[0], B[0]);
        int indexA = min(m, k / 2) - 1;
        int indexB = k - min(m, k / 2) - 1;
        if (A[indexA] == B[indexB])
            return A[indexA];
        else if (A[indexA] < B[indexB])
            return findKthSmallest(A + indexA + 1, m - indexA - 1, B, n, k - indexA - 1);
        else
            return findKthSmallest(A, m, B + indexB + 1, n - indexB - 1, k - indexB - 1);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    int A[] = {2, 3, 4};
    int B[] = {1};
    cout << sol.findMedianSortedArrays(A, 3, B, 1);
    return 0;
}
