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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        int count = 0;
        while (true) {
            if (count == m - 1)
                break;
            curr = curr->next;
            count++;
        }
        ListNode *tmp1 = curr;
        ListNode *tmp2 = curr->next;
        ListNode *prev = curr->next;
        curr = curr->next->next;
        count += 2;
        while (true) {
            ListNode *nextTmp = curr->next;
            curr->next = prev;
            if (count == n) {
                tmp1->next = curr;
                tmp2->next = nextTmp;
                break;
            }
            prev = curr;
            curr = nextTmp;
            count++;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = sol.reverseBetween(head, 1, 3);
    while (head != NULL) {
        cout << head->val << " " << endl;
        head = head->next;
    }
    return 0;
}
