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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l1Curr = l1;
        ListNode *l2Curr = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *ansCurr = dummy;
        int carry = 0;
        while (l1Curr != NULL || l2Curr != NULL) {
            if (l1Curr != NULL && l2Curr != NULL) {
                ansCurr->next = new ListNode((l1Curr->val + l2Curr->val + carry) % 10);
                carry = (l1Curr->val + l2Curr->val + carry) / 10;
                l1Curr = l1Curr->next;
                l2Curr = l2Curr->next;
                ansCurr = ansCurr->next;
            } else if (l1Curr != NULL && l2Curr == NULL) {
                ansCurr->next = new ListNode((l1Curr->val + carry) % 10);
                carry = (l1Curr->val + carry) / 10;
                l1Curr = l1Curr->next;
                ansCurr = ansCurr->next;
            } else if (l1Curr == NULL && l2Curr != NULL) {
                ansCurr->next = new ListNode((l2Curr->val + carry) % 10);
                carry = (l2Curr->val + carry) / 10;
                l2Curr = l2Curr->next;
                ansCurr = ansCurr->next;
            }
        }
        if (carry != 0)
            ansCurr->next = new ListNode(carry);
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
