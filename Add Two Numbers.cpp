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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans;
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        if (len1 >= len2) {
            ans = copyList(l1);
            add(ans, l2);
        } else {
            ans = copyList(l2);
            add(ans, l1);
        }
        return ans;
    }
    int getLength(ListNode *list) {
        int len = 0;
        ListNode *curr = list;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        return len;
    }
    void add(ListNode *ans, ListNode *list) {
        ListNode *ansCurr = ans;
        ListNode *lCurr = list;
        int carry = 0;
        while (lCurr != NULL) {
            ansCurr->val += lCurr->val + carry;
            carry = ansCurr->val / 10;
            ansCurr->val %= 10;
            lCurr = lCurr->next;
            if (lCurr == NULL)
                break;
            ansCurr = ansCurr->next;
        }
        dealWithCarry(ansCurr, carry);
    }
    void dealWithCarry(ListNode *curr, int carry) {
        while (true) {
            if (carry == 0)
                break;
            if (curr->next == NULL)
                curr->next = new ListNode(0);
            curr = curr->next;
            curr->val += carry;
            carry = curr->val / 10;
            curr->val %= 10;
        }
    }
    ListNode *copyList(ListNode *src) {
        ListNode *srcCurr = src;
        ListNode *head;
        ListNode *curr;
        if (src == NULL) {
            head = NULL;
            return head;
        } else {
            head = new ListNode(src->val);
            curr = head;
            srcCurr = src->next;
        }
        while (true) {
            if (srcCurr == NULL)
                break;
            curr->next = new ListNode(srcCurr->val);
            curr = curr->next;
            srcCurr = srcCurr->next;
        }
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
