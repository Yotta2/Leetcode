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
    void flatten(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *curr = dummy;
        preorderTraverse(root, curr);
        delete dummy;
    }
private:
    void preorderTraverse(TreeNode *root, TreeNode* &curr) {
        if (root == NULL)
            return;
        TreeNode *leftRoot = root->left;
        TreeNode *rightRoot = root->right;
        root->left = root->right = NULL;
        curr->right = root;
        curr = root;
        preorderTraverse(leftRoot, curr);
        preorderTraverse(rightRoot, curr);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
