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
        int i = 1;
        while (true) {
            TreeLinkNode *curr = NULL;
            inorderTraverse(root, 0, i, curr);
            if (curr == NULL)
                break;
            i++;
        }
    }
private:
    void inorderTraverse(TreeLinkNode *root, int level, int mark, TreeLinkNode* &curr) {
        if (root == NULL)
            return;
        if (level == mark + 1)
            return;
        inorderTraverse(root->left, level + 1, mark, curr);
        if (level == mark) {
            if (curr == NULL)
                curr = root;
            else {
                curr->next = root;
                curr = curr->next;
            }
        }
        inorderTraverse(root->right, level + 1, mark, curr);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

