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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> soFar;
        vector<vector<int> > ans;
        dfs(candidates, 0, soFar, target, ans);
        return ans;
    }
private:
    void dfs(vector<int> &candidates, int i, vector<int> &soFar,
             int remaining, vector<vector<int> > &ans) {
        if (remaining == 0)
            ans.push_back(soFar);
        if (i >= candidates.size() || remaining == 0)
            return;
        int n = remaining / candidates[i];
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < j; k++)
                soFar.push_back(candidates[i]);
            dfs(candidates, i + 1, soFar, remaining - candidates[i] * j, ans);
            for (int k = 0; k < j; k++)
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
