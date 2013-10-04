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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        string str;
        if (root != NULL)
            dfs(root, str, sum);
        return sum;
    }
    void dfs(TreeNode *root, string str, int &sum) {
        char ch = '0' + root->val;
        str += ch;
        if (root->left == NULL && root->right == NULL) {
            int num = 0;
            if (!str.empty())
                sscanf(str.c_str(), "%d", &num);
            sum += num;
            return;
        }
        if (root->left != NULL)
            dfs(root->left, str, sum);
        if (root->right != NULL)
            dfs(root->right, str, sum);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
