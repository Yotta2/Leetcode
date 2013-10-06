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

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *oldCurr = dummy;
        ListNode *newHead = new ListNode(0);
        ListNode *newCurr = newHead;
        while (true) {
            if (oldCurr == NULL || oldCurr->next == NULL)
                break;
            if (oldCurr->next->val < x) {
                newCurr->next = oldCurr->next;
                oldCurr->next = oldCurr->next->next;
                newCurr = newCurr->next;
                newCurr->next = NULL;
            } else {
                oldCurr = oldCurr->next;
            }
        }
        newCurr->next = dummy->next;
        delete dummy;
        dummy = newHead;
        newHead = newHead->next;
        delete dummy;
        return newHead;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

