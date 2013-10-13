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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        inorderTraverse(root, 0, ans);
        for (int i = 1; i < ans.size(); i += 2)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
private:
    void inorderTraverse(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, level + 1, ans);
        if (ans.size() < level + 1)
            ans.resize(level + 1);
        ans[level].push_back(root->val);
        inorderTraverse(root->right, level + 1, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
