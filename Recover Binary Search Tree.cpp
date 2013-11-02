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
    void recoverTree(TreeNode *root) {
        TreeNode *prevPointer = root;
        int prevVal = INT_MIN;
        foundFirst = false;
        inorderTraverse(root, prevVal, prevPointer);
        swap(first->val, second->val);
    }
private:
    bool foundFirst;
    TreeNode *first;
    TreeNode *second;
    void inorderTraverse(TreeNode *root, int &prevVal, TreeNode * &prevPointer) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, prevVal, prevPointer);
        if (root->val < prevVal) {
            if (foundFirst == false) {
                first = prevPointer;
                second = root;
                foundFirst = true;
            } else {
                second = root;
            }
        }
        prevVal = root->val;
        prevPointer = root;
        inorderTraverse(root->right, prevVal, prevPointer);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
