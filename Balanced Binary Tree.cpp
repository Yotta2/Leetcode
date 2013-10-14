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
    bool isBalanced(TreeNode *root) {
         treerootToHeightMap hm;
         hm[NULL] = 0;
         getHeight(root, hm);
         bool balanced = true;
         inorderTraverseCheck(root, hm, balanced);
         return balanced;
    }
private:
    typedef unordered_map<TreeNode *, int> treerootToHeightMap;
    int getHeight(TreeNode *root, treerootToHeightMap &hm) {
        if (root == NULL)
            return 0;
        int leftHeight = getHeight(root->left, hm);
        int rightHeight = getHeight(root->right, hm);
        hm[root] = max(leftHeight, rightHeight) + 1;
        return hm[root];
    }
    void inorderTraverseCheck(TreeNode *root, treerootToHeightMap &hm, bool &balanced) {
        if (root == NULL)
            return;
        inorderTraverseCheck(root->left, hm, balanced);
        if (fabs(hm[root->left] - hm[root->right]) > 1)
            balanced = false;
        inorderTraverseCheck(root->right, hm, balanced);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
