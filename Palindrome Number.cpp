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
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int len = 0;
        int tmp = x;
        while (tmp != 0) {
            tmp /= 10;
            len++;
        }
        len--;
        for (int i = 0; i <= len / 2; i++) {
            int digit0 = x / (int)pow(10, i) % 10;
            int digit1 = x / (int)pow(10, len - i) % 10;
            if (digit0 != digit1)
                return false;
        }
        return true;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
