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
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        int level = 0;
        while (true) {
            TreeLinkNode *curr = NULL;
            preorderTraverse(root, level, 0, curr);
            if (curr == NULL)
                break;
            level++;
        }
    }
private:
    void preorderTraverse(TreeLinkNode *root, int level, int currLevel, TreeLinkNode* &curr) {
        if (root == NULL)
            return;
        if (currLevel == level) {
            if (curr == NULL) {
                curr = root;
            } else {
                curr->next = root;
                curr = curr->next;
            }
        }
        preorderTraverse(root->left, level, currLevel + 1, curr);
        preorderTraverse(root->right, level, currLevel + 1, curr);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
