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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<int> soFar;
        dfs(soFar, nums, k, ans);
        return ans;
    }
    void dfs(vector<int> soFar, vector<int> remaining, int k, vector<vector<int> > &ans) {
        if (soFar.size() == k) {
            ans.push_back(soFar);
            return;
        }
        for (int i = 0; i < remaining.size(); i++) {
            vector<int> newSoFar = soFar;
            vector<int> newRem = remaining;
            newSoFar.push_back(remaining[i]);
            newRem.erase(newRem.begin(), newRem.begin() + i + 1);
            dfs(newSoFar, newRem, k, ans);
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}

