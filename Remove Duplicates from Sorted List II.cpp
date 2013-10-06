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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while (curr != NULL) {
            if (curr->next == NULL || curr->next->next == NULL)
                break;
            if (curr->next->val != curr->next->next->val)
                curr = curr->next;
            else {
                int val = curr->next->val;
                while (true) {
                    if (curr->next == NULL || curr->next->val != val)
                        break;
                    ListNode *p = curr->next;
                    curr->next = curr->next->next;
                    delete p;
                }
            }
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
    head->next = new ListNode(1);
    head = sol.deleteDuplicates(head);
    return 0;
}

