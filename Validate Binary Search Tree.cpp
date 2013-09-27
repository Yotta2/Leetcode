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
    bool isValidBST(TreeNode *root) {
        bool flag = true;
        int prevVal = INT_MIN;
        inorderTraverse(root, prevVal, flag);
        return flag;
    }

    void inorderTraverse(TreeNode *root, int &prevVal, bool &flag) {
        if (root == NULL)
            return;
        if (flag == false)
            return;
        inorderTraverse(root->left, prevVal, flag);
        if (root->val <= prevVal) {
            flag = false;
            return;
        } else {
            prevVal = root->val;
        }
        inorderTraverse(root->right, prevVal, flag);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
