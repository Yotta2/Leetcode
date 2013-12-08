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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", n, 0, 0, ans);
        return ans;
    }
private:
    void dfs(string soFar, int n, int leftCount, int rightCount, vector<string> &ans) {
        if (leftCount == n && rightCount == n) {
            ans.push_back(soFar);
            return;
        }
        if (leftCount + 1 >= rightCount && leftCount + 1 <= n)
            dfs(soFar + '(', n, leftCount + 1, rightCount, ans);
        if (rightCount + 1 <= leftCount && rightCount + 1 <= n)
            dfs(soFar + ')', n, leftCount, rightCount + 1, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
