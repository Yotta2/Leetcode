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
    int lengthOfLastWord(const char *s) {
        if (s[0] == '\0')
            return 0;
        int i = 0;
        while (s[i] != '\0')
            i++;
        int len = 0;
        i--;
        while (i >= 0 && s[i] == ' ')
            i--;
        while (true) {
            if (s[i] == ' ' || i < 0)
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
    cout << sol.lengthOfLastWord("a ") << endl;
    return 0;
}
