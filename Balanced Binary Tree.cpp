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
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        getHeight(root, flag);
        return flag;
    }
private:
    int getHeight(TreeNode *root, bool &flag) {
        if (root == NULL)
            return 0;
        int leftTreeHeight = getHeight(root->left, flag);
        int rightTreeHeight = getHeight(root->right, flag);
        if (abs(leftTreeHeight - rightTreeHeight) > 1)
            flag = false;
        return max(leftTreeHeight, rightTreeHeight) + 1;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
