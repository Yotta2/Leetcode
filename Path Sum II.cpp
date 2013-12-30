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

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> soFar;
        vector<vector<int> > ans;
        if (root == NULL)
            return ans;
        dfs(root, sum, soFar, ans);
        return ans;
    }
private:
    void dfs(TreeNode *root, int remaining,
             vector<int> &soFar, vector<vector<int> > &ans) {
        if (root == NULL)
            return;
        soFar.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (remaining - root->val == 0)
                ans.push_back(soFar);
        }
        dfs(root->left, remaining - root->val, soFar, ans);
        dfs(root->right, remaining - root->val, soFar, ans);
        soFar.pop_back();
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
