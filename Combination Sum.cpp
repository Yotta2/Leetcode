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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> soFar;
        dfs(soFar, 0, candidates, 0, target, ans);
        return ans;
    }
private:
    void dfs(vector<int> &soFar, int index, vector<int> &candidates, int currSum, int target, vector<vector<int> > &ans) {
        if (currSum > target)
            return;
        if (currSum == target) {
            ans.push_back(soFar);
            return;
        }
        if (index >= candidates.size())
            return;
        soFar.push_back(candidates[index]);
        dfs(soFar, index, candidates, currSum + candidates[index], target, ans);
        soFar.pop_back();
        dfs(soFar, index + 1, candidates, currSum, target, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

