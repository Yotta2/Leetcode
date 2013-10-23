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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        if (n == 0)
            return matrix;
        int count = 1;
        int i = 0;
        int j = 0;
        int layer = 0;
        while (true) {
            while (j < matrix[0].size() - layer) {
                matrix[i][j] = count;
                count++;
                if (count == matrix.size() * matrix[0].size() + 1)
                    return matrix;
                j++;
            }
            i++;
            j--;
            while (i < matrix.size() - layer) {
                matrix[i][j] = count;
                count++;
                if (count == matrix.size() * matrix[0].size() + 1)
                    return matrix;
                i++;
            }
            i--;
            j--;
            while (j >= layer) {
                matrix[i][j] = count;
                count++;
                if (count == matrix.size() * matrix[0].size() + 1)
                    return matrix;
                j--;
            }
            i--;
            j++;
            while (i > layer) {
                matrix[i][j] = count;
                count++;
                if (count == matrix.size() * matrix[0].size() + 1)
                    return matrix;
                i--;
            }
            i++;
            j++;
            layer++;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
