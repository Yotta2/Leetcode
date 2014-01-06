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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return recBuild(inorder, 0, inorder.size() - 1,
                        postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode *recBuild(vector<int> &inorder, int iStart, int iEnd,
                       vector<int> &postorder, int pStart, int pEnd) {
        if (iStart > iEnd)
            return NULL;
        int rootIndex;
        for (int i = iStart; i <= iEnd; i++)
            if (inorder[i] == postorder[pEnd]) {
                rootIndex = i;
                break;
            }
        TreeNode *root = new TreeNode(postorder[pEnd]);
        root->left = recBuild(inorder, iStart, rootIndex - 1,
                              postorder, pStart, pStart + rootIndex - iStart - 1);
        root->right = recBuild(inorder, rootIndex + 1, iEnd,
                               postorder, pStart + rootIndex - iStart, pEnd - 1);
        return root;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
