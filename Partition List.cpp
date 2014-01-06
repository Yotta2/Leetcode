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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *gHead = new ListNode(-1);
        ListNode *curr = dummy;
        ListNode *gCurr = gHead;
        while (curr->next != NULL) {
            if (curr->next->val < x) {
                curr = curr->next;
            } else {
                gCurr->next = curr->next;
                curr->next = curr->next->next;
                gCurr = gCurr->next;
                gCurr->next = NULL;
            }
        }
        ListNode *tmp = gHead;
        gHead = gHead->next;
        delete tmp;
        curr->next = gHead;
        tmp = dummy;
        head = dummy->next;
        delete tmp;
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
