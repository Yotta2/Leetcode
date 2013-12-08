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
    int sumNumbers(TreeNode *root) {
        int val = 0;
        int sum = 0;
        if (root == NULL)
            return sum;
        dfs(root, val, sum);
        return sum;
    }
private:
    void dfs(TreeNode *root, int val, int &sum) {
        val = val * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += val;
            return;
        }
        if (root->left != NULL)
            dfs(root->left, val, sum);
        if (root->right != NULL)
            dfs(root->right, val, sum);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
