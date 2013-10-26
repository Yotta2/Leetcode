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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        vector<int> sol;
        dfs(num, 0, target, sol, ans);
        return ans;
    }
private:
    void dfs(vector<int> &num, int index, int target, vector<int> &sol, vector<vector<int> > &ans) {
        if (target < 0)
            return;
        if (index == num.size()) {
            if (target == 0)
                ans.push_back(sol);
            return;
        }
        int count = 1;
        int tmp = num[index];
        index++;
        while (true) {
            if (index >= num.size())
                break;
            if (num[index] != num[index - 1])
                break;
            count++;
            index++;
        }
        for (int i = 0; i <= count; i++) {
            for (int j = 1; j <= i; j++)
                sol.push_back(tmp);
            dfs(num, index, target - tmp * i, sol, ans);
            for (int j = 1; j <= i; j++)
                sol.pop_back();
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
