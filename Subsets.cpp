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
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> soFar;
        vector<int> nums = S;
        sort(nums.begin(), nums.end());
        dfs(soFar, 0, nums, ans);
        return ans;
    }
    void dfs(vector<int> soFar, int i, vector<int> nums, vector<vector<int> > &ans) {
        if (i == nums.size()) {
            ans.push_back(soFar);
            return;
        }
        vector<int> newSoFar = soFar;
        dfs(newSoFar, i + 1, nums, ans);
        newSoFar.push_back(nums[i]);
        dfs(newSoFar, i + 1, nums, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}

