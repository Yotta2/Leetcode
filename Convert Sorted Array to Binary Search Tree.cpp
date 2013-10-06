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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
    TreeNode *buildBST(vector<int> &num, int low, int high) {
        if (low > high)
            return NULL;
        if (low == high)
            return new TreeNode(num[low]);
        int mid = (low + high) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, low, mid - 1);
        root->right = buildBST(num, mid + 1, high);
        return root;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

