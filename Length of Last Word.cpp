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
    int lengthOfLastWord(const char *s) {
        int len = 0;
        int i = strlen(s) - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        while (true) {
            if (i < 0)
                break;
            if (s[i] == ' ')
                break;
            len++;
            i--;
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
