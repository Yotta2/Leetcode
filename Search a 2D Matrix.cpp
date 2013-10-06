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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int low, high, mid;
        low = 0;
        high = matrix.size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        int row = low - 1;
        if (row < 0)
            return false;
        low = 0;
        high = matrix[0].size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

