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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tmp(2, vector<int>(1, 1));
        if (rowIndex == 0)
            return tmp[0];
        for (int i = 1; i <= rowIndex; i++) {
            tmp[i % 2].resize(i + 1);
            for (int j = 0; j < i + 1; j++) {
                if (j != i && j - 1 >= 0)
                    tmp[i % 2][j] = tmp[i % 2 ^ 1][j] + tmp[i % 2 ^ 1][j - 1];
                else if (j == i)
                    tmp[i % 2][j] = tmp[i % 2 ^ 1][j - 1];
                else if (j - 1 < 0)
                    tmp[i % 2][j] = tmp[i % 2 ^ 1][j];
            }
        }
        return tmp[rowIndex % 2];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
