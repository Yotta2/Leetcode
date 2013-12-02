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
    vector<int> searchRange(int A[], int n, int target) {
        int startIndex = bsearch(A, n, target - 0.5);
        int endIndex = bsearch(A, n, target + 0.5) - 1;
        if (endIndex < startIndex) {
            startIndex = -1;
            endIndex = -1;
        }
        vector<int> ans;
        ans.push_back(startIndex);
        ans.push_back(endIndex);
        return ans;
    }
private:
    // using binary search to find a given target in a sorted array,
    // if the target exists in the array, its index will be returned,
    // otherwise, the index of the upper_bound
    // (the first number that is bigger than the given number) will be returned
    int bsearch(int A[], int n, double target) {
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (A[m] == target)
                return m;
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
    cout << sizeof(size_t) <<endl;
    return 0;
}
