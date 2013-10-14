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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        int len = getLen(head);
        if (head == NULL)
            return NULL;
        if (len == 1)
            return new TreeNode(head->val);
        int count = 0;
        ListNode *curr = head;
        while (count < len / 2 - 1) {
            curr = curr->next;
            count++;
        }
        TreeNode *root = new TreeNode(curr->next->val);
        ListNode *rightHead = curr->next->next;
        curr->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(rightHead);
        return root;
    }
private:
    int getLen(ListNode *head) {
        ListNode *curr = head;
        int len = 0;
        while (curr != NULL) {
            curr = curr->next;
            len++;
        }
        return len;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
