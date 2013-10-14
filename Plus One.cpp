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
    vector<int> plusOne(vector<int> &digits) {
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--)
            if (i == 0 && digits[i] >= 10) {
                digits[i] %= 10;
                digits.insert(digits.begin(), 1);
            } else {
                digits[i - 1] += digits[i] / 10;
                digits[i] %= 10;
            }
        return digits;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
