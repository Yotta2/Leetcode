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
    void reorderList(ListNode *head) {
        if (head == NULL)
            return;
        int len = getLen(head);
        ListNode *secHead = head;
        if (len % 2 == 1) {
            for (int i = 0; i < len / 2 + 1; i++)
                secHead = secHead->next;
        } else {
            for (int i = 0; i < len / 2; i++)
                secHead = secHead->next;
        }
        ListNode *curr = head;
        recReorder(curr, secHead);
        curr = head;
        for (int i = 0; i < len - 1; i++)
            curr = curr->next;
        curr->next = NULL;
    }
private:
    int getLen(ListNode *head) {
        int len = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        return len;
    }
    void recReorder(ListNode* &curr, ListNode *secCurr) {
        if (secCurr == NULL)
            return;
        recReorder(curr, secCurr->next);
        secCurr->next = curr->next;
        curr->next = secCurr;
        curr = secCurr->next;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
