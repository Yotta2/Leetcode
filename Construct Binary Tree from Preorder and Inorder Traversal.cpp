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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return NULL;
        return recBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *recBuild(vector<int> &preorder, int preLow, int preHigh, vector<int> &inorder, int inLow, int inHigh) {
        if (preLow > preHigh)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preLow]);
        int count = 0;
        for (int i = inLow; i <= inHigh; i++)
            if (inorder[i] == preorder[preLow])
                break;
            else
                count++;
        root->left = recBuild(preorder, preLow + 1, preLow + 1 + count - 1, inorder, inLow, inLow + count - 1);
        root->right = recBuild(preorder, preLow + count + 1, preHigh, inorder, inLow + count + 1, inHigh);
        return root;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

