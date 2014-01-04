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
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        digits.push_back(0);
        digits[0]++;
        int i = 0;
        while (i < digits.size() && digits[i] >= 10) {
            digits[i + 1] += digits[i] / 10;
            digits[i] -= 10;
            i++;
        }
        if (digits[digits.size() - 1] == 0)
            digits.pop_back();
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
