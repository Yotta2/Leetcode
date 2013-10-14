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
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> hm;
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
            hm[num[i]] = false;
        for (int i = 0; i < num.size(); i++)
            if (hm[num[i]] == false) {
                int count = 1;
                int tmp = num[i] - 1;
                while (hm.find(tmp) != hm.end()) {
                    hm[tmp] = true;
                    tmp--;
                    count++;
                }
                tmp = num[i] + 1;
                while (hm.find(tmp) != hm.end()) {
                    hm[tmp] = true;
                    tmp++;
                    count++;
                }
                if (count > ans)
                    ans = count;
            }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
