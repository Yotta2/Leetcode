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
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            int len = 0;
            vector<bool> occurred(26, false);
            while (true) {
                if (j >= s.size() || occurred[s[j] - 'a'] == true)
                    break;
                occurred[s[j] - 'a'] = true;
                len++;
                j++;
            }
            if (len > max)
                max = len;
        }
        return max;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
