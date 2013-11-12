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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> s;
        if (root != NULL)
            s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->left == NULL && node->right == NULL) {
                ans.push_back(node->val);
            } else {
                TreeNode *tmpNode = new TreeNode(node->val);
                s.push(tmpNode);
                if (node->right != NULL)
                    s.push(node->right);
                if (node->left != NULL)
                    s.push(node->left);
            }
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
