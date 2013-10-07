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
    void flatten(TreeNode *root) {
        preorderTraverse(root);
    }
private:
    TreeNode *preorderTraverse(TreeNode *root) {  // return a pointer to the last visited treenode
        if (root == NULL)
            return NULL;
        TreeNode *leftLast = preorderTraverse(root->left);
        if (leftLast != NULL) {
            leftLast->right = root->right;
            root->right = root->left;
        }
        TreeNode *rightLast = preorderTraverse(root->right);
        root->left = NULL;
        if (rightLast == NULL) {
            if (leftLast == NULL)
                return root;
            else
                return leftLast;
        } else
            return rightLast;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

