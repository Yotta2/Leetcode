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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", 0, 0, n, n * 2, ans);
        return ans;
    }
    void dfs(string soFar, int leftCount, int rightCount, int n, int remaining, vector<string> &ans) {
        if (leftCount < rightCount || leftCount > n || rightCount > n)
            return;
        if (remaining == 0) {
            ans.push_back(soFar);
            return;
        }
        dfs(soFar + "(", leftCount + 1, rightCount, n, remaining - 1, ans);
        dfs(soFar + ")", leftCount, rightCount + 1, n, remaining - 1, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
