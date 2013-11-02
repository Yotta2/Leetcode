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
    int maxPathSum(TreeNode *root) {
        hm.clear();
        DP(root);
        int ans = INT_MIN;
        inorderTraverse(root, ans);
        return ans;
    }
private:
    typedef unordered_map<TreeNode *, int> NodeToMaxPathMap;
    NodeToMaxPathMap hm;
    void DP(TreeNode *root) {
        if (root == NULL) {
            hm[root] = 0;
            return;
        }
        DP(root->left);
        DP(root->right);
        hm[root] = root->val + max(max(hm[root->left], hm[root->right]), 0);
    }
    void inorderTraverse(TreeNode *root, int &ans) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, ans);
        int tmp = root->val;
        if (hm[root->left] > 0)
            tmp += hm[root->left];
        if (hm[root->right] > 0)
            tmp += hm[root->right];
        if (tmp > ans)
            ans = tmp;
        inorderTraverse(root->right, ans);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
