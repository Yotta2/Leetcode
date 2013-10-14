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
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int len = getLen(x);
        int i = 0;
        while (i < len / 2) {
            int right = x / (int)pow(10, i) % 10;
            int left = x / (int)pow(10, len - i - 1) % 10;
            if (right != left)
                return false;
            i++;
        }
        return true;
    }
private:
    int getLen(int x) {
        int len = 0;
        while (x != 0) {
            x /= 10;
            len++;
        }
        return len;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
