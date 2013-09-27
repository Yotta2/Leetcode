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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*haystack == '\0' && *needle == '\0')
            return haystack;
        char *start = haystack;
        while (true) {
            if (*start == '\0')
                return NULL;
            char *p = start;
            char *q = needle;
            while (true) {
                if (*p == '\0' || *q == '\0' || *p != *q)
                    break;
                p++;
                q++;
            }
            if (*q == '\0')
                return start;
            if (*p == '\0')
                break;
            start++;
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
