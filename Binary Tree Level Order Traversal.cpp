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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        inorderTraverse(root, 0, ans);
        return ans;
    }
    void inorderTraverse(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, level + 1, ans);
        if (level >= ans.size())
            ans.resize(level + 1, vector<int>());
        ans[level].push_back(root->val);
        inorderTraverse(root->right, level + 1, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}

