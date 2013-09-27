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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<bool> rowZeroFlags(matrix.size(), false);
        vector<bool> colZeroFlags(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    rowZeroFlags[i] = true;
                    colZeroFlags[j] = true;
                }
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (rowZeroFlags[i] || colZeroFlags[j])
                    matrix[i][j] = 0;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
