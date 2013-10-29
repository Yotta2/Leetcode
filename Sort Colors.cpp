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
    void sortColors(int A[], int n) {
        int i = -1;
        int j = -1;
        for (int k = 0; k < n; k++)
            if (A[k] == 1) {
                swap(A[j + 1], A[k]);
                j++;
            } else if (A[k] == 0) {
                swap(A[j + 1], A[k]);
                swap(A[i + 1], A[j + 1]);
                i++;
                j++;
            }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
