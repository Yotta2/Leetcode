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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.empty())
            return ans;
        int count = 0;
        int layer = 0;
        int i = 0;
        int j = 0;
        while (true) {
            while (j < matrix[0].size() - layer) {
                ans.push_back(matrix[i][j]);
                count++;
                if (count == matrix.size() * matrix[0].size())
                    return ans;
                j++;
            }
            i++;
            j--;
            while (i < matrix.size() - layer) {
                ans.push_back(matrix[i][j]);
                count++;
                if (count == matrix.size() * matrix[0].size())
                    return ans;
                i++;
            }
            i--;
            j--;
            while (j >= layer) {
                ans.push_back(matrix[i][j]);
                count++;
                if (count == matrix.size() * matrix[0].size())
                    return ans;
                j--;
            }
            i--;
            j++;
            while (i > layer) {
                ans.push_back(matrix[i][j]);
                count++;
                if (count == matrix.size() * matrix[0].size())
                    return ans;
                i--;
            }
            i++;
            j++;
            layer++;
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
