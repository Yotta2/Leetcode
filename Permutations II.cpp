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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        vector<int> perm;
        dfs(perm, num, ans);
        return ans;
    }
private:
    void dfs(vector<int> &perm, vector<int> &remaining, vector<vector<int> > &ans) {
        if (remaining.empty()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < remaining.size(); i++) {
            if (i != 0 && remaining[i] == remaining[i - 1])
                continue;
            vector<int> newRem = remaining;
            newRem.erase(newRem.begin() + i);
            perm.push_back(remaining[i]);
            dfs(perm, newRem, ans);
            perm.pop_back();
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
