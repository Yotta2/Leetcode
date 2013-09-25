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

#define EPS 1e-6
#define SIZE 110

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *l1Curr = l1;
        ListNode *l2Curr = l2;
        ListNode *ans;
        ListNode *ansCurr;
        if (l1->val <= l2->val) {
            ans = l1Curr;
            ansCurr = ans;
            l1Curr = l1Curr->next;
        } else {
            ans = l2Curr;
            ansCurr = ans;
            l2Curr = l2Curr->next;
        }
        while (l1Curr != NULL && l2Curr != NULL) {
            if (l1Curr->val <= l2Curr->val) {
                ansCurr->next = l1Curr;
                ansCurr = ansCurr->next;
                l1Curr = l1Curr->next;
            } else {
                ansCurr->next = l2Curr;
                ansCurr = ansCurr->next;
                l2Curr = l2Curr->next;
            }
        }
        if (l1Curr != NULL)
            ansCurr->next = l1Curr;
        else
            ansCurr->next = l2Curr;
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
