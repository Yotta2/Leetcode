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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        if (n == 0) {
            ans.push_back(NULL);
            return ans;
        }

        return dac(1, n);
    }
private:
    vector<TreeNode *> dac(int i, int j) {
        vector<TreeNode *> trees;
        if (i == j) {
            trees.push_back(new TreeNode(i));
            return trees;
        }
        for (int k = i; k <= j; k++) {
            vector<TreeNode *> leftSubtrees;
            if (k - 1 >= i)
                leftSubtrees = dac(i, k - 1);
            vector<TreeNode *> rightSubtrees;
            if (k + 1 <= j)
                rightSubtrees = dac(k + 1, j);
            conbine(trees, leftSubtrees, rightSubtrees, k);
        }
        return trees;
    }
    void conbine(vector<TreeNode *> &trees,
                 vector<TreeNode *> &leftSubtrees,
                 vector<TreeNode *> &rightSubtrees,
                 int rootVal) {
        if (leftSubtrees.empty())
            leftSubtrees.push_back(NULL);
        if (rightSubtrees.empty())
            rightSubtrees.push_back(NULL);
        for (int i = 0; i < leftSubtrees.size(); i++) {
            for (int j = 0; j < rightSubtrees.size(); j++) {
                TreeNode *root = new TreeNode(rootVal);
                root->left = leftSubtrees[i];
                root->right = rightSubtrees[j];
                trees.push_back(root);
            }
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
