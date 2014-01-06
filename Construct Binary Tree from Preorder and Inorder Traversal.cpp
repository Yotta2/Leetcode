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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *recBuild(vector<int> &preorder, int pStart, int pEnd,
                       vector<int> &inorder, int iStart, int iEnd) {
        if (pStart > pEnd)
            return NULL;
        int rootIndex;
        for (int i = iStart; i <= iEnd; i++)
            if (inorder[i] == preorder[pStart]) {
                rootIndex = i;
                break;
            }
        TreeNode *root = new TreeNode(preorder[pStart]);
        root->left = recBuild(preorder, pStart + 1, pStart + rootIndex - iStart,
                              inorder, iStart, rootIndex - 1);
        root->right = recBuild(preorder, pStart + rootIndex - iStart + 1, pEnd,
                               inorder, rootIndex + 1, iEnd);
        return root;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
