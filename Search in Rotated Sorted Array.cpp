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
    int search(int A[], int n, int target) {
        int pivotIndex = findPivot(A, n);
        int index = bsearch(A, 0, pivotIndex, target);
        if (index == -1)
            index = bsearch(A, pivotIndex + 1, n - 1, target);
        return index;
    }
private:
    int bsearch(int A[], int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    int findPivot(int A[], int n) {
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (A[m] > A[m + 1])
                return m;
            if (A[m] > A[i])
                i = m;
            else
                j = m;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int A[] = {8, 9, 2, 3, 4};
    Solution sol;
    cout << sol.search(A, 5, 9) << endl;
    return 0;
}

