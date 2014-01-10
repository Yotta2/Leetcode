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
    bool search(int A[], int n, int target) {
        int pivot = findPivot(A, n);
        int index = bsearch(A, 0, pivot, target);
        if (index == -1)
            index = bsearch(A, pivot + 1, n - 1, target);
        return (index != -1);
    }
private:
    int findPivot(int A[], int n) {
        int i = 0;
        int j = n - 1;
        while (i + 1 < j) {
            int m = (i + j) / 2;
            if (A[m] == A[i]) // can not confirm that i .. m is in ascending order
                i++;
            else if (A[m] > A[i])
                i = m;
            else
                j = m;
        }
        return i;
    }
    int bsearch(int A[], int low, int high, int target) {
        int i = low;
        int j = high;
        while (i <= j) {
            int m = (i + j) / 2;
            if (A[m] == target)
                return m;
            if (A[m] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        return -1;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
