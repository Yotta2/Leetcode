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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = findRow(matrix, target);
        if (row >= 0 && row < matrix.size())
            return bsearch(matrix[row], target);
        return false;
    }
private:
    int findRow(vector<vector<int> > &matrix, int target) {
        int i = 0;
        int j = matrix.size() - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (matrix[m][0] == target)
                return m;
            else if (matrix[m][0] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        return i - 1;
    }
    bool bsearch(vector<int> &nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return true;
            else if (nums[m] < target)
                i = m + 1;
            else
                j = m - 1;
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
