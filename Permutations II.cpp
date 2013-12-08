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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> perm;
        sort(num.begin(), num.end());
        dfs(perm, num, ans);
        return ans;
    }
private:
    void dfs(vector<int> &soFar, vector<int> &remaining, vector<vector<int> > &ans) {
        if (remaining.empty()) {
            ans.push_back(soFar);
            return;
        }
        for (int i = 0; i < remaining.size(); i++) {
            if (i != 0 && remaining[i - 1] == remaining[i])
                continue;
            soFar.push_back(remaining[i]);
            vector<int> newRemaining = remaining;
            newRemaining.erase(newRemaining.begin() + i);
            dfs(soFar, newRemaining, ans);
            soFar.pop_back();
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
