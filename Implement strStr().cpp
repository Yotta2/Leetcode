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
    char *strStr(char *haystack, char *needle) {
        if (*haystack == '\0' && *needle == '\0')
            return haystack;
        for (char *start = haystack; *start != '\0'; start++) {
            char *p0 = start;
            char *p1 = needle;
            while (*p0 != '\0' && *p1 != '\0') {
                if (*p0 != *p1)
                    break;
                p0++;
                p1++;
            }
            if (*p1 == '\0')
                return start;
            if (*p0 == '\0')
                break;
        }
        return NULL;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
