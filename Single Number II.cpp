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
    int singleNumber(int A[], int n) {
        vector<int> occurs(32, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 32; j++) {
                if (A[i] & (1 << j))
                    occurs[j]++;
            }
        int num = 0;
        for (int i = 0; i < 32; i++)
            if (occurs[i] % 3 != 0)
                num |= 1 << i;
        return num;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
