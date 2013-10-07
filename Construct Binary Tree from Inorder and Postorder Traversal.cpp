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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0)
            return NULL;
        return recBuild(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode *recBuild(vector<int> &inorder, int inLow, int inHigh, vector<int> &postorder, int postLow, int postHigh) {
        if (inLow > inHigh)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postHigh]);
        int count = 0;
        for (int i = inLow; i <= inHigh; i++)
            if (inorder[i] == postorder[postHigh])
                break;
            else
                count++;
        root->left = recBuild(inorder, inLow, inLow + count - 1, postorder, postLow, postLow + count - 1);
        root->right = recBuild(inorder, inLow + count + 1, inHigh, postorder, postLow + count, postHigh - 1);
        return root;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

