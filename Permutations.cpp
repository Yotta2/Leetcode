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
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> soFar;
        dfs(soFar, num, ans);
        return ans;
    }
    void dfs(vector<int> soFar, vector<int> remaining, vector<vector<int> > &ans) {
        if (remaining.empty()) {
            ans.push_back(soFar);
            return;
        }
        for (int i = 0; i < remaining.size(); i++) {
            vector<int> newRe = remaining;
            vector<int> newSoFar = soFar;
            newRe.erase(newRe.begin() + i);
            newSoFar.push_back(remaining[i]);
            dfs(newSoFar, newRe, ans);
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
